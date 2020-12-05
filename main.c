char *chien(char *pa)
{
  return pa;
}

int doubler(int x)
{
  // int chien = (&x)[5000];
  (&x)[0] = 454;
  return (&x)[0];
}