#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"

int main()
{
    int num1 = 0;
    int num2 = 0;
    int a, b, d, e, f;
    float c;
    int flag1 = 0;
    int flag2 = 0;
    int flag3 = 0;
    int opcion;

    do
    {
        system("cls");
        printf("****************CALCULADORA******************");
        printf("\n***1- Ingresar 1er operando (A=%.3i)       ***", num1);
        printf("\n***2- Ingresar 2do operando (B=%.3i)       ***", num2);
        printf("\n***3- Calcular todas las operaciones      ***");
        printf("\n***4- Informar resultados                 ***");
        printf("\n***5- Salir                               ***");
        printf("\n*********************************************");
        printf("\n\nINTRODUZCA OPCION (1-5): ");
        fflush(stdin);
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                printf("Ingresar 1er operando: ");
                scanf("%i", &num1);
                flag1 = 1;
                system("pause");
                break;
            case 2:
                system("cls");
                printf("Ingresar 2do operando: ");
                scanf("%i", &num2);
                flag2 = 1;
                system("pause");
                break;
            case 3:
                if(flag1 == 1 && flag2 == 1)
                {
                    system("cls");
                    printf("CALCULANDO RESULTADOS... Aguarde por favor\n\n");
                    system("pause");
                    printf("\n\nSe calculo la suma de A+B");
                    printf("\n\nSe calculo la resta de A-B");
                    printf("\n\nSe calculo la division de A/B");
                    printf("\n\nSe calculo la multiplicacion de A*B");
                    printf("\n\nSe calcularon ambas factoriales A! y B!\n\n");

                    flag3 = 1;
                    system("pause");
                }
                else
                {
                    system("cls");
                    printf("ERROR !!!");
                    printf("\nDEBE INGRESAR LOS VALORES EN LAS OPCIONES 1 Y 2\n\n");
                    system("pause");
                }
                break;
            case 4:
                if(flag3 == 1)
                {
                    system("cls");
                    a = suma(num1, num2);
                    printf("El resultado de A+B = %i", a);

                    b = resta(num1, num2);
                    printf("\n\nEl resultado de A-B = %i", b);

                    if(num2 == 0)
                    {
                        printf("\n\nERROR!!! No se puede dividir por 0(cero)");
                    }
                    else
                    {
                        c = division(num1, num2);
                        printf("\n\nEl resultado de A/B = %.2f", c);
                    }

                    d = multiplicacion(num1, num2);
                    printf("\n\nEl resultado de A*B = %i", d);

                    e = factorialA(num1);
                    f = factorialB(num2);
                    printf("\n\nEl resultado de A! = %i \nEl resultado de B! = %i\n\n", e, f);
                    system("pause");
                }
                else
                {
                    system("cls");
                    printf("DEBE CALCULAR LOS RESULTADOS UTILIZANDO LA OPCION 3!!!\n\n");
                    system("pause");
                }
                break;
            case 5:
                system("cls");
                printf("<<<<<Gracias por utilizar la Calculadora>>>>>");
                printf("\n\n<<<<<Presione cualquier tecla para salir>>>>>\n\n");
                system("exit");
                break;
            default:
                printf("OPCION INVALIDA!!!");
                printf("\n\nIntente de nuevo");
                system("pause");
        }
    }while(opcion != 5);

    return 0;
}



