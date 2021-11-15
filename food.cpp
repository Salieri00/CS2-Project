#include "food.h"

food::food()
{

    // Set Image
       QPixmap image("cheese.png");
       image = image.scaledToWidth(30);
       image = image.scaledToHeight(30);
       setPixmap(image);
       // Set Position
        //setPos(50 + 1 * 50, 50 + 1 * 50);
        // setPos(50 + 8 * 50, 50 + 12 * 50);
}
