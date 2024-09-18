
#ifndef MY_VECTOR_H
#define MY_VECTOR_H
#include "status.h"




typedef void* MY_VECTOR;
MY_VECTOR my_vector_init_default(void);

Status my_vector_pop_back(MY_VECTOR hVector);

int my_vector_get_size(MY_VECTOR hVector);
int my_vector_get_capacity(MY_VECTOR hVector);
//know how many items in vector
Status my_vector_push_back(MY_VECTOR hVector, int value);
//look at and change the values of the items in the vector
int* my_vector_at(MY_VECTOR hVector, int index, Status* pStatus);
Boolean my_vector_is_empty(MY_VECTOR* hVector);



void my_vector_destroy(MY_VECTOR* phVector);

#endif