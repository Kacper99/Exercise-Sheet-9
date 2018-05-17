#include <stdio.h>
#include <stdlib.h>

typedef int* TRIARR;

/*
Returns the position of an element in the array.

y(y+1)/2 will get you to the column and the addition of x gets you to the row.
Essentially the y is the series of triangular numbers and the x is the gap in-
between them
e.g. (1,1) will be in position 2
*/
int offset(int x, int y)
{
    return ((y * (y + 1)) / 2) + x;
}

/*
Creates a new triangle of size N
*/
TRIARR triNew(int N) 
{
    TRIARR array = (int*) malloc(offset(N, N) * sizeof(int)); //Allocates memory by getting the largest offset and multipying by the size of an int to get the required space
    if (array == NULL) printf("Failed to allocate memory\n"); //If memory failed to be allocated print error message
        
    return array; //Return pointer to the start of array
}

int triStore(TRIARR as, int N, int row, int col, int val) 
{
    if (row <= col && row < N && col < N) //Checking if the position passed in is valid (Position has to be within the array and x has to be smaller or equal to y)
    {
        *(as + offset(row, col)) = val; //Setting that position to passed in value. Pointer is calculated by getting the pointer to the start of the array and adding the offset
        return 1;
    }
    else 
    {
        return -1;
    }
}
    
int triFetch(TRIARR as, int N, int row, int col)
{
    if (row <= col && row < N && col < N) //Checking if the position passed is valid
    {
        int val = *(as + offset(row, col)); //Getting the value at that point, calculated in the same way storing is done
        printf("Value at %i , %i is %i \n", row, col, val); //Print the value
        return 1;
    }
    else
    {
        return -1;
    }
}

int main(int argc, char const *argv[])
{
    int size = 5;
    TRIARR as = triNew(size);
    for(int i = 0;i < size;i++)
    {
        for(int j = 0; j <= i; j++) 
        {
            printf("x: %i, y: %i, v: %i \n", j, i, i*j);
            triStore(as, size, j, i, i * j);
        }        
    }

    for(int i = 0;i < size;i++)
    {
        for(int j = 0; j <= i; j++) 
        {
            triFetch(as, size, j, i);
        }        
    }

    return 0;
}
