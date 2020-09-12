#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "aguilera.h"

float ingresarNumero()
{
    float valor;

    printf("Ingrese un numero: ");
    scanf("%f",&valor);

    return valor;
}

float sumar(float operandoA, float operandoB)
{
    float suma;

    suma = operandoA + operandoB;

    return suma;
}

float restar(float operandoA, float operandoB)
{
    float resta;

    resta = operandoA - operandoB;

    return resta;
}

float multiplicar(float operandoA, float operandoB)
{
    float multiplicacion;

    multiplicacion = operandoA * operandoB;

    return multiplicacion;
}

float dividir(float operandoA, float operandoB)
{
    float division;

    if(operandoB !=0)
    {
        division = operandoA / operandoB;

        printf("El resultado de A/B es: %.2f\n",division);
    }
    else
    {
        printf("No es posible dividir por cero.\n");
    }

    return division;
}


float factorial(float primerFactor, float segundoFactor)
{
    int factorUno = 1, factorDos = 1;

    if (primerFactor >= 0)
    {
        for (int i = primerFactor; i >= 1; i--)
        {
            factorUno = factorUno * i;
        }
        printf("El factorial de A! es: %.2d\n",factorUno);
    }
    else
    {
        printf("No se puede factorizar el primer operando porque es un numero negativo.\n");
    }

    if (segundoFactor >=0)
    {

        for (int i = 1; i <= segundoFactor; i++)
        {

            factorDos = factorDos * i;
        }
        printf("El factorial de B! es: %.2d\n",factorDos);
    }
    else
    {
        printf("No se puede factorizar el segundo operando porque es un numero negativo!\n");
    }

    return 0;
}
