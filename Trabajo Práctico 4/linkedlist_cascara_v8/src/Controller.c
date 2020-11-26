#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* La ruta donde se encuentra el archivo
 * \param pArrayListEmployee LinkedList* La lista de empleados
 * \return int (0) si se cargo el archivo
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = -1;

    FILE* pFile;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "r");

        if(pFile != NULL)
        {

            if(!parser_EmployeeFromText(pFile, pArrayListEmployee))
            {
                printf(" Carga en modo texto exitosa!!\n");
                retorno = 0;
            }
            else
            {
                printf(" Hubo un error al cargar el archivo .csv\n");
            }
        }
        else
        {
            printf(" El archivo no se pudo abrir correctamente\n");
        }

        fclose(pFile);
    }

    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char* La ruta donde se encuentra el archivo
 * \param pArrayListEmployee LinkedList* La lista de empleados
 * \return int (0) si se cargo el archivo
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE* pFile;

    if(path !=NULL && pArrayListEmployee !=NULL)
    {
        pFile = fopen(path,"rb");

        if(pFile !=NULL)
        {
            if(!parser_EmployeeFromBinary(pFile,pArrayListEmployee))
            {
                printf(" Carga en modo binario exitosa!!\n");
                retorno = 0;
            }
            else
            {
                printf(" Hubo un error al cargar el archivo .bin\n");
            }
        }
        else
        {
            printf(" El archivo no se pudo abrir correctamente\n");
        }

        fclose(pFile);
    }

    return retorno;
}

/** \brief Alta de empleados
 * \param pArrayListEmployee LinkedList* La lista de empleados
 * \return int (1) si se agrego el empleado
 *
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 0;

    if(pArrayListEmployee !=NULL)
    {
        if(darAlta(pArrayListEmployee))
        {
            printf("\n");
            printf(" Empleado dado de alta con exito!!!\n");
            retorno = 1;
        }
        else
        {
            printf(" Hubo un error\n");
        }
    }
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param pArrayListEmployee LinkedList* La lista de empleados
 * \return int (1) si se modifico el empleado
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 0;

    if(pArrayListEmployee !=NULL)
    {
        if(darModificacion(pArrayListEmployee))
        {
            printf("\n");
            printf(" Modificación ejecutada con exito!!!\n");
            retorno = 1;
        }
        else
        {
            printf(" Hubo un error\n");
        }
    }
    return retorno;
}

/** \brief Baja de empleado
 *
 * \param pArrayListEmployee LinkedList* La lista de empleados
 * \return int (1) si se elimino el empleado
 *
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 0;

    if(pArrayListEmployee !=NULL)
    {
        if(darBaja(pArrayListEmployee))
        {
            printf("\n");
            printf(" Baja ejecutada con exito!!!\n");
            retorno = 1;
        }
        else
        {
            printf(" Hubo un error\n");
        }
    }

    return retorno;
}

/** \brief Listar empleados
 *
 * \param pArrayListEmployee LinkedList* La lista de empleados
 * \return int (1) si se listaron los empleados
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 0;

    if(pArrayListEmployee !=NULL)
    {
        if(listarEmpleados(pArrayListEmployee))
        {
            printf(" Empleados listados con exito!!!\n");
            retorno = 1;
        }
        else
        {
            printf(" Hubo un error\n");
        }
    }
    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param pArrayListEmployee LinkedList* La lista de empleados
 * \return int (1) si se ordenaron los empleados
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 0;

    if(pArrayListEmployee !=NULL)
    {
        if(ordenarEmpleados(pArrayListEmployee))
        {
            printf("\n");
            printf(" Empleados ordenados con exito!!!\n");
            retorno = 1;
        }
        else
        {
            printf(" Hubo un error\n");
        }
    }

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char* La ruta donde se guardara el archivo
 * \param pArrayListEmployee LinkedList* La lista de empleados a guardar
 * \return int (1) si se guardaron los empleados
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE* pFile;
    Employee* nuevoEmpleado;

    if(path !=NULL && pArrayListEmployee !=NULL)
    {
        pFile = fopen(path,"w");

        if(pFile !=NULL)
        {
            fprintf(pFile,"Id,Nombre,Horas,Sueldo\n");

            for(int i=0; i<ll_len(pArrayListEmployee); i++)
            {
                nuevoEmpleado = (Employee*)ll_get(pArrayListEmployee,i);

                if(nuevoEmpleado !=NULL)
                {
                    fprintf(pFile,"%d,%s,%d,%d\n",nuevoEmpleado->id,nuevoEmpleado->nombre,nuevoEmpleado->horasTrabajadas,nuevoEmpleado->sueldo);
                }
            }

            printf(" Empleados cargados en modo texto con exito!!!\n");
            retorno = 0;
        }
        else
        {
            printf(" Hubo un error al guardar el archivo .csv\n");
        }

        fclose(pFile);
    }

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.bin (modo binario).
 *
 * \param path char* La ruta donde se guardara el archivo
 * \param pArrayListEmployee LinkedList* La lista de empleados a guardar
 * \return int (1) si se guardaron los empleados
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE* pFile;
    Employee* nuevoEmpleado;

    if(path !=NULL && pArrayListEmployee !=NULL)
    {
        pFile = fopen(path,"wb");

        if(pFile !=NULL)
        {
            for(int i=0; i<ll_len(pArrayListEmployee); i++)
            {
                nuevoEmpleado = (Employee*)ll_get(pArrayListEmployee,i);

                if(nuevoEmpleado !=NULL)
                {
                    fwrite(nuevoEmpleado,sizeof(Employee),1,pFile);
                }
            }

            printf(" Empleados cargados en modo binario con exito!!!\n");
            retorno = 0;
        }
        else
        {
            printf(" Hubo un error al guardar el archivo .bin\n");
        }

        fclose(pFile);
    }

    return retorno;
}
