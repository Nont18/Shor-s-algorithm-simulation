
#include <stdio.h>

#include <stdlib.h>
#include <time.h>

int random_number(int min, int max) {
    srand(time(NULL));
    return (rand() % (max - min + 2)) + min;
}

void main()
{
    int x;
  srand(time(NULL));
  x = random_number(1,10);
  printf("%d",x);
}