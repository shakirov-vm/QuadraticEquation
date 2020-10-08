#include <stdio.h>
#include <math.h>

#include "UnitTests.h"
#include "Function.h"

int main()
{
    QuadTest();

    printf ("\nThis program displays the number of roots of a quadratic equation and the roots themselves\n");
    printf ("This program was written by Vadim Shakirov, its version is 1.3.1\n");
    printf ("You need to enter the coefficients of the equation a*x*x + b*x + c = 0. You will be prompted to enter them individually as a decimal.\n");

    double a = 0;
    double b = 0;
    double c = 0;

    printf ("\nEnter a: ");
    a = ScanNumber (a);

    printf ("\nEnter b: ");
    b = ScanNumber (b);

    printf ("\nEnter c: ");
    c = ScanNumber (c);

    printf ("\n");

    int nRoots = 0;

    double x  = 0;
    double x1 = 0;
    double x2 = 0;

    if (a!=0)
    {
        nRoots = SolveQuadratic(a,b,c,&x1,&x2,&x);
    }
    if  (a==0)
    {
        nRoots = SolveLinear(b,c,&x);

        printf ("This equation is not quadratic, but linear.\n\n");
    }

    if (IsZero(x) == 1) x = 0;
    if (IsZero(x1) == 1) x1 = 0;
    if (IsZero(x2) == 1) x2 = 0;

    switch (nRoots)
    {
        case NO_ROOTS:
        {
            printf ("There no roots");
            break;
        }
        case ONE_ROOT:
        {
            printf ("\nThere 1 root. x = %lf.", x);
            break;
        }
        case TWO_ROOTS:
        {
            printf ("\nThere 2 roots. x1 = %lf, x2 = %lf.", x1, x2);
            break;
        }
        case INF_ROOTS:
        {
            printf ("There are infinite roots here - any number is a solution");
            break;
        }
        default:
        {
            printf ("Error");
            break;
        }
    }
}
