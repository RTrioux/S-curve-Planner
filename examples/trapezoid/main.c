#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "motionPlanning.h"

#define ORDER 2
#define DT 5e-3

int main()
{
    srand(time(NULL));

    float Xpeak[ORDER + 1] = {200.0, 50.0, 30.0};
    float T[ORDER + 1] = {0, 0, 0};
    computePeriods(Xpeak, T);

    // for (int i = 0; i <= ORDER; i++) {
    //     printf("Xpeak[%d] = %f\n", i, Xpeak[i]);
    // }
    //
    // for (int i = 0; i <= ORDER; i++) {
    //     printf("T[%d] = %f\n", i, T[i]);
    // }

    for (int i = 0; i <= ceil(15 / DT); i++)
    {
        printf("%f\n", getSetpoint(Xpeak, T, DT * i));
    }

    return 0;
}