#include "chess.h"
#include "figures.h"
#include "gc.h"

void display(){
  //char** blackSquare = reverse(whiteSquare);
  //interpreter(blackSquare);
  int *a;
  memoryAlloc((void **)&a, sizeof(int));
  countMemoryEntries();
  garbageCollector();
}
