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
    if (array == NULL) //Print error message 
    {
        printf("Failed to allocate memory\n");
    }
    return array; //Return pointer to the start of array
}

int triStore(TRIARR as, int N, int row, int col, int val) 
{
    //Row <= column, row and column must be less than N
    if (row <= col && row < N && col < N)
    {
        *(as + (row * sizeof(int)) + (col * sizeof(int))) = val;
        return 1;
    }
    else 
    {
        return -1;
    }
    
}

int triFetch(TRIARR as, int N, int row, int col)
{
    if (row <= col && row < N && col < N) 
    {
        int val = *(as + (row * sizeof(int)) + (col * sizeof(int)));
        printf("Value at %i , %i is %i", row, col, val);
        return 1;
    }
    else
    {
        return -1;
    }
}

int main(int argc, char const *argv[])
{
    int size = 6;
    TRIARR as = triNew(6);

    triStore(as, size, 7, 7, 10);
    triFetch(as, size, 7, 7);
    return 0;
}
