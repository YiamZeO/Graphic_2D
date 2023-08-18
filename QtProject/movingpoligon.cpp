#include "movingpoligon.h"
#include <QThread>

bool *MovingPoligon::getPaintFlag()
{
    return &isPaintPoligon;
}

bool *MovingPoligon::getMoveFlag()
{
    return &isMovePoligon;
}

double *MovingPoligon::getMoveNumber()
{
    return &movePoligonNumber;
}

void MovingPoligon::paintPoligon(QPainter *painter)
{
    painter->setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::SquareCap));
    painter->setBrush(QBrush(Qt::yellow, Qt::SolidPattern));
    painter->drawPolygon(poligonPoints);
}

void MovingPoligon::movePoligon(QList<QPointF> *path, QMutex *mutexPath)
{
    while(isMovePoligon)
    {
        int firstP = path->size()-1;
        for(int i = 0; i < path->size() && isMovePoligon; i++)
        {
            int secondP = i;
            mutexPath->lock();
            double d = qSqrt(qPow(((*path)[secondP].x()-(*path)[firstP].x()), 2)+qPow(((*path)[secondP].y()-(*path)[firstP].y()), 2));
            mutexPath->unlock();
            for(double t = 0; t < 1 && d > 1 && isMovePoligon; t += 1*movePoligonNumber/d)
            {
                mutexPath->lock();
                QPointF newP(0, 0);
                newP.setX((*path)[firstP].x()*(1-t)+(*path)[secondP].x()*t);
                newP.setY((*path)[firstP].y()*(1-t)+(*path)[secondP].y()*t);
                mutexPath->unlock();
                mutexPoligon.lock();
                QPointF center(0, 0);
                for(QPointF p : poligonPoints)
                {
                    center.setX(center.x()+p.x());
                    center.setY(center.y()+p.y());
                }
                center.setX(center.x()/poligonPoints.size());
                center.setY(center.y()/poligonPoints.size());
                for(auto it = poligonPoints.begin(); it != poligonPoints.end(); it++)
                {
                    it->setX((it->x()-center.x())+newP.x());
                    it->setY((it->y()-center.y())+newP.y());
                }
                mutexPoligon.unlock();
                QThread::msleep(10);
            }
            firstP = secondP;
        }
    }
}
