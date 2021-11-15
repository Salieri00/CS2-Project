#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QDir>
#include <QFile>
#include "player.h"
#include "tom.h"
#include<QDebug>
#include<stdlib.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsView view;
    QGraphicsScene scene;
    view.setFixedSize(700,700);
    view.setWindowTitle("Maze Game");


    QBrush brush (Qt::black);
    view.setBackgroundBrush(brush);
    int boarddata[13][13];
    QFile file ("Board.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream stream (&file);
    QString temp;
    for ( int i=0; i<13;i++)
    {
        for ( int j=0; j<13;j++)
        {
           // stream>>boarddata[i][j]; this might make an error
            stream>>temp; // we are going to recieve the data in the text file as string and then convert it to integar
            boarddata[i][j]=temp.toInt();
        }
     }
    // drawing the board

    QPixmap bricksimage("mario.png");
    bricksimage =bricksimage.scaledToWidth(50);
    bricksimage =bricksimage.scaledToHeight(50);
    QPixmap grassimage("white-brick.png");
    grassimage =grassimage.scaledToWidth(50);
    grassimage =grassimage.scaledToHeight(50);
    QGraphicsPixmapItem boarditems[13][13];
    for ( int i=0; i<13;i++)
    {
        for ( int j=0; j<13;j++)
        {
            // set image
            if (boarddata[i][j]<0)
            {
                boarditems[i][j].setPixmap(bricksimage);
            }
            else
            {
                boarditems[i][j].setPixmap(grassimage);
            }
         // set position
        boarditems[i][j].setPos(50+(50*j),50+(50*i));//j-> x axis    i-> y axis
        // add to the scene
        scene.addItem(& boarditems[i][j]);
        }
    }
   // qDebug()<<"here";
     Player player(boarddata);
     scene.addItem(& player);

    Tom tom(boarddata);
    scene.addItem(& tom);

     food food1,food2,food3, food4;
     food1.setPos(50 + 1 * 50, 50 + 7 * 50);
     scene.addItem(&food1);

     food2.setPos(50 + 1 * 50, 50 + 1 * 50);
     scene.addItem(&food2);

     food3.setPos(50 + 11 * 50, 50 + 7 * 50);
     scene.addItem(&food3);

     food4.setPos(50 + 11 * 50, 50 + 9 * 50);
     scene.addItem(&food4);

     player.setFlag(QGraphicsPixmapItem::ItemIsFocusable);
     player.setFocus();


     //tom.setFlag(QGraphicsPixmapItem::ItemIsFocusable);
    //tom.setFocus();
     view.setScene(& scene);
     tom.movingTom();

     view.show();
    return a.exec();
}
