#include "tom.h"

Tom::Tom(int boarddata[13][13])
{
// set image
    QPixmap image ("1.png");
    image =image.scaledToWidth(50);
    image =image.scaledToHeight(50);
    setPixmap(image);
 // set position

//add to the scene but not in the constructor, in the main
// initializing the array
 row=8;
 column=8;
  setPos(50+(50*column),50+(50*row));
 for ( int i=0; i<13; i++)
 {
     for ( int j=0; j<13; j++)
         data[i][j]=boarddata[i][j];

 }


}

void Tom::movingTom ()
{
srand(time(0));
while (true)
{
    int n = rand()%4;

    if (n==0 && data[row-1][column]>=0)
    {
        row--;// this is not setting a position
         setPos(50+(50*column),50+(50*row));

    }
        else if (n=1 && data[row+1][column]>=0)
    {
        row++;
          setPos(50+(50*column),50+(50*row));
    }
    else if ( n=2 && data[row][column+1]>=0)
 {
        column++;
       setPos(50+(50*column),50+(50*row));
 }
 else if ( n =3 &&data[row][column-1]>=0)
{
     column--;
      setPos(50+(50*column),50+(50*row));
}




}


}



