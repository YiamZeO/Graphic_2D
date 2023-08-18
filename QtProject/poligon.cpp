#include "poligon.h"
#include <QThread>

QList<QPointF> *Poligon::getPoligonPoints()
{
    return &poligonPoints;
}

bool *Poligon::getRotatingFlag()
{
    return &isRotatingPoligon;
}

QMutex *Poligon::getMutex()
{
    return &mutexPoligon;
}

double *Poligon::getRotateNumber()
{
    return &rotateNumber;
}

void Poligon::paintPoligon(QPainter *painter)
{
    if(!poligonPoints.empty())
    {
        if(poligonPoints.size() > 2)
        {
            painter->setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::SquareCap));
            painter->drawPolygon(poligonPoints);
        }
        painter->setPen(QPen(Qt::black, 0, Qt::SolidLine, Qt::SquareCap));
        painter->setBrush(QBrush(Qt::white, Qt::SolidPattern));
        for(QPointF p : poligonPoints)
            painter->drawRect(p.x()-3, p.y()-3, 7, 7);
    }
}

void Poligon::rotatePoligon()
{
    while(isRotatingPoligon)
    {
        mutexPoligon.lock();
        QPointF center(0, 0);
        for(QPointF p : poligonPoints)
        {
            center.setX(center.x()+p.x());
            center.setY(center.y()+p.y());
        }
        center.setX(center.x()/poligonPoints.size());
        center.setY(center.y()/poligonPoints.size());
        for(auto i = poligonPoints.begin(); i != poligonPoints.end(); i++)
        {
            double pointX = (i->x()-center.x())*qCos(rotateNumber)-(i->y()-center.y())*qSin(rotateNumber)+center.x();
            double pointY = (i->x()-center.x())*qSin(rotateNumber)+(i->y()-center.y())*qCos(rotateNumber)+center.y();
            i->setX(pointX);
            i->setY(pointY);
        }
        mutexPoligon.unlock();
        QThread::msleep(10);
    }
}
