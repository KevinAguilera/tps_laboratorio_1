#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "validaciones.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int opcion;
    char valOpcion[3];
    char seguir = 's';
    int flagText = 0;
    int flagBin = 0;
    int flagUno = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();

    do
    {
        system("cls");
        printf(" ==============================================================================\n");
        printf(" #                         Trabajo Practico Nro. 3                            #\n");
        printf(" #                                                                            #\n");
        printf(" #                         >>>> MENU DE OPCIONES <<<<                         #\n");
        printf(" ==============================================================================\n");
        printf(" |                                                                            |\n");
        printf("   1- Cargar datos de los empleados desde el archivo data.csv (modo texto)     \n");
        printf(" |                                                                            |\n");
        printf("   2- Cargar datos de los empleados desde el archivo data.bin (modo binario)   \n");
        printf(" |                                                                            |\n");
        printf("   3- Alta de empleado                                                         \n");
        printf(" |                                                                            |\n");
        printf("   4- Modificar datos de empleado                                              \n");
        printf(" |                                                                            |\n");
        printf("   5- Baja de empleado                                                         \n");
        printf(" |                                                                            |\n");
        printf("   6- Listar de empleados                                                      \n");
        printf(" |                                                                            |\n");
        printf("   7- Ordenar empleados                                                        \n");
        printf(" |                                                                            |\n");
        printf("   8- Guardar datos de los empleados en el archivo data.csv (modo texto)       \n");
        printf(" |                                                                            |\n");
        printf("   9- Guardar datos de los empleados en el archivo data.bin (modo binario)     \n");
        printf(" |                                                                            |\n");
        printf("   10- Salir                                                                   \n");
        printf(" |                                                                            |\n");
        printf(" ==============================================================================\n");
        printf("                                                                               \n");
        printf(" Ingrese una opcion del menu: ");
        fflush(stdin);
        gets(valOpcion);

        opcion = validarEntero(valOpcion);

        switch(opcion)
        {
        case 1:
            printf("\n");
            if(flagBin == 0 && flagUno == 0)
            {
                controller_loadFromText("data.csv",listaEmpleados);
                flagText =  1;
                flagUno = 1;
            }
            else
            {
                printf(" Solo se puede cargar un archivo\n");
            }
            break;
        case 2:
            printf("\n");
            if(flagText == 0 && flagUno == 0)
            {
                controller_loadFromBinary("data.bin",listaEmpleados);
                flagBin = 1;
                flagUno = 1;
            }
            else
            {
                printf(" Solo se puede cargar un archivo\n");
            }
            break;
        case 3:
            printf("\n");
            if(flagText == 1 || flagBin == 1)
            {
                controller_addEmployee(listaEmpleados);
            }
            else
            {
                printf(" Primero debe cargar el archivo\n");
            }
            break;
        case 4:
            printf("\n");
            if(flagText == 1 || flagBin == 1)
            {
                if(ll_len(listaEmpleados)==0)
                {
                    printf(" No hay ningun empleado\n");
                }
                else
                {
                    controller_editEmployee(listaEmpleados);
                }
            }
            else
            {
                printf(" Primero debe cargar el archivo\n");
            }
            break;
        case 5:
            printf("\n");
            if(flagText == 1 || flagBin == 1)
            {
                if(ll_len(listaEmpleados)==0)
                {
                    printf(" No hay ningun empleado que mostrar\n");
                }
                else
                {
                    controller_removeEmployee(listaEmpleados);
                }
            }
            else
            {
                printf(" Primero debe cargar el archivo\n");
            }
            break;
        case 6:
            printf("\n");
            if(flagText == 1 || flagBin == 1)
            {
                if(ll_len(listaEmpleados)==0)
                {
                    printf(" No hay ningun empleado que mostrar\n");
                }
                else
                {
                    controller_ListEmployee(listaEmpleados);
                }
            }
            else
            {
                printf(" Primero debe cargar el archivo\n");
            }
            break;
        case 7:
            printf("\n");
            if(flagText == 1 || flagBin == 1)
            {
                if(ll_len(listaEmpleados)==0)
                {
                    printf(" No hay ningun empleado que mostrar\n");
                }
                else
                {
                    controller_sortEmployee(listaEmpleados);
                }
            }
            else
            {
                printf(" Primero debe cargar el archivo\n");
            }
            break;
        case 8:
            printf("\n");
            if(flagText == 1 || flagBin == 1)
            {
                controller_saveAsText("data.csv",listaEmpleados);
            }
            else
            {
                printf(" Primero debe cargar el archivo\n");
            }
            break;
        case 9:
            printf("\n");
            if(flagText == 1 || flagBin == 1)
            {
                controller_saveAsBinary("data.bin",listaEmpleados);
            }
            else
            {
                printf(" Primero debe cargar el archivo\n");
            }
            break;
        case 10:
            system("cls");
            seguir = 'n';
            printf(" ==============================================================================\n");
            printf(" #                              Saliendo...                                   #\n");
            ll_deleteLinkedList(listaEmpleados);

            break;
        default:
            printf("\n\n");
            printf(" ERROR. Esta opcion no es correcta\n");
        }

        fflush(stdin);
        printf(" Presione ENTER para continuar");
        getchar();
    }
    while(seguir == 's');

    return 0;
}
