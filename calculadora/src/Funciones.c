/*
 * Funciones.c
 *
 *  Created on: 7 sept. 2020
 *      Author: Ale
 */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include "Funciones.h"

#define TRUE 1
#define FALSE 0


int Calculadora(void)
{
	int salir;
	int primerFlag;
	int segundoFlag;
	int flagFunciones;
	char salida;
	float primerValor;
	float segundoValor;
	float suma;
	float resta;
	float division;
	float multiplicacion;
	float primerFactorial;
	float segundoFactorial;


	salir = FALSE;
	primerFlag = FALSE;
	segundoFlag = FALSE;
	flagFunciones = FALSE;

	do{
		switch(menu())
		{
			case 1:
				primerFlag = TRUE;
				printf("ingrese primer valor: ");
				scanf("%f", &primerValor);
				break;
			case 2:
				segundoFlag = TRUE;
				printf("ingrese segundo valor: ");
				scanf("%f", &segundoValor);
				break;
			case 3:
				if(primerFlag == TRUE && segundoFlag == TRUE)
				{
					flagFunciones = TRUE;
					suma = sumar(primerValor, segundoValor);
					resta = restar(primerValor, segundoValor);
					division = dividir(primerValor, segundoValor);
					multiplicacion = multiplicar(primerValor, segundoValor);

					if(primerValor > -1)
					{
						primerFactorial = factorial(primerValor);
					}

					if(segundoValor > -1)
					{
						segundoFactorial = factorial(segundoValor);
					}

					animacionFunciones(primerValor, segundoValor);
				}
				else
				{
					printf("\nFalta ingresar un valor!...\n");
				}


				break;
			case 4:
				if(flagFunciones == TRUE)
				{
					primerFlag = FALSE;
					segundoFlag = FALSE;
					flagFunciones = FALSE;
					mostrarResultados(primerValor, segundoValor, suma, resta, division, multiplicacion, primerFactorial, segundoFactorial);
				}
				else
				{
					printf("\nPara mostrar los resultados primero debe realizar las operaciones! (opcion 3)\n");
				}

				break;
			case 5:
				printf("Queres salir? s/n: ");
				fflush(stdin);
				scanf("%c", &salida);

				if(salida == 's'){
					printf("gracias por utilizar mi programa.\n");
					salir = TRUE;
				}
				break;
			default:
				printf("ingrese una opcion valida!!\n");
				break;
		}
		system("pause");
	} while(salir != TRUE);


	return 0;
}

int menu(void)
{
	int opcion;

	system("cls");

	printf("\n ______________________________________________");
	printf("\n|                                              |");
	printf("\n|**************CALCULADORA*********************|");
	printf("\n|______________________________________________|\n");


	printf("\n[1]- Ingresar el primer numero ");
	printf("\n[2]- Ingresar el segundo numero ");
	printf("\n[3]- Realizar los Calculos");
	printf("\n[4]- Mostrar Resultados");
	printf("\n[5]- Salir");
	printf("\nSeleccione una de las opciones: ");
	scanf("%d", &opcion);


	return opcion;

}

float sumar(float primerNumero, float segundoNumero)
{
	float resultado;

	resultado = primerNumero + segundoNumero;

	return resultado;

}

float restar(float primerNumero, float segundoNumero)
{
	float resultado;

	resultado = primerNumero - segundoNumero;

	return resultado;
}

float dividir(float primerNumero, float segundoNumero)
{
	float resultado;


	resultado = primerNumero / segundoNumero;


	return resultado;
}

float multiplicar(float primerNumero, float segundoNumero)
{
	float resultado;

	resultado = primerNumero * segundoNumero;

	return resultado;
}

float factorial(float numeroIngresado)
{
	float resultado;

	if(numeroIngresado == 0)
	{
		resultado = 1;
	}
	else
	{
		resultado = numeroIngresado * factorial(numeroIngresado - 1);
	}

	return resultado;
}

int animacionFunciones(float primerNumero, float segundoNumero)
{
	system("cls");

	printf("\n ___________________________________");
	printf("\n|                                   |");
	printf("\n|------[A]=%.2f---------[B]=%.2f----|", primerNumero, segundoNumero);
	Sleep(2000);
	printf("\n|--------Calculando la Suma---------|");
	Sleep(2000);
	printf("\n|--------Calculando la Resta--------|");
	Sleep(2000);
	printf("\n|-------Calculando la Division------|");
	Sleep(2000);
	printf("\n|----Calculando la Multiplicacion---|");
	Sleep(2000);
	printf("\n|-----Calculando los Factoriales----|");
	Sleep(2000);
	printf("\n|--------Resultados Listos!!--------|");
	printf("\n|___________________________________|\n");


	return 0;

}

int mostrarResultados(float primerNumero, float segundoNumero, float suma, float resta, float division, float multiplicacion, float primerFactorial, float segundoFactorial)
{
	system("cls");

		printf("\n ______________________________________________");
		printf("\n|                                              |");
		printf("\n|******************RESULTADOS******************|");
		printf("\n|______________________________________________|\n");

		printf("\nEl resultado de la suma es: %.2f", suma);
		printf("\nEl resultado de la resta es: %.2f", resta);
		printf("\nEl resultado de la multiplicacion es: %.2f", multiplicacion);

		if(segundoNumero != 0)
		{
			printf("\nEl resultado de la division es: %.2f", division);
		}
		else
		{
			printf("\nNo se puede dividir por 0!!!");
		}

		if(primerNumero > -1)
		{
			printf("\nEl resultado del primer factorial es: %.2f", primerFactorial);
		}
		else
		{
			printf("\nno se puede calcular el factorial de un numero negativo!!!");
		}

		if(segundoNumero > -1)
		{
			printf("\nEl resultado del segundo factorial es: %.2f\n", segundoFactorial);
		}
		else
		{
			printf("\nno se puede calcular el factorial de un numero negativo!!!\n");
		}

	return 0;
}
