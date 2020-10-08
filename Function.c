#include <math.h>
#include <stdio.h>
#include <stdlib.h>

enum nRoots_type
{
    ERROR_ROOTS = -1,
    NO_ROOTS = 0,
    ONE_ROOT = 1,
    TWO_ROOTS = 2,
    INF_ROOTS = 3,
};

const int MAX_BUF_SIZE = 1000;

int IsZero(double forCompare)
    {
        const double small = 1e-6;

        if (fabs(forCompare) <  small) return 1;
        if (fabs(forCompare) >= small) return 0;
    }
enum nRoots_type SolveLinear(double b, double c, double* x)
{
        if (b!=0)
        {
            *x = -c/b;

            return 1;
        }
        if (IsZero(b) == 1 && IsZero(c) == 1)
        {
            return 3;
        }
        if (IsZero(b) == 1 && c!=0)
        {
            return 0;
        }
        else return -1;
}
enum nRoots_type SolveQuadratic (double a, double b, double c, double* x1, double* x2, double* x)
{

        double discrim = b*b - 4*a*c;

        if (IsZero(discrim) == 1) discrim = 0;

        if (discrim > 0)
        {
            *x1 = (-b - sqrt(discrim))/(2*a);
            *x2 = (-b + sqrt(discrim))/(2*a);

            return 2;
        }

        if (discrim == 0)
        {
            *x = -b/2*a;
            *x = round(*x);

            return 1;

        }
        if (discrim < 0)
        {
            return 0;
        }
        else return -1;
}
/*  Некорректно работает в некоторых случаях
double ScanNumber (double scanned)
{
    while(scanf("%lf",&scanned) != 1)
    {
        printf("Please enter the coefficient of the equation\n");
        fflush(stdin);
    }
    return scanned;
} */

double ScanNumber (double scanned)
{
    while(1)
    {
            char StringBuf [MAX_BUF_SIZE];

            while(scanf("%s", StringBuf) != 1)
            {
                printf("Please enter the coefficient of the equation\n");
                fflush(stdin);
            }

            char* String = StringBuf;
            while (*String == ' ')
                ++String;

            char* runner_len = String;

            int len_string = 0;

            while (*runner_len != '\0')
            {
                runner_len = runner_len + 1;
                len_string = len_string + 1;
            }

            int one_point = 0;
            int one_comma = 0;
            int error_enter = 0;
            int num_element = 0;
            int one_probel = 0;

            for(num_element; num_element < len_string; num_element++)
            {
                if (String[num_element] == '.') one_point++;
                if (String[num_element] == ',') one_comma++;
                if (String[num_element] == ' ') one_probel++;

                if (String[num_element] == ',') String[num_element] = '.';

                if (one_comma > 1 || one_point > 1 || one_probel == 1)
                {
                    error_enter = 1;
                    break;
                }

                if (num_element == 0)
                {
                    if ((!isdigit (String[num_element]) && (String[num_element] != '-')))
                    {
                        error_enter = 1;
                    }
                }
                if (num_element > 0)
                {
                    if ((!isdigit (String[num_element]) && (String[num_element] != '.') && (String[num_element] != ',')))
                    {
                        error_enter = 1;
                    }
                }
            }
            if (error_enter == 1  || one_comma > 1 || one_point > 1 || (one_point == 1 && one_comma == 1))
                printf ("Please enter the coefficient of the equation\n");
            if (error_enter == 0)
            {
                sscanf(String, "%lg", &scanned);

                break;
            }
    }

    return scanned;
}
