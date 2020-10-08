#ifndef FUNCTION_H_
#define FUNCTION_H_

#include <stdio.h>
#include <math.h>

enum nRoots_type
{
    ERROR_ROOTS = -1,
    NO_ROOTS = 0,
    ONE_ROOT = 1,
    TWO_ROOTS = 2,
    INF_ROOTS = 3,
};

int IsZero(double forCompare);
int SolveLinear(double b, double c, double* x);
int SolveQuadratic (double a, double b, double c, double* x1, double* x2, double* x);
double ScanNumber (double scanned);

#endif
