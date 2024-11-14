//#include <stdio.h>
#include <stdlib.h>
#include "chess.h"
#include "gc.h"

void  allocateMemory(int rows, size_t cols,char*** fig){
  
  memoryAlloc((void**)fig, sizeof(char*)*(rows + 1));
  for(int i = 0; i < rows; i++)
    memoryAlloc((void**)&(*fig)[i], sizeof(char)*(cols + 1));
  
}

void unlinkMemory(char*** fig){
  countMemoryEntries();
  for(int i = 0; (*fig)[i]; i++)
    unregisterPointer((void**)&(*fig)[i]);
  countMemoryEntries();
  unregisterPointer((void**)fig);
  countMemoryEntries();
}

char** reverse(char** fig){
  int rows = 0;
  while(fig[++rows]);
  
  int cols = 0;
  while(fig[0][++cols]);

  char** newFig;
  allocateMemory(rows, cols,&newFig);

  for(int i = 0; fig[i]; i++){
    for(int j = 0; fig[0][j]; j++){
      switch(fig[i][j]){
        case '@': newFig[i][j] = '.'; break;
        case '.': newFig[i][j] = '@'; break;
        case '=': newFig[i][j] = '_'; break;
        case '_': newFig[i][j] = '='; break;
        default : newFig[i][j] = fig[i][j]; break;
      }
    }
    newFig[i][cols] = 0;
  }
  newFig[rows] = 0;
  unlinkMemory(&newFig);
  return newFig;
}
char** join(char** fig1, char** fig2){
  int row = 0;
  while(fig1[++row]);
  
  int col = 0;
  while(fig1[0][++col]);

  int col2 = 0;
  while(fig2[0][++col2]);
  
  char** figurejoin;
  allocateMemory(row,col+col2-1,&figurejoin);
  for(int i = 0; i < row; i++){
    int j = 0, k = 0;
    while(fig1[i][k]){
      figurejoin[i][j] = fig1[i][k]; 
      k++;
      j++;
    }
    k=0;
    while(fig2[i][k]){
      figurejoin[i][j] = fig2[i][k];
      k++;
      j++;
    }
    figurejoin[i][col*2] = 0 ; 
  }
  figurejoin[row]=0;
  unlinkMemory(&figurejoin);
  return figurejoin;
}

