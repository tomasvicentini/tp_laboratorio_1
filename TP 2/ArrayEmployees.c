#include "ArrayEmployees.h"

int initEmployees(Employee* lista, int len)
{
    int i;
    int flag = -1;

    for(i=0;(i<len)&&(len<=1000);i++)
    {
        lista[i].isEmpty = TRUE;
        flag = 0;
    }
    return flag;
}

void validadorInicializacionEmpleados(int flag,int len)
{
    if(flag==-1)
    {
        //ERROR
        printf("\nERROR!! Supera maximo de empleados habilitados (Max. 1000).\n\n");
    }
    else
    {
        //OK
        //printf("\n%d empleados liberados con exito.\n\n", len);
    }
    //system("pause");
    //system("cls");
}

int security(Employee listado[], int len)
{
    int i;
    int acceso = -1;
    for(i=0;i<len;i++)
    {
        if(listado[i].isEmpty==FALSE)
        {
            acceso = 0;
        }
    }
    return acceso;
}

int buscarLibre(Employee* listado, int tam)
{
    int i;
    int index = -1;
    for(i=0; i<tam; i++)
    {
        if(listado[i].isEmpty == TRUE)
        {
            index = i;
            break;
        }
    }
    return index;
}

int cargarUnEmpleado(Employee* lista, int len)
{
    char name[51], lastName[51];
    float salary;
    int sector, id, index, retorno;

    index = buscarLibre(lista, len);

    if(index!=-1)
    {
        id=index+1;
        printf("Nombre/s: ");
        //scanf("%s",&name);
        fflush(stdin);
        fgets(name,51,stdin);
        name[strlen(name)-1]='\n';
        name[strlen(name)-1]='\0';
        printf("Apellido/s: ");
        //scanf("%s",&lastName);
        fflush(stdin);
        fgets(lastName,51,stdin);
        lastName[strlen(lastName)-1]='\n';
        lastName[strlen(lastName)-1]='\0';
        printf("Salario: ");
        scanf("%f",&salary);
        printf("Sector: ");
        scanf("%d",&sector);

        retorno = addEmployee(lista,len,id,name,lastName,salary,sector);
    }
    else
    {
        retorno = index;
    }

    return retorno;
}

int addEmployee(Employee* lista, int len, int id, char name[],char lastName[],float salary,int sector)
{
    int retorno;
    int i = id-1;
    if(id<=(len+1))
    {
        lista[i].id = id;
        strcpy(lista[i].name, name);
        strcpy(lista[i].lastName, lastName);
        lista[i].salary = salary;
        lista[i].sector = sector;
        lista[i].isEmpty = FALSE;

        //CARGA CON EXITO
        retorno = 0;
    }
    else
    {
        //ERROR DE ESPACIO
        retorno = -1;
    }

    return retorno;
}

int findEmployeeById(Employee* lista, int len,int id)
{
    int retorno = -1;

    for(int i=0;i<len;i++)
    {
        if(lista[i].id == id)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}

void modificarEmpleado(Employee listado[], int tam)
{
    int id, retorno, opcion;
    printf("\n----MODIFICAR EMPLEADO----\n");
    printf("Ingrese ID del Empleado a modificar: ");
    scanf("%d", &id);

    retorno = findEmployeeById(listado,tam,id);
    system("cls");

    if(retorno!=-1)
    {
        do
        {
            printf("------MODIFICAR EMPLEADO------\n");
            printf("\t1- NOMBRE/S\n");
            printf("\t2- APELLIDO/S\n");
            printf("\t3- SALARIO\n");
            printf("\t4- SECTOR\n");
            printf("\t5- VOLVER\n");
            printf("----------------------------\n");
            printf("Elija una opcion: ");
            scanf("%d", &opcion);
            system("cls");

            switch(opcion)
            {
                case 1:
                    printf("Nombre/s: ");
                    //scanf("%s",&listado[id-1].name);
                    fflush(stdin);
                    fgets(listado[id-1].name,51,stdin);
                    listado[id-1].name[strlen(listado[id-1].name)-1]='\n';
                    listado[id-1].name[strlen(listado[id-1].name)-1]='\0';
                    printf("\nNombre modificado!\n\n");
                    system("pause");
                    system("cls");
                    break;
                case 2:
                    printf("Apellido/s: ");
                    //scanf("%s",&listado[id-1].lastName);
                    fflush(stdin);
                    fgets(listado[id-1].lastName,51,stdin);
                    listado[id-1].lastName[strlen(listado[id-1].lastName)-1]='\n';
                    listado[id-1].lastName[strlen(listado[id-1].lastName)-1]='\0';
                    printf("\nApellido modificado!\n\n");
                    system("pause");
                    system("cls");
                    break;
                case 3:
                    printf("Salario: ");
                    scanf("%f",&listado[id-1].salary);
                    printf("\nSalario modificado!\n\n");
                    system("pause");
                    system("cls");
                    break;
                case 4:
                    printf("Sector: ");
                    scanf("%d",&listado[id-1].sector);
                    printf("\nSector modificado!\n\n");
                    system("pause");
                    system("cls");
                    break;
                case 5:
                    system("cls");
                    break;
                default:
                    printf("\nOpcion invalida!!\n\n");
                    system("pause");
                    system("cls");
            }
        }while(opcion!=5);
    }
    else
    {
        printf("ERROR! El empleado no existe!!\n\n");
        system("pause");
        system("cls");
    }
}

int removeEmployee(Employee* listado, int len, int id)
{
    int retorno = -1;

    for(int i=0;i<len; i++)
    {
        if(listado[i].isEmpty == FALSE && id == listado[i].id)
        {
            listado[i].isEmpty = TRUE;
            retorno = 0;
            break;
        }
    }

    return retorno;
}

void eliminarEmpleado(Employee listado[], int tam)
{
    int idEliminar;
    int retorno;

    printf("\n----ELIMINAR EMPLEADO----\n");
    printf("Ingrese ID a eliminar: ");
    scanf("%d", &idEliminar);

    retorno = removeEmployee(listado,tam,idEliminar);
    system("cls");
    if(retorno==0)
    {
        printf("Empleado de ID=%d eliminado\n\n",idEliminar);
    }
    else
    {
        printf("Error! El empleado no existe\n\n");
    }
}


void mostrarListadoDeEmpleados(Employee listado[], int tam)
{
    int i;
    int flag = -1;
    printf("---------------------------------------------------------------------------------------------------\n");
    printf("%4s | %30s | %30s | %15s | %6s |\n","ID","NOMBRE", "APELLIDO", "SALARIO", "SECTOR");
    printf("---------------------------------------------------------------------------------------------------\n");
    for(i=0; i<tam; i++)
    {
       if(listado[i].isEmpty == FALSE)
        {
            printf("%4d | %30s | %30s | %15.2f | %6d |\n",  listado[i].id,
                                                            listado[i].name,
                                                            listado[i].lastName,
                                                            listado[i].salary,
                                                            listado[i].sector);
            flag = 0;
        }
    }
    if(flag==0)
    {
        printf("---------------------------------------------------------------------------------------------------\n");
    }
    else if(flag == -1)
    {
        printf("No se han cargado empleados\n\n");
    }
}

int printEmployees(Employee* listado, int length)
{
    int opcion;
    int retorno = -1;
    do
    {
        printf("1- MOSTRAR LISTADO EN ORDEN ASC\n");
        printf("2- MOSTRAR LISTADO EN ORDEN DESC\n");
        printf("Escriba una opcion: ");
        scanf("%d",&opcion);
        system("cls");
        switch(opcion)
        {
            case 1:
                retorno = sortEmployees(listado,length,1);
                break;
            case 2:
                retorno = sortEmployees(listado,length,0);
                break;
            default:
                printf("Opcion invalida!!!\n\n");
                system("pause");
                system("cls");
        }
    }while(opcion!=1 && opcion!=2);

    return retorno;
}

int sortEmployees(Employee* list, int len, int order)
{
    int i, j, retorno;
    Employee aux;

    if(list==NULL)
    {
        retorno = -1;
    }
    else
    {
        for(i=0;i<len-1;i++)
        {
            for(j=i+1;j<len;j++)
            {
                if(order==0)
                {
                    if(strcmp(list[i].lastName,list[j].lastName)<0)
                    {
                        aux=list[i];
                        list[i]=list[j];
                        list[j]=aux;
                        continue;
                    }
                    if(strcmp(list[i].lastName,list[j].lastName)==0)
                    {
                        if(list[i].sector<list[j].sector)
                        {
                            aux=list[i];
                            list[i]=list[j];
                            list[j]=aux;
                        }
                    }
                }
                else if(order==1)
                {
                    if(strcmp(list[i].lastName,list[j].lastName)>0)
                    {
                        aux=list[i];
                        list[i]=list[j];
                        list[j]=aux;
                        continue;
                    }
                    if(strcmp(list[i].lastName,list[j].lastName)==0)
                    {
                        if(list[i].sector>list[j].sector)
                        {
                            aux=list[i];
                            list[i]=list[j];
                            list[j]=aux;
                        }
                    }
                }
            }
        }
    }
    mostrarListadoDeEmpleados(list,len);
    salariosTotalesYpromedios(list,len);
    retorno=0;

    return retorno;
}

void ordenarListadoDeEmpleadosPorApellidoYporSector(Employee listado[], int tam)
{
    int i, j;
    Employee aux;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(listado[i].lastName,listado[j].lastName)>0)
            {
               aux = listado[i];
               listado[i] = listado[j];
               listado[j] = aux;
            }

            else if(strcmp(listado[i].lastName,listado[j].lastName)==0)
            {
                if(listado[i].sector>listado[j].sector)
                {
                        aux = listado[i];
                        listado[i] = listado[j];
                        listado[j] = aux;
                }
            }
        }
    }
}

void salariosTotalesYpromedios(Employee listado[], int len)
{
    int i, contEmplMasProm;
    float totalSalario, promedioSalario, contador;
    contEmplMasProm = 0;
    contador = 0;
    totalSalario = 0;

    for(i=0;i<len;i++)
    {
        if(listado[i].isEmpty==FALSE)
        {
            totalSalario += listado[i].salary;
            contador++;
        }
    }

    promedioSalario = totalSalario/contador;

    for(i=0;i<len;i++)
    {
        if(listado[i].isEmpty==FALSE && listado[i].salary > promedioSalario)
        {
            contEmplMasProm++;
        }
    }
    printf("TOTAL SALARIOS: %.2f\nPROMEDIO DE SALARIOS: %.2f\nEMPLEADOS QUE SUPERAN EL PROMEDIO: %d\n\n",totalSalario,
                                                                                                         promedioSalario,
                                                                                                         contEmplMasProm);
}
