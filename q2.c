#include <stdio.h>
#include <stdlib.h>

typedef int* TRIARR;

/*
Valid only when rows <= columns
e.g. [1,3], [2,3], [3,3] are valid but [4,3] wouldn't be
*/

TRIARR triNew(int n) 
{
    TRIARR array = malloc(((n*(n + 1))/2) * sizeof(int)); //The size will be the triangular number times the size of integer
    if (array = NULL) //Print error message 
    {
        printf("Failed to allocate memory\n");
    }
    return (int)* array;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
