#include <stdlib.h>
#include "my_vector.h"
#include <stdio.h>

struct my_vector   // known type
{
    int size;  // # of elements currently holding
    int capacity; // # of elements it can hold without resizing
    int* data;
};

typedef struct my_vector My_vector;

MY_VECTOR my_vector_init_default(void) {
    My_vector *pVector;

    pVector = malloc(sizeof(My_vector));
    if (pVector != NULL) {
        pVector->size = 0;
        pVector->capacity = 1;
        pVector->data = malloc(sizeof(int) * pVector->capacity);
        if (pVector->data == NULL) {
            free(pVector);
            return NULL;
        }
    }
    return pVector;
}

int my_vector_get_size(MY_VECTOR hVector)
{
    My_vector* pVector = (My_vector*)hVector;
    return pVector->size;
}
int my_vector_get_capacity(MY_VECTOR hVector)
{
My_vector* pVector = (My_vector*)hVector;
return pVector->capacity;
}

    Status my_vector_push_back(MY_VECTOR hVector, int value)
    {
        My_vector* pVector = (My_vector*)hVector;   // cast to known type
        int* temp;
        int i;
        if(pVector->size >= pVector->capacity)  // if it is full then make room
        {
           temp = (int*)malloc(sizeof(int) * pVector->capacity * 2);
           if(temp == NULL)
           {
               return FAILURE;
           }
           for(i = 0;i < pVector->size;i++)
           {
               temp[i] = pVector->data[i];
           }
           free(pVector->data);
           pVector->data = temp;   // copy data from temp to pVector
           pVector->capacity*= 2;  // double capacity
        }

        pVector->data[pVector->size] = value;
        pVector->size++;

        return SUCCESS;
    }

Boolean my_vector_is_empty(MY_VECTOR* hVector)
{
    My_vector* pVector = (My_vector*)hVector;
    if(pVector->size <= 0)
    {
        return TRUE;
    }
    return FALSE;
    return (pVector->size <= 0) ? TRUE : FALSE;   // another way to return.
}

Status my_vector_pop_back(MY_VECTOR hVector)
{
    My_vector* pVector = (My_vector*)hVector;    //cast to known type

    if(my_vector_is_empty(hVector) == TRUE)
    {
        return FAILURE;
    }
    pVector->size--;
    return SUCCESS;
}

int* my_vector_at(MY_VECTOR hVector, int index, Status* pStatus)
{
    My_vector* pVector = (My_vector*)hVector;

    if(index < 0 || index >= pVector->size)
    {
        if(pStatus != NULL)
        {
            *pStatus = FAILURE;
        }
        return NULL;
    }

    if(pStatus != NULL)
    {
        *pStatus = SUCCESS;
    }

    return &pVector->data[index];

}
void my_vector_destroy(MY_VECTOR* phVector)
{
    My_vector* pVector = (My_vector*)*phVector;  //clean up memory the object allocated
    free(pVector->data);

    free(pVector);
    *phVector = NULL;


}