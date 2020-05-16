#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"


int main()
{
    int opcion, a, ini, m, permiso;
    Employee listaEmployee[T]; /*= {   {1,"Juan Roman","Riquelme",1000.50,2,FALSE},
                                    {2,"Sergio", "Aguero",500,3,FALSE},
                                    {3,"Thierry", "Henry",5000,2,FALSE},
                                    {4,"Dennis", "Henry",5000,1,FALSE}
                                };*/
    ini = initEmployees(listaEmployee,T);
    validadorInicializacionEmpleados(ini,T);

    do
    {
        printf("-------MENU DE OPCIONES-------\n");
        printf("1- ALTAS\n");
        printf("2- MODIFICAR\n");
        printf("3- ELIMINAR\n");
        printf("4- INFORMAR\n");
        printf("5- SALIR\n");
        printf("------------------------------\n");
        printf("Elija una opcion: ");
        scanf("%d", &opcion);
        system("cls");

        switch(opcion)
        {
            case 1:
                printf("----CARGAR EMPLEADO----\n\n");
                a = cargarUnEmpleado(listaEmployee, T);
                if(a==-1)
                {
                    printf("Error! Espacio insuficiente.\n\n");
                }
                else
                {
                    printf("\nEmpleado creado con exito!\n\n");
                }
                system("pause");
                system("cls");
                break;
            case 2:
                permiso = security(listaEmployee,T);
                if(permiso==0)
                {
                    mostrarListadoDeEmpleados(listaEmployee,T);
                    modificarEmpleado(listaEmployee,T);
                }
                else
                {
                    printf("ERROR!!! Aun no ingresado ningun empleado\n\n");
                    system("pause");
                }
                system("cls");
                break;
            case 3:
                permiso = security(listaEmployee,T);
                if(permiso==0)
                {
                    mostrarListadoDeEmpleados(listaEmployee,T);
                    eliminarEmpleado(listaEmployee,T);
                }
                else
                {
                    printf("ERROR!!! Aun no ingresado ningun empleado\n\n");
                }
                system("pause");
                system("cls");
                break;
            case 4:
                permiso = security(listaEmployee,T);
                if(permiso==0)
                {
                    m = printEmployees(listaEmployee,T);
                    if(m == -1)
                    {
                        printf("No se han cargado empleados\n\n");
                    }
                }
                else
                {
                    printf("ERROR!!! Aun no ingresado ningun empleado\n\n");
                }
                system("pause");
                system("cls");
                break;
            case 5:
                printf("\n\t\t==================\n\t\t=  Hasta luego!  =\n\t\t==================\n");
                break;
            default:
                printf("ERROR! Opcion invalida.\n\n");
                system("pause");
                system("cls");
        }

    }while(opcion!=5);


    return 0;
}
