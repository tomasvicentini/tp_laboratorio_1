#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"

int suma(int num1, int num2)
{
    int totalSuma;
    totalSuma = num1 + num2;
    return totalSuma;
}
int resta(int num1, int num2)
{
    int totalResta;
    totalResta = num1 - num2;
    return totalResta;
}
float division(int num1, int num2)
{
    float totalDiv;

    totalDiv = (float)num1 / (float)num2;

    return totalDiv;
}
int multiplicacion(int num1, int num2)
{
    int totalMult;
    totalMult = num1 * num2;
    return totalMult;
}
int factorialA(int num1)
{
    int total = 1;
    int i;

    for(i=1; i<=num1; i++)
    {
        if(num1 == 0)
        {
            total = 1;
        }
        else
        {
            total *= i;
        }
    }
    return total;
}
int factorialB(int num2)
{
    int total = 1;
    int i;

    for(i=1; i<=num2; i++)
    {
        if(num2 == 0)
        {
            total = 1;
        }
        else
        {
            total *= i;
        }
    }
    return total;
}
