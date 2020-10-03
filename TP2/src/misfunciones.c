/*
 * misfunciones.c
 *
 *  Created on: 27 sept. 2020
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



/*  ------------------------------------------------------------------------------------------------------------------------
 * |																														|
 * |*********************************************MENUS Y ANIMACIONES********************************************************|
 * |																														|
 *  ------------------------------------------------------------------------------------------------------------------------
 * */

int menu()
{
	int opcion;

	system("cls");

	printf("\n ______________________________________________");
	printf("\n|                                              |");
	printf("\n|************LISTA DE EMPLEADOS****************|");
	printf("\n|______________________________________________|\n");


	printf("\n[1]- Alta Empleado ");
	printf("\n[2]- Modificar Empleado ");
	printf("\n[3]- Baja Empleado ");
	printf("\n[4]- Informes");
	printf("\n[5]- Salir");
	printf("\nSeleccione una de las opciones: ");
	scanf("%d", &opcion);


	return opcion;

}


int animacionFunciones()
{
	system("cls");

	printf("\n ___________________________________");
	printf("\n|                                   |");
	printf("\n|--------Cambiando el Nombre--------|");
	Sleep(2000);
	printf("\n|----------Cargando = 25%%-----------|");
	Sleep(2000);
	printf("\n|----------Cargando = 50%%-----------|");
	Sleep(2000);
	printf("\n|----------Cargando = 75%%-----------|");
	Sleep(2000);
	printf("\n|----------Cargando = 100%%----------|");
	Sleep(2000);
	printf("\n|-----Cambio de nombre relizado!----|");
	printf("\n|___________________________________|\n");


	return 0;

}

int menuModificaciones()
{
	int opcion;



	printf("\n ______________________________________________");
	printf("\n|                                              |");
	printf("\n|***************MODIFICACIONES*****************|");
	printf("\n|______________________________________________|\n");


	printf("\n[1]- Modificar Nombre ");
	printf("\n[2]- Modificar Apellido ");
	printf("\n[3]- Modificar Salario ");
	printf("\n[4]- Modificar Sector");
	printf("\n[5]- Salir");
	printf("\nSeleccione una de las opciones: ");
	scanf("%d", &opcion);


	return opcion;

}

int menuInformes()
{
	int opcion;



	printf("\n ______________________________________________");
	printf("\n|                                              |");
	printf("\n|**************LISTA DE INFORMES***************|");
	printf("\n|______________________________________________|\n");


	printf("\n[1]- Listado de los empleados ordenados alfabéticamente por Apellido y Sector ");
	printf("\n[2]- Total y promedio de los salarios, y cuántos empleados superan el salario promedio. ");
	printf("\n[3]- Salir");
	printf("\nSeleccione una de las opciones: ");
	scanf("%d", &opcion);


	return opcion;

}



/*  ------------------------------------------------------------------------------------------------------------------------
 * |																														|
 * |**********************************FUNCIONES DE CADENAS DE CARACTERES****************************************************|
 * |																														|
 *  ------------------------------------------------------------------------------------------------------------------------
 * */



int modificarPrimerLetra(char cadena[])
{
	int i;

	strlwr(cadena);
	cadena[0] = toupper(cadena[0]);

	for(i = 0; cadena[i] != '\0'; i++)
	{
		if(cadena[i] == ' ')
		{
			cadena[i + 1] = toupper(cadena[i + 1]);
		}
	}

	return 0;
}


int formateoCadena(char cadena[])
{
	int i;

	for(i = 0; cadena[i] != '\0'; i++)
	{
		if(cadena[i] == '\n')
		{
			cadena[i] = '\0';
		}
	}

	return 0;
}



/*  ------------------------------------------------------------------------------------------------------------------------
 * |																														|
 * |*************************************************INGRESO DE DATOS*******************************************************|
 * |																														|
 *  ------------------------------------------------------------------------------------------------------------------------
 * */


float getFloat(char mensaje[])
{
    float auxiliar;
    printf("%s",mensaje);
    scanf("%f",&auxiliar);
    return auxiliar;
}


int getInt(char mensaje[])
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}

void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    fflush(stdin);
    fgets(input, 51, stdin);
}

char getChar(char mensaje[])
{
    char auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&auxiliar);
    return auxiliar;
}


/*  ------------------------------------------------------------------------------------------------------------------------
 * |																														|
 * |*************************************************VALIDACIONES***********************************************************|
 * |																														|
 *  ------------------------------------------------------------------------------------------------------------------------
 * */

int esNumerico(char str[])
{
   int i;
   int allOK;
   int longitud;

   longitud = strlen(str)-1;

   for(i = 0; i < longitud; i++)
   {
	   if(isdigit(str[i]) || str[i] == '.')
	   {
		   allOK = TRUE;
	   }
	   else
	   {
		   allOK = FALSE;
		   break;
	   }
   }

   return allOK;
}


int esSoloLetras(char str[])
{
   int i;
   int allOK;
   int longitud;

   longitud = strlen(str)-1;

   for(i = 0; i < longitud; i++)
   {
	   if(isalpha(str[i]) || str[i] == ' ')
	   {
		   allOK = TRUE;
	   }
	   else
	   {
		   allOK = FALSE;
		   break;
	   }
   }
   return allOK;
}


/*  ------------------------------------------------------------------------------------------------------------------------
 * |																														|
 * |*******************************************INPUTS CON VALIDACIONES******************************************************|
 * |																														|
 *  ------------------------------------------------------------------------------------------------------------------------
 * */


int getStringLetras(char mensaje[],char input[], char mensajeError[])
{
    char aux[256];
    int allOK;

    allOK = FALSE;

    getString(mensaje,aux);

    while(!esSoloLetras(aux))
    {
    	printf(mensajeError);
    	fflush(stdin);
    	fgets(aux, sizeof(aux), stdin);
    }
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        allOK = TRUE;
    }
    return allOK;
}


int getStringNumeros(char mensaje[],char input[], char mensajeError[])
{
    char aux[256];
    int allOK;

    allOK = FALSE;

    getString(mensaje,aux);

    while(!esNumerico(aux))
    {
    	printf(mensajeError);
    	fflush(stdin);
    	fgets(aux, sizeof(aux), stdin);
    }
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        allOK = TRUE;
    }
    return allOK;
}

/*  ------------------------------------------------------------------------------------------------------------------------
 * |																														|
 * |**********************************************MUESTREO DE DATOS*********************************************************|
 * |																														|
 *  ------------------------------------------------------------------------------------------------------------------------
 * */

int printEmployee(eEmployee employee)
{
	printf("%d      %-10s    %-10s    %.2f    %2d\n", employee.id, employee.name, employee.lastName, employee.salary, employee.sector);

	return 0;
}


int printPromedios(eEmployee employees[], int len)
{
	float salarios;
	float promedio;
	int contador;

	salarios = sumaSalary(employees, len);
	promedio = promedioSalary(employees, len);
	contador = countExceededAverage(employees, len);

	printf("La suma de los salarios es: %f\n", salarios);
	printf("El promedio de los salarios es: %f\n", promedio);
	printf("La cantidad de empleados que superan el promedio es: %d y son: \n\n", contador);

	printf("----------------------------------------------------------------------------------\n\n");

	showListExceedAverage(employees, len);

	return 0;

}

int showListExceedAverage(eEmployee employees[], int len)
{
	int flag;
	float promedio;

	promedio = promedioSalary(employees, len);
	flag = FALSE;

	printf("ID       NOMBRE      APELLIDO     SALARIO     SECTOR\n");

	printf("----------------------------------------------------------------------------------\n\n");

	for(int i = 0; i < len; i++){
			if (employees[i].salary > promedio && employees[i].isEmpty == FALSE){
				printEmployee(employees[i]);
				flag = TRUE;
			}
		}

		if(flag == FALSE){
			printf("no hay empleados que superen el promedio de sueldo\n\n");
		}

		return 0;
}


/*  ------------------------------------------------------------------------------------------------------------------------
 * |																														|
 * |**********************************************BUSQUEDAS DE INDICE LIBRE*************************************************|
 * |																														|
 *  ------------------------------------------------------------------------------------------------------------------------
 * */


int findEmpty(eEmployee employees[], int len)
{
	int i;
	int index;

	index = -1;

	for(i = 0; i < len; i++)
	{
		if(employees[i].isEmpty == TRUE)
		{
			index = i;
			break;
		}
	}


	return index;
}


/*  ------------------------------------------------------------------------------------------------------------------------
 * |																														|
 * |******************************************CARGA DE DATOS EN ESTRUCRURA**************************************************|
 * |																														|
 *  ------------------------------------------------------------------------------------------------------------------------
 * */

int loadEmployee(eEmployee employees[], int len, int id)
{
	int flagID;
	char name[51];
	char lastName[51];
	char auxSalary[51];
	float salary;
	int sector;
	int i;

	flagID = FALSE;
	i = findEmpty(employees, len);


	if(i != -1)
	{
		getStringLetras("\nIngrese el nombre del empleado: ", name, "Solo debe ingresar nombres con letras: ");
		formateoCadena(name);
		modificarPrimerLetra(name);

		getStringLetras("Ingrese el apellido del empleado: ", lastName, "Solo debe ingresar apellidos con letras: ");
		formateoCadena(lastName);
		modificarPrimerLetra(lastName);

		getStringNumeros("Ingrese el salario del empleado: ", auxSalary, "Solo debe ingresar salarios con numeros: ");

		salary = atof(auxSalary);

		sector = getInt("Ingrese el sector del empleado: ");

		if(addEmployee(employees, len, id, name, lastName, salary, sector))
		{
			flagID = TRUE;
		}


	}
	else
	{
		printf("System Complete!!\n");
	}

	return flagID;
}




/*  ------------------------------------------------------------------------------------------------------------------------
 * |																														|
 * |**********************************FUNCIONES DE REEMPLAZO DE DATOS EN ESTRUCTURAS****************************************|
 * |																														|
 *  ------------------------------------------------------------------------------------------------------------------------
 * */


int newName(eEmployee employees[], int len, int id)
{
	int index;
	char newName[51];
	char confirm;

	index = findEmployeeByID(employees, len, id);


	getStringLetras("Ingrese el nuevo nombre: ", newName, "Error!! coloque el nombre solo con letras: ");
	formateoCadena(newName);
	modificarPrimerLetra(newName);

	confirm = getChar("¿Confirma el cambio de nombre? [s/n]: ");
	while(confirm != 's' && confirm != 'n')
	{
		confirm = getChar("Error!!! Debes poner una s (si confirmas) o n (si cancelas): ");
	}

	if(confirm == 's')
	{
		strcpy(employees[index].name, newName);
		printf("Se realizo el cambio con exito!\n");
	}
	else
	{
		printf("Operacion cancelada!\n");
	}

	return 0;
}

int newLastName(eEmployee employees[], int len, int id)
{
	int index;
	char newLastName[51];
	char confirm;

	index = findEmployeeByID(employees, len, id);


	getStringLetras("Ingrese el nuevo apellido: ", newLastName, "Error!! coloque el apellido solo con letras: ");
	formateoCadena(newLastName);
	modificarPrimerLetra(newLastName);

	confirm = getChar("¿Confirma el cambio de apellido? [s/n]: ");
	while(confirm != 's' && confirm != 'n')
	{
		confirm = getChar("Error!!! Debes poner una s (si confirmas) o n (si cancelas): ");
	}

	if(confirm == 's')
	{
		strcpy(employees[index].lastName, newLastName);
		printf("Se realizo el cambio con exito!\n");
	}
	else
	{
		printf("Operacion cancelada!\n");
	}

	return 0;
}

int newSalary(eEmployee employees[], int len, int id)
{
	int index;
	float newSalary;
	char auxNewSalary[50];
	char confirm;

	index = findEmployeeByID(employees, len, id);


	getStringNumeros("Ingrese el nuevo salario: ", auxNewSalary, "Solo debe ingresar salarios con numeros: ");
	newSalary = atof(auxNewSalary);

	confirm = getChar("¿Confirma el cambio de salario? [s/n]: ");
	while(confirm != 's' && confirm != 'n')
	{
		confirm = getChar("Error!!! Debes poner una s (si confirmas) o n (si cancelas): ");
	}

	if(confirm == 's')
	{
		employees[index].salary = newSalary;
		printf("Se realizo el cambio con exito!\n");
	}
	else
	{
		printf("Operacion cancelada!\n");
	}

	return 0;
}

int newSector(eEmployee employees[], int len, int id)
{
	int index;
	int newSector;
	char confirm;

	index = findEmployeeByID(employees, len, id);

	newSector = getInt("Ingrese el nuevo sector del empleado: ");

	confirm = getChar("¿Confirma el cambio de sector? [s/n]: ");
	while(confirm != 's' && confirm != 'n')
	{
		confirm = getChar("Error!!! Debes poner una s (si confirmas) o n (si cancelas): ");
	}

	if(confirm == 's')
	{
		employees[index].sector = newSector;
		printf("Se realizo el cambio con exito!\n");
	}
	else
	{
		printf("Operacion cancelada!\n");
	}

	return 0;
}



/*  ------------------------------------------------------------------------------------------------------------------------
 * |																														|
 * |***************************************CONTADOR, ACUMULADOR, PROMEDIO***************************************************|
 * |																														|
 *  ------------------------------------------------------------------------------------------------------------------------
 * */


int countEmployee(eEmployee employees[], int len)
{
	int i;
	int contador;

	contador = 0;

	for(i = 0; i < len; i++)
	{
		if(employees[i].isEmpty == FALSE)
		{
			contador++;
		}
	}

	return contador;
}



int sumaSalary(eEmployee employees[], int len)
{
	int i;
	float suma;

	suma = 0;

	for(i = 0; i < len; i++)
	{
		if(employees[i].isEmpty == FALSE)
		{
			suma += employees[i].salary;
		}
	}

	return suma;
}


int promedioSalary(eEmployee employees[], int len)
{
	float promedio;
	float suma;
	int contador;

	suma = sumaSalary(employees, len);
	contador = countEmployee(employees, len);

	promedio = suma / contador;

	return promedio;
}

int countExceededAverage(eEmployee employees[], int len)
{
	int i;
	float promedio;
	int contador;

	promedio = promedioSalary(employees, len);
	contador = 0;

	for(i = 0; i < len; i++)
	{
		if(employees[i].isEmpty == FALSE && employees[i].salary > promedio)
		{
			contador ++;
		}
	}

	return contador;
}

