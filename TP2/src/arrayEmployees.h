/*
 * arrayEmployees.h
 *
 *  Created on: 22 sept. 2020
 *      Author: Ale
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;

}eEmployee;


/**
 * \brief: Funcion principal del programa.
 * \return: retorna 0.
 */
int listEmployees();

/**
 * \brief: inicia los indices de la estructura en TRUE para decir que no hay empleados en los indices
 * \param: employees toma el array de empleados
 * \param: len toma la cantidad de indices del array
 * \return: retorna 0.
 */
int initEmployee(eEmployee employees[], int len);

/**
 * \brief: toma todos los datos ingresados en la estructura
 * \param: employees toma el array de empleados
 * \param: len toma la cantidad de indices en el array
 * \param: id toma el id generado automaticamente
 * \param: name toma el nombre del empleado ingresado
 * \param: lastName toma el apellido del empleado ingresado
 * \param: salary toma el salario del empleado ingresado.
 * \param: sector toma el sector del empleado ingresado
 * \return: retorna -1 si hay un error al cargar los empleados y 1 si los cargo correctamente
 */
int addEmployee(eEmployee employees[], int len, int id, char name[], char lastName[], float salary, int sector);

/**
 * \brief: imprime en pantalla la lista de empleados
 * \param: employees toma el array de empleados
 * \param: len toma la cantidad de indices en el array
 * \return: retorna 0.
 */
int printEmployees(eEmployee employees[], int len);

/**
 * \brief: elimina de manera logica al empleado
 * \param: employees toma el array de empleados
 * \param: len toma la cantidad de indices en el array
 * \param: id toma el id del empleado que hay que eliminar
 * \return: retorna 0.
 */
int removeEmployee(eEmployee employees[], int len, int id);

/**
 * \brief: modifica los datos de un empleado
 * \param: employees toma el array de empleados
 * \param: len toma la cantidad de indices del array
 * \param: id toma el id del empleado que queres modificar
 * \return: retorna 0
 */
int modifyEmployeeByID(eEmployee employees[], int len, int id);

/**
 * \brief: busca un empleado por id
 * \param: employees toma el array de empleados
 * \param: len toma la cantidad de indices en el array
 * \param: id es el id del empleado que queres encontrar
 * \return: retorna el indice en donde estab el empleado
 */
int findEmployeeByID(eEmployee employees[], int len, int id);
/**
 * \brief: ordena la lista de empleados alfabeticamente y por sector
 * \param: employees toma el array de empleados
 * \param: len toma la cantidad de indices en el array
 * \return: retorna 0
 */
int sortEmployees(eEmployee employees[], int len);

/**
 * \brief: es la funcion que se encarga de tomar la opcion escogida en el mnenu de informes
 * \param: employees toma el array de empleados
 * \param: len toma la cantidad de indices en el array
 * \return: retorna 0
 */
int listInformes(eEmployee employees[], int len);





#endif /* ARRAYEMPLOYEES_H_ */
