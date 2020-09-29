#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#define OCUPADO 1
#define VACIO 0
#define T 1000

typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    float sueldo;
    int sector;
    int isEmpty;
} eEmpleado;

/** \brief Inicializa a los empleados
 *
 * \param eEmpleado[]
 * \param int
 * \return void
 *
 */
void inicializar(eEmpleado[],int);

/** \brief Muestra las opciones al usuario
 *
 * \param eEmpleado[]
 * \param int
 * \return void
 *
 */
void menuPrincipal(eEmpleado[],int);

/** \brief Muestra al usuario los informes disponibles
 *
 * \param eEmpleado[]
 * \param int
 * \return void
 *
 */
void menuInformes(eEmpleado[],int);

/** \brief Busca espacio libre, y lo devuelve si esta vacio, si no, salta un mensaje de error
 *
 * \param Eempleado[]
 * \param int
 * \return int
 *
 */
int buscarLibre(eEmpleado[],int);

/** \brief Permite encontrar a un empleado mediante su ID
 *
 * \param Eempleado[]
 * \param int
 * \param int
 * \return int
 *
 */
int buscarXid(eEmpleado[],int,int);

/** \brief Carga de manera incremental el ID de un empleado
 *
 * \param void
 * \return int
 *
 */
int cargarID();

/** \brief Ingresa los datos del empleado a dar de alta(pregunta si desea continuar)
 *
 * \param eEmpleado[]
 * \param int
 * \return void
 *
 */
void darAlta(eEmpleado[],int);

/** \brief Muestra datos de un empleado
 *
 * \param eEmpleado
 * \return void
 *
 */
void mostrarEmpleado(eEmpleado x);

/** \brief Muestra los datos de todos los empleados mediante un recorrido de todo el array
 *
 * \param eEmpleado[]
 * \param int
 * \return void
 *
 */
void mostrarEmpleados(eEmpleado[],int);

/** \brief Modifica los valores a elegir por parte del usuario
 *
 * \param eEmpleado[]
 * \param int
 * \return void
 *
 */
void darModificacion(eEmpleado[],int);

/** \brief Da de baja a un empleado, segun su ID
 *
 * \param eEmpleado[]
 * \param int
 * \return void
 *
 */
void darBaja(eEmpleado[],int);

/** \brief Ordena a los empleados por apellido y sector
 *
 * \param eEmpleado[]
 * \param int
 * \return void
 *
 */
void ordenar(eEmpleado[],int);

/** \brief Calcula y muestra el salario total y promedio de los empleados, y cuales empleados superan el salario promedio
 *
 * \param eEmpleado[]
 * \param int
 * \return void
 *
 */
void promediar(eEmpleado[],int);

/** \brief Valida que una cadena de caracteres reciba solo chars alfabeticos
 *
 * \param char[]
 * \return void
 *
 */
void validarString(char x[]);

/** \brief Recorre la cadena buscando que cada uno de sus chars sea igual a cero o positivo, si no muestra mensaje de error
 *
 * \param char[]
 * \return int
 *
 */
int validarEntero(char entero[]);

/** \brief Recorre la cadena buscando que cada uno de sus chars sea igual a cero o positivo, si no muestra mensaje de error
 *
 * \param char[]
 * \return float
 *
 */
float validarFloat(char sueldo[]);

/** \brief Recorre la cadena buscando una coma, en el caso de encontrarla la reemplaza por un punto, de forma que se permita ingresar un salario con coma
 *
 * \param char[]
 * \return void
 *
 */
void comaPunto(char sueldo[]);

/** \brief Pregunta si desea continuar, en caso de ingresar algo diferente a "s" o "n", muestra mensaje de error
 *
 * \return char
 *
 */
char validarSeguir();
#endif // arrayEmployees
