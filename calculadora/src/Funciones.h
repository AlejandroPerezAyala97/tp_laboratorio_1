/*
 * Funciones.h
 *
 *  Created on: 7 sept. 2020
 *      Author: Ale
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

/**
 * \brief: Menu de opciones.
 * \return: Retorna la opcion escogida.
 */
int menu(void);

/**
 * \brief: contiene el switch encargado de realizr todas las llamadas de las funciones.
 * \return: retorna 0.
 */
int Calculadora(void);

/**
 * \brief: toma los numeros ingresados y los suma.
 * \param: primerNumero toma el primer valor ingresado
 * \param: segundoNumero toma el segundo valor ingresado.
 * \return: retorna el resultado de la suma.
 */
float sumar(float primerNumero, float segundoNumero);

/**
 * \brief: toma los numeros ingresados y los resta.
 * \param: primerNumero toma el primer valor ingresado
 * \param: segundoNumero toma el segundo valor ingresado.
 * \return: retorna el resultado de la resta.
 */
float restar(float primerNumero, float segundoNumero);

/**
 * \brief: toma los numeros ingresados y los divide.
 * \param: primerNumero toma el primer valor ingresado
 * \param: segundoNumero toma el segundo valor ingresado.
 * \return: retorna el resultado de la division.
 */
float dividir(float primerNumero, float segundoNumero);


/**
 * \brief: toma los numeros ingresados y los multiplica.
 * \param: primerNumero toma el primer valor ingresado
 * \param: segundoNumero toma el segundo valor ingresado.
 * \return: retorna el resultado de la multiplicacion.
 */
float multiplicar(float primerNumero, float segundoNumero);


/**
 * \brief: toma el valor ingresado y calcula el factorial.
 * \param: numeroIngresado toma el valor ingresado.
 * \return: retorna el resultado del factorial.
 */
float factorial(float numeroIngresado);

/**
 * \brief: incorpora una animacion al momento de realizar los calculos.
 * \return: retorna 0.
 */
int animacionFunciones(float primerNumero, float segundoNumero);

/**
 * \brief: toma todos los datos de los calculos y realiza la muestra de los resultados.
 * \param: primerNumero toma el primer valor ingresado
 * \param: segundoNumero toma el segundo valor ingresado.
 * \param: suma toma el resultado de la suma.
 * \param: resta toma el resultado de la resta.
 * \param: division toma el resultado de la division.
 * \param: multiplicacion toma el resultado de la multiplicacion.
 * \param: primerFactorial toma el resultado del factorial del primer valor ingresado.
 * \param: segundoFactorial toma el resultado del factorial del segundo valor ingresado.
 * \return: retorna 0 ya que solo realiza la muestra de los resultados en pantalla.
 */
int mostrarResultados(float primerNumero, float segundoNumero, float suma, float resta, float division, float multiplicacion, float primerFactorial, float segundoFactorial);




#endif /* FUNCIONES_H_ */
