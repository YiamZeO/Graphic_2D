#ifndef POLIGON_H
#define POLIGON_H

#include <QPoint>
#include <QList>
#include <QMutex>
#include <QtMath>
#include <QPainter>
#include <QObject>

class Poligon : public QObject
{
    Q_OBJECT
public:
    Poligon() = default;
    ~Poligon() = default;
public slots:
    QList<QPointF>* getPoligonPoints();
    bool *getRotatingFlag();
    QMutex *getMutex();
    double *getRotateNumber();
    void paintPoligon(QPainter *painter);
    void rotatePoligon();
protected:
    QList<QPointF> poligonPoints;
    bool isRotatingPoligon = false;
    QMutex mutexPoligon;
    double rotateNumber = qDegreesToRadians(1);
};

#endif // POLIGON_H
