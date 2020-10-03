/*
 * arrayEmployees.c
 *
 *  Created on: 22 sept. 2020
 *      Author: Ale
 */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>
#include "arrayEmployees.h"
#include "misfunciones.h"

#define LEN 3
#define TRUE 1
#define FALSE 0

int initEmployee(eEmployee employees[], int len)
{
	int i;

	for(i = 0; i < len; i++)
	{
		employees[i].isEmpty = TRUE;
	}

	return 0;
}


int findEmployeeByID(eEmployee employees[], int len, int id)
{
	int i;
	int index;

	index = -1;

	for(i = 0; i < len; i++)
	{
		if(employees[i].id == id && employees[i].isEmpty == FALSE)
		{
			index = i;
			break;
		}
	}

	return index;
}



int listEmployees()
{
	int salir;
	int nextID;
	int ID;
	eEmployee employees[LEN];

	nextID = 1;
	salir = TRUE;

	initEmployee(employees, LEN);

	do
	{
		switch(menu())
		{
			case 1:
				if(loadEmployee(employees, LEN, nextID))
				{
					nextID ++;
				}
				break;
			case 2:
				ID = getInt("Ingrese el ID del empleado que quiere modificar: ");
				modifyEmployeeByID(employees, LEN, ID);
				break;
			case 3:
				ID = getInt("Ingrese el ID del empleado que quiere dar de BAJA: ");
				removeEmployee(employees, LEN, ID);
				break;
			case 4:
				listInformes(employees, LEN);
				break;
			case 5:
				printf("gracias por salir\n");
				salir = FALSE;
				break;
			default:
				printf("ingrese una opcion valida\n");
		}


		system("pause");

	} while(salir == TRUE);


	return 0;
}

int addEmployee(eEmployee employees[], int len, int id, char name[], char lastName[], float salary, int sector)
{
	int allOk;
	int i;
	eEmployee auxEmployee;

	allOk = FALSE;
	i = findEmpty(employees, len);

	if(i != -1 )
	{
		auxEmployee.id = id;
		strcpy(auxEmployee.name, name);
		strcpy(auxEmployee.lastName, lastName);
		auxEmployee.salary = salary;
		auxEmployee.sector = sector;
		auxEmployee.isEmpty = FALSE;

		employees[i] = auxEmployee;

		sumaSalary(employees, len);
		countEmployee(employees, len);

		allOk = TRUE;
	}

	return allOk;
}


int printEmployees(eEmployee employees[], int len)
{
	int i;
	system("cls");

	printf("ID       NOMBRE      APELLIDO     SALARIO     SECTOR\n");


	for(i = 0; i < len; i++)
	{
		if(employees[i].isEmpty == FALSE)
		{
			printEmployee(employees[i]);
		}

	}

	return 0;
}

int removeEmployee(eEmployee employees[], int len, int id)
{
	int index;

	char confirm;

	index = findEmployeeByID(employees, len, id);

	if(index != -1)
	{
		printEmployee(employees[index]);
		confirm = getChar("\n¿Seguro que quiere dar de baja este empleado? [s/n]: ");
		while(confirm != 's' && confirm != 'n')
		{
			confirm = getChar("\nError!!!! Debes poner una s (si confirmas) o n (si cancelas): ");
		}

		if(confirm == 's')
		{
			employees[index].isEmpty = TRUE;
			printf("La baja se realizo con exito!!\n");
		}
		else
		{
			printf("Se cancelo la operacion!!\n");
		}
	}
	else
	{
		printf("No Existe un empleado con ese numero de ID!!\n");
	}

	return 0;
}


int modifyEmployeeByID(eEmployee employees[], int len, int id)
{
	int index;
	int salir;

	index = findEmployeeByID(employees, len, id);
	salir = TRUE;

	if(index != -1)
	{
		do
		{
			system("cls");
			printEmployee(employees[index]);

			switch(menuModificaciones())
			{
				case 1:
					newName(employees, len, id);
					break;
				case 2:
					newLastName(employees, len, id);
					break;
				case 3:
					newSalary(employees, len, id);
					break;
				case 4:
					newSector(employees, len, id);
					break;
				case 5:
					printf("Saliste de las modificaciones\n");
					salir = FALSE;
					break;
				default:
					printf("ingrese una opcion valida!\n");
			}

			getch();
		}while(salir == TRUE);


	}

	return 0;
}

int sortEmployees(eEmployee employees[], int len)
{
	eEmployee auxLastName;
	eEmployee auxSector;
	int i;
	int j;

	for(i = 0; i < len - 1; i ++)
	{
		for(j = i + 1; j < len; j++)
		{
			if(strcmp(employees[i].lastName, employees[j].lastName) > 0)
			{
				auxLastName = employees[i];
				employees[i] = employees[j];
				employees[j] = auxLastName;
			}

			if(((strcmp(employees[i].lastName, employees[j].lastName) == 0) && ((employees[i].sector > employees[j].sector) > 0)))
			{
				auxSector = employees[i];
				employees[i] = employees[j];
				employees[j] = auxSector;
			}


		}
	}

	return 0;
}

int listInformes(eEmployee employees[], int len)
{
	int salir = TRUE;


	do
	{
		system("cls");

		switch(menuInformes())
		{
			case 1:
				sortEmployees(employees, len);
				printEmployees(employees, len);
				break;
			case 2:
				printPromedios(employees, len);
				break;
			case 3:
				salir = FALSE;
				break;
			default:
				printf("ingrese una opcion valida!");
		}
		getch();
	}while(salir == TRUE);

	return 0;
}

