#ifndef MOVINGPOLIGON_H
#define MOVINGPOLIGON_H

#include "poligon.h"

class MovingPoligon : public Poligon
{
public:
    MovingPoligon() = default;
    ~MovingPoligon() = default;
public slots:
    bool *getPaintFlag();
    bool *getMoveFlag();
    double *getMoveNumber();
    void paintPoligon(QPainter *painter);
    void movePoligon(QList<QPointF> *path, QMutex *mutexPath);
protected:
    bool isPaintPoligon = false, isMovePoligon = false;
    double movePoligonNumber = 10;
};

#endif // MOVINGPOLIGON_H
