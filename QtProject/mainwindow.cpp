#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QThread>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setMouseTracking(true);
    centralWidget()->setMouseTracking(true);
    connect(&upTimer, SIGNAL(timeout()), this, SLOT(update()));
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(clearButton()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(rotatePolButton()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(paintMPolButton()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(rotateMPolButton()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(moveMPolButton()));
    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), SLOT(sliderPolRotatingSp()));
    connect(ui->horizontalSlider_2, SIGNAL(valueChanged(int)), SLOT(sliderSqMovingSp()));
    connect(ui->horizontalSlider_3, SIGNAL(valueChanged(int)), SLOT(sliderSqRotatingSp()));
    upTimer.start(10);
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    const QRect & rect = event->rect();
    QPainter painter(this);
    painter.eraseRect(rect);
    poligon.getMutex()->lock();
    poligon.paintPoligon(&painter);
    paintCheckP(&painter);
    poligon.getMutex()->unlock();
    if(*mPoligon.getPaintFlag())
    {
        mPoligon.getMutex()->lock();
        mPoligon.paintPoligon(&painter);
        mPoligon.getMutex()->unlock();
    }
}

void MainWindow::clearButton()
{
    if(*mPoligon.getMoveFlag())
        moveMPolButton();
    if(*mPoligon.getRotatingFlag())
        rotateMPolButton();
    if(*poligon.getRotatingFlag())
        rotatePolButton();
    poligon.getPoligonPoints()->clear();
    checkPoints.clear();
    *mPoligon.getPaintFlag() = false;
    mPoligon.getPoligonPoints()->clear();
}

void MainWindow::rotatePolButton()
{
    if(poligon.getPoligonPoints()->size() > 2)
    {
        if(!*poligon.getRotatingFlag())
        {
            *poligon.getRotatingFlag() = true;
            poligonRotateTh = QThread::create(std::bind(&Poligon::rotatePoligon, &poligon));
            poligonRotateTh->start();
        }
        else
        {
            *poligon.getRotatingFlag() = false;
            poligonRotateTh->wait();
            poligonRotateTh->deleteLater();
            poligonRotateTh = nullptr;
        }
    }
}

void MainWindow::paintMPolButton()
{
    if(!*mPoligon.getPaintFlag())
    {
        mPoligon.getPoligonPoints()->push_back(QPoint(750-20, 250-20));
        mPoligon.getPoligonPoints()->push_back(QPoint(750-20, 250+20));
        mPoligon.getPoligonPoints()->push_back(QPoint(750+20, 250+20));
        mPoligon.getPoligonPoints()->push_back(QPoint(750+20, 250-20));
        *mPoligon.getPaintFlag() = true;
    }
}

void MainWindow::rotateMPolButton()
{
    if(*mPoligon.getPaintFlag())
    {
        if(!*mPoligon.getRotatingFlag())
        {
            *mPoligon.getRotatingFlag() = true;
            mPoligonRotateTh = QThread::create(std::bind(&MovingPoligon::rotatePoligon, &mPoligon));
            mPoligonRotateTh->start();
        }
        else
        {
            *mPoligon.getRotatingFlag() = false;
            mPoligonRotateTh->wait();
            mPoligonRotateTh->deleteLater();
            mPoligonRotateTh = nullptr;
        }
    }
}

void MainWindow::moveMPolButton()
{
    if(poligon.getPoligonPoints()->size()>2 && *mPoligon.getPaintFlag())
    {
        if(!*mPoligon.getMoveFlag())
        {
            *mPoligon.getMoveFlag() = true;
            mPoligonMoveTh = QThread::create(std::bind(&MovingPoligon::movePoligon, &mPoligon, poligon.getPoligonPoints(), poligon.getMutex()));
            mPoligonMoveTh->start();
        }
        else
        {
            *mPoligon.getMoveFlag() = false;
            mPoligonMoveTh->wait();
            mPoligonMoveTh->deleteLater();
            mPoligonMoveTh = nullptr;
        }
    }
}

void MainWindow::sliderPolRotatingSp()
{
    *poligon.getRotateNumber() = qDegreesToRadians(1+0.9*ui->horizontalSlider->value());
}

void MainWindow::sliderSqMovingSp()
{
    if(ui->horizontalSlider_2->value() >= 0 && ui->horizontalSlider_2->value() <= 10)
        *mPoligon.getMoveNumber() = 10+9*ui->horizontalSlider_2->value();
    else
        *mPoligon.getMoveNumber() = 10-0.9*(-ui->horizontalSlider_2->value());
}

void MainWindow::sliderSqRotatingSp()
{
    *mPoligon.getRotateNumber() = qDegreesToRadians(1+0.9*ui->horizontalSlider_3->value());
}

void MainWindow::mousePressEvent(QMouseEvent *mouse)
{
    if(!*poligon.getRotatingFlag() && !*mPoligon.getMoveFlag())
    {
        if(mouse->button() == Qt::LeftButton)
        {
            poligon.getPoligonPoints()->push_back(QPointF(mouse->pos()));
        }
        else if(mouse->button() == Qt::RightButton && !poligon.getPoligonPoints()->empty())
        {
            for(auto i = poligon.getPoligonPoints()->begin(); i != poligon.getPoligonPoints()->end(); i++)
                if(qFabs(i->x()-mouse->pos().x()) <= 4 && qFabs(i->y()-mouse->pos().y()) <= 4)
                {
                    targetPoint = &(*i);
                    isTargetPoint = true;
                    break;
                }
        }
        else if(mouse->button() == Qt::MiddleButton)
        {
            checkPoints.push_back(QPointF(mouse->pos()));
        }
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *mouse)
{
    if(!*poligon.getRotatingFlag() && !*mPoligon.getMoveFlag())
    {
        if(isTargetPoint)
        {
            targetPoint->setX(mouse->pos().x());
            targetPoint->setY(mouse->pos().y());
        }
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *mouse)
{
    if(mouse->button() == Qt::RightButton)
    {
        isTargetPoint = false;
        targetPoint = nullptr;
    }
}

void MainWindow::paintCheckP(QPainter *painter)
{
    if(!checkPoints.empty())
    {
        painter->setPen(QPen(Qt::black, 0, Qt::SolidLine, Qt::SquareCap));
        for(QPointF p : checkPoints){
            if(poligon.getPoligonPoints()->size()>2 && nonZeroWindingRule(p))
                painter->setBrush(QBrush(Qt::green, Qt::SolidPattern));
            else
                painter->setBrush(QBrush(Qt::red, Qt::SolidPattern));
            painter->drawRect(p.x()-3, p.y()-3, 7, 7);
        }
    }
}

bool MainWindow::nonZeroWindingRule(QPointF point)
{
    auto j = *poligon.getPoligonPoints()->rbegin();
    int result = 0;
    for(auto i : *poligon.getPoligonPoints()){
        if(point.x() == i.x() && point.y() == i.y())
            return true;
        if((point.y()<i.y()) != (point.y()<j.y()))
        {
            int slope = (point.x()-i.x())*(j.y()-i.y())-(j.x()-i.x())*(point.y()-i.y());
            if(slope == 0)
                return true;
            if((slope<0) != (j.y()<i.y())){
                if(j.y()<i.y())
                    result += 1;
                else
                    result -= 1;
            }
        }
        j = i;
    }
    return (result != 0);
}

MainWindow::~MainWindow()
{
    if(poligonRotateTh)
    {
        poligonRotateTh->terminate();
        poligonRotateTh->wait();
    }
    if(mPoligonRotateTh)
    {
        mPoligonRotateTh->terminate();
        mPoligonRotateTh->wait();
    }
    if(mPoligonMoveTh)
    {
        mPoligonMoveTh->terminate();
        mPoligonMoveTh->wait();
    }
    delete ui;
}

