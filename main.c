#include <stdlib.h>

#define RED 0
#define GREEN 1
#define BLUE 2
#define ALPHA 3

#define PIX(x, y) ((unsigned char *)&(data[(y * width + x)]))

void processImage(int *data, int width, int height, int amount)
{
  for (int y = 0; y < height; y += 1)
  {
    for (int x = 0; x < width; x += 1)
    {
      if (y % amount == 0)
      {
        unsigned char *pix = PIX(x, y);
        pix[RED] = (unsigned char)amount;
        pix[GREEN] = 0;
        pix[BLUE] = 0;
      }
    }
  }
}
