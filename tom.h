
#ifndef TOM_H
#define TOM_H
#include<QGraphicsPixmapItem>
#include<QKeyEvent>
#include<QGraphicsScene>
#include<QList>


class Tom : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT;
public:

    Tom(int boarddata[13][13]);
    void movingTom ();

private:
    int row, column;
    int data[13][13];

};

#endif // TOM_H

