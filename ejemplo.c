#include "chess.h"
#include "figures.h"
#include "gc.h"

void display(){
  //char** blackSquare = reverse(whiteSquare);
  //interpreter(blackSquare);
  //asignar
  int rows=58; 
  int cols=rows;
  int **a;
  memoryAlloc((void **)&a, (rows+1)*sizeof(int*)); 
  countMemoryEntries();
  for (int i = 0; i<rows; i++)
    memoryAlloc((void**)&a[i], (cols+1)*sizeof(int));
  countMemoryEntries();
  
  //desvincular memoria
  for(int i=0;a[i];i++){
    unregisterPointer((void**)&a[i]);
  }
  countMemoryEntries();
  unregisterPointer((void**)&a);
  countMemoryEntries();
  garbageCollector();
}
