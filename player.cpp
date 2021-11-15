#include "player.h"

Player::Player(int boarddata[13][13])
{
// set image
    QPixmap image ("4.png");
    image =image.scaledToWidth(50);
    image =image.scaledToHeight(50);
    setPixmap(image);
 // set position

//add to the scene but not in the constructor, in the main
// initializing the array
 row=6;
 column=6;
  setPos(50+(50*column),50+(50*row));
 for ( int i=0; i<13; i++)
 {
     for ( int j=0; j<13; j++)
     {
         data[i][j]=boarddata[i][j];
     }

 }

}
void Player::keyPressEvent(QKeyEvent*event)
{
    if (event->key()==Qt::Key_Up&&data[row-1][column]>=0)
    {
        row--;// this is not setting a position
         setPos(50+(50*column),50+(50*row));
    }
    else if ( event->key()==Qt::Key_Down&&data[row+1][column]>=0)
    {
        row++;
          setPos(50+(50*column),50+(50*row));
    }
       else if ( event->key()==Qt::Key_Right&&data[row][column+1]>=0)
    {
           column++;
          setPos(50+(50*column),50+(50*row));
    }
    else if ( event->key()==Qt::Key_Left&&data[row][column-1]>=0)
 {
        column--;
         setPos(50+(50*column),50+(50*row));
 }
    QList<QGraphicsItem*> items = collidingItems();
        for (int i = 0; i < items.size(); i++)
        {
            if (typeid(*items[i]) == typeid(food))
                scene()->removeItem(items[i]);
        }
}
