#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*  La ruta del archivo que se cargara
 * \param pArrayListEmployee LinkedList* La lista de empleados
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int todoOk = -1;
    int cant;
    char buffer[4][128];
    Employee* nuevoEmpleado = NULL;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {

        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

        while(!feof(pFile))
        {

            cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

            if(cant <4)
            {
                if(feof(pFile))
                {
                    break;
                }
                else
                {
                    printf("Archivo corrupto\n");
                    break;
                }
            }

            nuevoEmpleado = employee_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);

            if(nuevoEmpleado != NULL)
            {
                ll_add(pArrayListEmployee, nuevoEmpleado);
            }
        }

        todoOk = 0;
    }

    return todoOk;
}


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char* La ruta del archivo que se cargara
 * \param pArrayListEmployee LinkedList* La lista de empleados
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    Employee* nuevoEmpleado;
    int cant;

    if(pFile !=NULL && pArrayListEmployee !=NULL)
    {
        while(!feof(pFile))
        {
            nuevoEmpleado = employee_new();

            if(nuevoEmpleado !=NULL)
            {
                cant = fread(nuevoEmpleado, sizeof(Employee), 1, pFile);

                if( cant < 1)
                {
                    if(feof(pFile))
                    {

                        break;
                    }
                    else
                    {
                        printf("Problemas para leer el archivo");
                    }
                }
                ll_add(pArrayListEmployee,nuevoEmpleado);
            }
        }

        retorno = 0;
    }

    return retorno;
}
