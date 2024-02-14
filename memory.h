#ifndef clox_memory_h

#define clox_memory_h
#include "common.h"

#define GROW_CAPACITY(capacity) ((capacity) < 8 ? 8 : (capacity)*2)
#define GROW_ARRAY(type, pointer, oldCount, newCount) \
                  (type*)reallocate(pointer, oldCount * sizeof(type),sizeof(type) * newCount)

#define FREE_ARRAY(type, pointer, oldCount) \
        reallocate( pointer, oldCount * sizeof(type), 0 )

void* reallocate(void* pointer, int oldSize, int newSize );
 
#endif
