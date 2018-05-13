#include <stdio.h>
#include <math.h>

/*
int analyse(int *wholePtr, double *fracPtr, double d) {
    *fracPtr = (int) modf(d, wholePtr);

    if (d < 0) {
        return -1;
    } else {
        return 1;
    }
}
*/

int analyse(int *wholePtr, double *fracPtr, double d) {
    

    if (d < 0) {
        d += d * -2;
        *wholePtr = (int) d;
        *fracPtr = d - *wholePtr;
        return -1;
    } else {
        *wholePtr = (int) d;
        *fracPtr = d - *wholePtr;
        return 1;
    }
}

int main(int argc, char const *argv[]) {
    int sign;
    //double input, fracPart, wholePart;
    double input, fracPart;
    int wholePart;
    printf("What number would you like to analyse?\n");
    scanf("%lf", &input); //Check if I can use without the &

    sign = analyse(&wholePart, &fracPart, input);

    printf("The sign of the number is %i, the whole part is %i and the fractional part is %lf\n", sign, wholePart, fracPart);
    return 0;
}