/**Ejemplo simple del empleo de funciones
*\n El proyecto esta compuesto por varios archivos
* @author adrian
* @version 1.1
* @date 20200810
*/
#include <stdio.h>
#include "cabecera.h"///Incluyo el archivo con el prototipo de las funciones

void mostrarMensaje();//prototipo de funci�n local

int cubo(int pValor);

int main(){
	char sMiSaludo[]="Mi saludo";
	int iValor = 3;
	mostrarMensaje();//invocaci�n de funci�n local
	mostraMensajeCabecera(); //invocaci�n de la funci�n externa
	mostrarParametro(sMiSaludo); //invocaci�n de funci�n y paso de parametro
	printf ("\nEl cubo de %d es %d",iValor,cubo(iValor));
	return 0;
}
	
/**Muestra un mensaje por pantalla*/	
void mostrarMensaje(){
	printf("\nHola desde la funcion");
}
	

/**Calcula el cubo de un numero entero
* @param pValor: numero sobre el cual operar
* @return int el parametro pValor elevado al cuadrado*/
int cubo(int pVAlor){
	int iResult = 0;
	iResult = pVAlor * pVAlor * pVAlor;
	return iResult;
}
	
