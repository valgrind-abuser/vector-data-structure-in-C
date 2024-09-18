#include <stdio.h>
#include <stdlib.h>
#include "my_vector.h"

int main(int argc, char* argv[])
{
    MY_VECTOR hVector;
    int i;
    hVector = my_vector_init_default();
    if(hVector == NULL)
    {
        printf("Failed to allocate space for my_vector object.\n");
        exit(1);
    }

    if(my_vector_is_empty(hVector) == TRUE)
    {
        printf("yep\n");
    }
for(i = 0;i < 10;i++)
{
    if(my_vector_push_back(hVector, i) == FAILURE)
    {
        printf("Failed to push_back %d\n", i);
        exit(1);
    }
    printf("%d/%d\n", my_vector_get_size(hVector), my_vector_get_capacity(hVector));
}

while(my_vector_pop_back(hVector) == FALSE)
{
    printf("Pop!\n");
}

    *my_vector_at(hVector, 4, NULL) = 107;
while(my_vector_is_empty(hVector) == FALSE)
{
    printf("Pop!\n");
    printf("%d ->", *my_vector_at(hVector, my_vector_get_size(hVector) - 1, NULL));
    printf("yep\n");
    my_vector_pop_back(hVector);
}
    my_vector_destroy(&hVector);
    return 0;
}
