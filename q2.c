#include <stdio.h>
#include <stdlib.h>

typedef int* TRIARR;

/*
Valid only when rows <= columns
e.g. [1,3], [2,3], [3,3] are valid but [4,3] wouldn't be
*/

TRIARR triNew(int n) 
{
    TRIARR array = (int*) malloc(((n*(n + 1))/2) * sizeof(int)); //The size will be the triangular number times the size of integer
    if (array == NULL) //Print error message 
    {
        printf("Failed to allocate memory\n");
    }
    return array; //Return pointer to the start of array
}

int triStore(TRIARR as, int N, int row, int col, int val) 
{
    if (row <= col && row < N && col < N)
    {
        *(as + row + col) = val;
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
        int val = *(as + row + col);
        printf("Value at %i , %i is %i \n", row, col, val);
        return 1;
    }
    else
    {
        return -1;
    }
}

int main(int argc, char const *argv[])
{
    int size = 10;
    TRIARR as = triNew(size);
    for(int i = 0;i < size;i++)
    {
        for(int j = 0; j < i; j++) 
        {
            triStore(as, size, j, i, i * 2);
        }        
    }

    for(int i = 0;i < size;i++)
    {
        for(int j = 0; j < i; j++) 
        {
            triFetch(as, size, j, i);
        }        
    }

    return 0;
}
