#include <emscripten.h>
#include <stdlib.h>

extern unsigned int curTime();
extern void logProgress(double progress);

int main()
{
  return 0;
}

EMSCRIPTEN_KEEPALIVE
unsigned char *randString(int len)
{
  // malloc это функция из JS, которую мы поставляем в env.emscripten_resize_heap
  unsigned char *str = malloc(len + 1); // Allocate memory for len characters + null terminator

  srand(curTime()); // Seed the random number generator

  for (int i = 0; i < len; i++)
  {
    // generate printable character
    str[i] = rand() % (127 - 33) + 33;
    logProgress((double)(i + 1) / (double)len); // This is called type casting
  }

  str[len] = 0; // Null-terminate the string
  return str;
}
