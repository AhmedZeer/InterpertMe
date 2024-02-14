#include "common.h"
#include "value.h"
#include "memory.h"
#include <stdio.h>

void initValueArray(ValueArray* array){
  array->count = 0;
  array->size = 0;
  array->values = NULL;
}

void writeValueArray(ValueArray* array, double value){

  if( array->count + 1 > array->size ){
    int oldCapacity = array->capacity;
    array->capacity = GROW_CAPACITY(oldCapacity);
    values = GROW_ARRAY(Value, array->values, oldCapacity, array->capacity);
  }
  
  array->values[array->count] = value;
  array->count++;
}

void freeValueArray(ValueArray* array){
  FREE_ARRAY(Value , array->values , array->capacity);
  initValueArray(array);
}
