#include <stdio.h>
#include "chapter2.h"
#include <assert.h>
#include <string.h>
#include <stdint.h>
#include <limits.h>
int main(int argc, char* argv[]) {
  assert(threefourths(8) == 6);
  assert(threefourths(9) == 6);
  assert(threefourths(10) == 7);
  assert(threefourths(11) == 8);
  assert(threefourths(12) == 9);

  assert(threefourths(-8) == -6);
  assert(threefourths(-9) == -6);
  assert(threefourths(-10) == -7);
  assert(threefourths(-11) == -8);
  assert(threefourths(-12) == -9);
  return 0;
}

