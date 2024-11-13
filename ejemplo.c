#include "chess.h"
#include "figures.h"
#include "gc.h"
void unlinkMemory_2(char** fig){
  countMemoryEntries();
  for(int i = 0; fig[i]; i++)
    unregisterPointer((void**)&fig[i]);
  countMemoryEntries();
  unregisterPointer((void**)&fig);
  countMemoryEntries();
}


void display(){
  //char** blackSquare = reverse(whiteSquare);
  //interpreter(blackSquare);
  //asignar
  int rows=1; 
  int cols=rows;
  //funcion
  char **a;
  memoryAlloc((void **)&a, (rows+1)*sizeof(char*)); 
  countMemoryEntries();
  for (int i = 0; i<rows; i++)
    memoryAlloc((void**)&a[i], (cols+1)*sizeof(char));
  /*
  countMemoryEntries();
  //desvincular memoria
  for(int i=0;a[i];i++){
    unregisterPointer((void**)&a[i]);
  }
  countMemoryEntries();
  unregisterPointer((void**)&a);
  countMemoryEntries();*/
  unlinkMemory_2(a);
  garbageCollector();
}
