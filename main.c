
#define RED 0
#define GREEN 1
#define BLUE 2
#define ALPHA 3

#define PIX(x, y) ((unsigned char *)&(data[(y * width + x)]))

void processImage(int *data, int width, int height, unsigned char amount)
{
  for (int y = 0; y < height; y += 1)
  {
    for (int x = 0; x < width; x += 1)
    {
      {
        unsigned char *pix = PIX(x, y);
        pix[RED] = amount;
        pix[GREEN] = 250 - amount;
        pix[BLUE] = 250 - amount;
      }
    }
  }
}
