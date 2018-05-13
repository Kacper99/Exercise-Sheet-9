#include <stdio.h>
#include <math.h>

int analyse(int *wholePtr, double *fracPtr, double d) {
    if (d < 0) { //If the number is below we will return -1, else we will return 1
        d += d * -2; //As the required output is to show the fractional and whole part without the minus we have to turn into a positive number
        *wholePtr = (int) d; //Casting the double to an int will always round down
        *fracPtr = d - *wholePtr; //We take away the whole part and get left with the fractional part
        return -1;
    } else {
        *wholePtr = (int) d;
        *fracPtr = d - *wholePtr;
        return 1;
    }
}

int main(int argc, char const *argv[]) {
    int sign, wholePart;
    double input, fracPart;

    printf("What number would you like to analyse?\n");
    scanf("%lf", &input);

    sign = analyse(&wholePart, &fracPart, input);

    printf("The sign of the number is %i, the whole part is %i and the fractional part is %lf\n", sign, wholePart, fracPart);
    return 0;
}