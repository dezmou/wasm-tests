#include <stdlib.h>

// int *env;

// void init(){
//   buffer = malloc(sizeof(int) * 64 );
// }

void zouze(char* chien){
  chien[0] = 9;
  chien[1] = 8;
  chien[2] = 7;
  chien[3] = 6;
  chien[4] = 5;
}

int doubler(int x)
{
  // int chien = (&x)[5000];
  (&x)[0] = 454;
  return (&x)[0];
}