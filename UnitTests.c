#include <math.h>
#include <stdio.h>

void QuadTest()
{
    const QuadUT = 6;
    const HELL = 666;

    double Koef_a[] = {1, 1, 1, 1, 1, 1};
    double Koef_b[] = {-3, 2, 2, 0, 4.000000004, 4.000000001, 0, 0, 1};
    double Koef_c[] = {2, 1, 3, 0, 4.000000001, 4.000000004, 0, 1, 2};
    int expected_nRoots[] =    {2, 1, 0, 1, 1, 1, 3, 0, 1};
    double expectedX1[] = {1, HELL, HELL, HELL, HELL, HELL};
    double expectedX2[] = {2, HELL, HELL, HELL, HELL, HELL};
    double expectedX [] = {HELL, -1, HELL, 0, -2, -2, HELL, HELL, -2};

    int received_nRoots[] = {0};
    double receivedX1[] = {0};
    double receivedX2[] = {0};
    double receivedX [] = {0};

    int i = 0; //Иначе компилятор ругается

    for (i; i < QuadUT; i++)
    {
        received_nRoots[i] = SolveQuadratic(Koef_a[i],Koef_b[i],Koef_c[i],&receivedX1[i],&receivedX2[i],&receivedX[i]);

        if (received_nRoots[i] == expected_nRoots[i])
        {
            if (received_nRoots[i] == 2)
            {
                if ((expectedX1[i] == receivedX1[i]) && (expectedX2[i] == receivedX2[i]))
                {
                    printf("Test %i ok", i+1);
                }
                else
                {
                    printf("Test %i BAD", i+1);
                }
                printf("\n");
            }
        }
        if (received_nRoots[i] == 1)
        {
            if (expectedX[i] == receivedX[i])
            {
                printf("Test %i ok", i+1);
            }
            if (expectedX[i] != receivedX[i])
            {
                printf("Test %i BAD", i+1);
            }
            printf("\n");
        }
        if (received_nRoots[i] == 0)
        {
            printf("Test %i ok\n", i+1);
        }
    }

    for (i; i < 9; i++)
    {
        received_nRoots[i] = SolveLinear(Koef_b[i], Koef_c[i], &receivedX[i]);

        if (received_nRoots[i] == expected_nRoots[i])
        {
            if (received_nRoots[i] == 3)
            {
                printf("Test %i ok\n", i+1);
            }
            if (received_nRoots[i] == 1)
            {
                if (expectedX[i] == receivedX[i])
                {
                    printf("Test %i ok",i+1);
                }
                if (expectedX[i] != receivedX[i])
                {
                    printf("Test %i BAD", i+1);
                }
                printf("\n");
            }
            if (received_nRoots[i] == 0)
            {
                printf("Test %i ok\n", i+1);
            }

        }
    }
}

