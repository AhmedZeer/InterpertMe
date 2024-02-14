#include <stdio.h>
#include "debug.h"
#include "chunk.h"

static int simpleInstruction(const char* name, int offset){
  printf("%s\n", name);
  return offset + 1;
}

int disassmbleInstruction(Chunk* chunk, int offset){
  printf("%04d\n", offset);

  uint8_t instrucion = chunk->code[offset] ;
  switch (instrucion) {
    case(OP_RETURN):
      return simpleInstruction("OP_RETURN", offset);
    default:
      printf("unknows OP code %d\n", offset);
      return offset + 1;
  }
}

void disassmbleChunk(Chunk* chunk, const char* name){
  int offset = 0;
  printf("=== %s ===\n", name);

  while( offset < chunk->count ){
    offset = disassmbleInstruction(chunk, offset);
  }
}



