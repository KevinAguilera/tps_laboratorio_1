#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "aguilera.h"


int main()
{

    int opcion;
    char seguir = 's';
    char confirma;
    float operandoA;
    float operandoB;
    int flagA = 0;
    int flagB = 0;
    int flagC = 0;

    do
    {
        system("cls");
        printf("MENU DE OPCIONES\n\n");
        if(flagA == 1)
        {
            printf("1- Ingresar primer Operando (A=%.2f)\n",operandoA);
        }
        else
        {
            printf("1- Ingresar primer Operando (A=x)\n");
        }
        if(flagB == 1)
        {
            printf("2- Ingresar segundo Operando (B=%.2f)\n",operandoB);
        }
        else
        {
            printf("2- Ingresar segundo Operando (B=y)\n");
        }
        printf("3- Calcular todas las operaciones\n");
        printf("4- Informar resultados\n");
        printf("5- Salir\n\n");
        printf("Ingrese una opcion del menu: ");
        fflush(stdin);
        scanf("%d",&opcion);


        switch(opcion)
        {
        case 1:
            operandoA = ingresarNumero();
            flagA = 1;
            break;

        case 2:
            operandoB = ingresarNumero();
            flagB = 1;
            break;

        case 3:
            if (flagA == 1 && flagB == 1)
            {
                flagC = 1;
                system("cls");
                printf("Calculando la suma de %.2f + %.2f...\n",operandoA,operandoB);
                printf("Calculando la resta de %.2f - %.2f...\n",operandoA,operandoB);
                printf("Calculando la multiplicacion de %.2f * %.0f...\n",operandoA,operandoB);
                printf("Calculando la division de %.2f / %.2f...\n",operandoA,operandoB);
                printf("Calculando el factorial de %.2f! y %.2f!...\n\n",operandoA,operandoB);
                printf("Ya puede ver los resultados!\n");
            }
            else
            {
                printf("Primero debe ingresar los operandos!\n");
            }
            break;

        case 4:
            if(flagA == 1 && flagB == 1 && flagC == 1)
            {
                system("cls");
                printf("El resultado de A+B es: %.2f\n", sumar(operandoA,operandoB));
                printf("El resultado de A-B es: %.2f\n", restar(operandoA,operandoB));
                printf("El resultado de A*B es: %.2f\n", multiplicar(operandoA,operandoB));
                dividir(operandoA,operandoB);
                factorial(operandoA,operandoB);
            }
            else
            {
                printf("Primero debe calcular las operaciones!\n");
            }
            break;

        case 5:
            printf("Confirma salida?: ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's')
            {
                seguir = 'n';
            }
            break;

        default:
            printf("Opcion invalida!!\n\n");
            break;
        }
        printf("\n");
        printf("Presione una tecla para continuar");
        getch();
    }

    while(seguir == 's');

    return 0;
}
