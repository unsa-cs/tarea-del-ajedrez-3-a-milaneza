#include "chess.h"
#include "figures.h"
#include "gc.h"

void display(){
  //char** blackSquare = reverse(king);
  char** bishopknight = join(bishop, knight);
  interpreter(join(bishopknight, rook));
  garbageCollector();
  //asignar
  /*int rows=1; 
  int cols=rows;
  //funcion
  char **a;
  memoryAlloc((void **)&a, (rows+1)*sizeof(char*)); 
  countMemoryEntries();
  for (int i = 0; i<rows; i++)
    memoryAlloc((void**)&a[i], (cols+1)*sizeof(char));
  
  countMemoryEntries();
  //desvincular memoria
  for(int i=0;a[i];i++){
    unregisterPointer((void**)&a[i]);
  }
  countMemoryEntries();
  unregisterPointer((void**)&a);
  countMemoryEntries();
  unlinkMemory_2(&a);
  */
      
  
}
