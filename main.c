
#define RED 0
#define GREEN 1
#define BLUE 2
#define ALPHA 3

unsigned char * PIX(int *chien, int width, int x, int y){
  return ((unsigned char *)&(chien[(y * width + x)]));
}

void processImage(int *data, int *out, int width, int height, unsigned char amount)
{
  for (int y = 1; y < height - 1; y += 1)
  {
    for (int x = 1; x < width - 1; x += 1)
    {
      unsigned char *pix = PIX(data, width, x, y);
      unsigned char *pix2 = PIX(out, width, x, y);
      pix2[ALPHA] = 255;

      if (pix[RED] == 253){

        int alias = 0;

        unsigned char *_1 = PIX(data, width, x, y+1);
        unsigned char *_2 = PIX(data, width, x, y-1);
        unsigned char *_3 = PIX(data, width, x+1, y);
        unsigned char *_4 = PIX(data, width, x+1, y+1);
        unsigned char *_5 = PIX(data, width, x+1, y-1);
        unsigned char *_6 = PIX(data, width, x-1, y);
        unsigned char *_7 = PIX(data, width, x-1, y+1);
        unsigned char *_8 = PIX(data, width, x-1, y-1);

        if (_1[RED] == 0){alias += 1;}
        if (_2[RED] == 0){alias += 1;}
        if (_3[RED] == 0){alias += 1;}
        if (_4[RED] == 0){alias += 1;}
        if (_5[RED] == 0){alias += 1;}
        if (_6[RED] == 0){alias += 1;}
        if (_7[RED] == 0){alias += 1;}
        if (_8[RED] == 0){alias += 1;}


        pix2[RED] = amount ;
        pix2[GREEN] = 0 ;
        pix2[BLUE] = 100 ;
        float factor = 1;
        if (alias >= 4){
          pix2[ALPHA] = 50  * factor;
        } else if (alias >= 3) {
          pix2[ALPHA] = 75 * factor;
        } else if (alias >= 2){
          pix2[ALPHA] = 150 * factor;
        } else if (alias >= 1){
          pix2[ALPHA] = 200 * factor;
        }


      } else {
        pix2[RED] = 0;
        pix2[GREEN] = 0;
        pix2[BLUE] = 0;
        pix2[ALPHA] = 0;
      }

      // if (pix[RED] > 160){
      //   pix[BLUE] = 250 - amount;
      // }
      // pix[RED] = amount;
      // pix[GREEN] = 250 - amount;
      // pix[BLUE] = 250 - amount;
    }
  }
}
