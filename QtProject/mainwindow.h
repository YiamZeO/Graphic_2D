#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QPoint>
#include <QList>
#include <QMouseEvent>
#include <QtMath>
#include <QTimer>
#include <QMutex>
#include <QThread>
#include <poligon.h>
#include <movingpoligon.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent *event);

private slots:
    void clearButton();
    void rotatePolButton();
    void paintMPolButton();
    void rotateMPolButton();
    void moveMPolButton();
    void sliderPolRotatingSp();
    void sliderSqMovingSp();
    void sliderSqRotatingSp();

private:
    Ui::MainWindow *ui;
    Poligon poligon;
    MovingPoligon mPoligon;
    QList<QPointF> checkPoints;
    bool isTargetPoint = false;
    QPointF *targetPoint;
    QTimer upTimer;
    QThread *poligonRotateTh = nullptr, *mPoligonRotateTh = nullptr, *mPoligonMoveTh = nullptr;
    void mousePressEvent(QMouseEvent *mouse);
    void mouseMoveEvent(QMouseEvent *mouse);
    void mouseReleaseEvent(QMouseEvent *mouse);
    void paintCheckP(QPainter *painter);
    bool nonZeroWindingRule(QPointF point);
};
#endif // MAINWINDOW_H
