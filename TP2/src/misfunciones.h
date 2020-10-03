/*
 * misfunciones.h
 *
 *  Created on: 27 sept. 2020
 *      Author: Ale
 */

#ifndef MISFUNCIONES_H_
#define MISFUNCIONES_H_


/**
 * \brief: Agrega un menu de opciones al programa
 * \return: retorna 0
 */
int menu();

/**
 * \brief: Agrega un menu a la opcion de informes
 * \return: retorna 0
 */
int menuInformes();

/**
 * \brief: toma una cadena de caracteres y le modifica las primeras letras para que sean mayuscula.
 * \param: cadena es el string ingresado
 * \return: retorna 0
 */
int modificarPrimerLetra(char cadena[]);

/**
 * \brief: toma la cadena de caracteres y ve si hay un salte de linea y lo modifica(se utiliza con fgets)
 * \param: cadena es el string ingresado
 * \return: retorna 0
 */
int formateoCadena(char cadena[]);

/**
 * \brief: pide ingresar un valor del tipo flotante
 * \param: mensaje es para escribir lo que quieras que se vea en pantalla
 * \return: retorna el valor del tipo flotante ingresado
 */
float getFloat(char mensaje[]);

/**
 * \brief: pide ingresar un dato del tipo entero.
 * \param: mensaje es para escribir lo que quieras que se imprima en pantalla
 * \return: retorna el dato de tipo entero
 */
int getInt(char mensaje[]);

/**
 * \brief: pide un caracter
 * \param: mensaje es para escribir lo que quieras que se imprima en pantalla
 * \return: retorna el caracter
 */
char getChar(char mensaje[]);

/**
 * \brief: verifica si la cadena ingresada tiene numeros
 * \param: str toma el string ingresado
 * \return: retorna 0 si no es numerico y 1 si es numerico
 */
int esNumerico(char str[]);

/**
 * \brief: verifica si la cadena ingresada tiene letras
 * \param: str toma el string ingresado
 * \return: retorna 0 si no es letras y 1 si es letras
 */
int esSoloLetras(char str[]);

/**
 * \brief: toma el string ingresado y verifica si contiene solo letras
 * \param: mensaje es para poner lo que queres que se imprima en pantalla
 * \param: input es el string ingresado
 * \param: mensajeError es para colocar lo que queres que imprima en pantalla si el string contiene algo que no sean letras
 * \return: retorna el resultado de la multiplicacion.
 */
int getStringLetras(char mensaje[],char input[], char mensajeError[]);

/**
 * \brief: toma el string ingresado y verifica si contiene solo numeros.
 * \param: mensaje es para poner lo que queres que se imprima en pantalla
 * \param: input es el string ingresado
 * \param: mensajeError es para colocar lo que queres que imprima en pantalla si el string contiene algo que no sean letras
 * \return: retorna el resultado de la multiplicacion.
 * */
int getStringNumeros(char mensaje[],char input[], char mensajeError[]);

/**
 * \param: agrega una animacion al programa
 * \return: retorna 0;
 */

int animacionFunciones();

/**
 * \brief: busca si hay indices vacion en el array de empleados
 * \param: employees
 * \param: segundoNumero toma el segundo valor ingresado.
 * \return: retorna el resultado de la multiplicacion.
 */
int findEmpty(eEmployee employees[], int len);

/**
 * \brief: toma los numeros ingresados y los multiplica.
 * \param: primerNumero toma el primer valor ingresado
 * \param: segundoNumero toma el segundo valor ingresado.
 * \return: retorna el resultado de la multiplicacion.
 */
int loadEmployee(eEmployee employees[], int len, int id);

/**
 * \brief: toma los numeros ingresados y los multiplica.
 * \param: primerNumero toma el primer valor ingresado
 * \param: segundoNumero toma el segundo valor ingresado.
 * \return: retorna el resultado de la multiplicacion.
 */
int printEmployee(eEmployee employee);

/**
 * \brief: toma los numeros ingresados y los multiplica.
 * \param: primerNumero toma el primer valor ingresado
 * \param: segundoNumero toma el segundo valor ingresado.
 * \return: retorna el resultado de la multiplicacion.
 */
int newName(eEmployee employees[], int len, int id);

/**
 * \brief: toma los numeros ingresados y los multiplica.
 * \param: primerNumero toma el primer valor ingresado
 * \param: segundoNumero toma el segundo valor ingresado.
 * \return: retorna el resultado de la multiplicacion.
 */
int newLastName(eEmployee employees[], int len, int id);

/**
 * \brief: toma los numeros ingresados y los multiplica.
 * \param: primerNumero toma el primer valor ingresado
 * \param: segundoNumero toma el segundo valor ingresado.
 * \return: retorna el resultado de la multiplicacion.
 */
int newSalary(eEmployee employees[], int len, int id);

/**
 * \brief: toma los numeros ingresados y los multiplica.
 * \param: primerNumero toma el primer valor ingresado
 * \param: segundoNumero toma el segundo valor ingresado.
 * \return: retorna el resultado de la multiplicacion.
 */
int newSector(eEmployee employees[], int len, int id);

int menuModificaciones();

/**
 * \brief: toma los numeros ingresados y los multiplica.
 * \param: primerNumero toma el primer valor ingresado
 * \param: segundoNumero toma el segundo valor ingresado.
 * \return: retorna el resultado de la multiplicacion.
 */
int sumaSalary(eEmployee employees[], int len);

/**
 * \brief: toma los numeros ingresados y los multiplica.
 * \param: primerNumero toma el primer valor ingresado
 * \param: segundoNumero toma el segundo valor ingresado.
 * \return: retorna el resultado de la multiplicacion.
 */
int countEmployee(eEmployee employees[], int len);

int promedioSalary(eEmployee employees[], int len);

int countExceededAverage(eEmployee employees[], int len);

int printPromedios(eEmployee employees[], int len);

int showListExceedAverage(eEmployee employees[], int len);





#endif /* MISFUNCIONES_H_ */
