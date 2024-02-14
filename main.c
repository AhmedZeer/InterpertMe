#include "common.h"
#include "chunk.h"
#include "debug.h"

int main(int argc, char *argv[])
{
  Chunk chunk;

  initChunk(&chunk);
  writeChunk(&chunk, OP_RETURN);
  disassmbleChunk(&chunk, "testChunk");
  freeChunk(&chunk);

  return 0;
}
