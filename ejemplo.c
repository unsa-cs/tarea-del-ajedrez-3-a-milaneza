#include "chess.h"
#include "figures.h"
#include "gc.h"

void display(){
  //char** blackSquare = reverse(whiteSquare);
  //interpreter(blackSquare);
  //asignar
  int **a;
  memoryAlloc((void **)&a, 59*sizeof(int)); 
  countMemoryEntries();
  for (int i = 0; i<58; i++)
    memoryAlloc((void**)&a[i], 59*sizeof(int));
  countMemoryEntries();
  
  //desvincular memoria
  for(int i=0;i<58;i++){
    unregisterPointer((void**)&a[i]);
  }
  countMemoryEntries();
  unregisterPointer((void**)&a);
  countMemoryEntries();
  garbageCollector();
}
