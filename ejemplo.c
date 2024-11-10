#include "chess.h"
#include "figures.h"
#include "gc.h"

void display(){
  //char** blackSquare = reverse(whiteSquare);
  //interpreter(blackSquare);
  int *a;
  int *b;
  memoryAlloc((void **)&a, sizeof(int));
  memoryAlloc((void **)&b, sizeof(int));

  countMemoryEntries();
  unregisterPointer((void **)&a);
  countMemoryEntries();
  garbageCollector();
}
