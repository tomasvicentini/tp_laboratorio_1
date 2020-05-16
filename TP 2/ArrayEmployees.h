#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define T 1000
#define FALSE 0
#define TRUE 1

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}Employee;


/** \brief Inicializa estado de todos los empleados a vacios
 *
 * \param lista Employee*
 * \param len int
 * \return flag int (-1) ERROR - (0) OK
 *
 */
int initEmployees(Employee* lista, int len);

/** \brief valida que sea correcta la inicializacion de empleados
 *
 * \param lista Employee*
 * \param len int
 * \return flag int (-1) ERROR - (0) OK
 *
 */
void validadorInicializacionEmpleados(int flag,int len);

/** \brief valida que se haya ingresado al menos un empleado
 *
 * \param lista Employee*
 * \param len int
 *
 */
int security(Employee listado[], int len);

/** \brief busca estados libres de empleados para crear uno nuevo
 *
 * \param lista Employee*
 * \param tam int
 * \return acceso int (-1) ERROR - (!=0) OK
 *
 */
int buscarLibre(Employee* listado, int tam);

/** \brief carga los datos de un empleado
 *
 * \param lista Employee*
 * \param len int
 * \return retorno int (-1) ERROR - (!=0) OK
 *
 */
int cargarUnEmpleado(Employee* lista, int len);

/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*/
int addEmployee(Employee* lista, int len, int id, char name[],char lastName[],float salary,int sector);

/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/
int findEmployeeById(Employee* lista, int len,int id);


/** \brief modifica un empleado por ID
 *
 * \param listado Employee*
 * \param tam int
 *
 */
void modificarEmpleado(Employee listado[], int tam);

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param listado Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
int removeEmployee(Employee* listado, int len, int id);

/** \brief elimina un empleado por ID
 *
 * \param listado Employee*
 * \param len int
 *
 */
void eliminarEmpleado(Employee listado[], int tam);

/** \brief muestra listado de empleados con estado FALSE
 *
 * \param listado Employee*
 * \param tam int
 *
 */
void mostrarListadoDeEmpleados(Employee listado[], int tam);

/** \brief print the content of employees array
*
* \param listado Employee*
* \param length int
* \return int
*
*/
int printEmployees(Employee* listado, int length);

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(Employee* list, int len, int order);

/** \brief calcula suma de salarios totales, promedio de salarios y cantidad de empleados que superan ese promedio
 *
 * \param listado Employee*
 * \param len int
 *
 */
void salariosTotalesYpromedios(Employee listado[], int len);
