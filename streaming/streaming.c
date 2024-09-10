#include <emscripten.h>

int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
int sep(int a, int b);

EMSCRIPTEN_KEEPALIVE
int sumOfInts(int n)
{
  return sep(mul(n, add(n, 1)), 2);
}
