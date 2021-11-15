#ifndef PLAYER_H
#define PLAYER_H
#include<QGraphicsPixmapItem>
#include<QKeyEvent>
#include<QGraphicsScene>
#include<QList>
#include "food.h"
class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT;
private:
    int row, column;
    int data[13][13];
public:

    Player(int boarddata[13][13]);
public slots:
    void keyPressEvent(QKeyEvent*event);// function internelly include that someone clicked on the keyboard

};

#endif // PLAYER_H
