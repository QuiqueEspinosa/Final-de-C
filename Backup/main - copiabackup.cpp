#include<iostream>
#include<stdio.h>
#include <string.h>
#include <stdlib.h> 

char sNombre[]="C:/Users/Ferrez/projects/FinalLenguaje/archivo.txt";

struct articulos{
	int orden;
	char idarticulo[30];
	char descripcion[30];
	float costo;
	char tipo[30];
	int anio;
	float precio_venta;
};

articulos art[3];

void leerArchivo();
void mostrar();

int main (int argc, char *argv[]) {
	//articulos art[3];
	leerArchivo();
	mostrar();
	return 0;
}


/**Funcion para leer el archivo generado*/  
void leerArchivo(){
	char delimitador[] = ";";
	char aux[7][30];
	char linea[255];//buffer en el cual leer el archivo
	FILE *manejador_archivo = NULL;
	manejador_archivo = fopen(sNombre, "r");
	if(manejador_archivo == NULL ) {
		printf("No fue posible abrir el archivo\n");
		return;
	}
	while (!feof(manejador_archivo)){
		fscanf(manejador_archivo, "%s", linea);
		char *token = strtok(linea, delimitador);
		int i=0;
		if(token != NULL){  
			while(token!=NULL){
			//printf("%s\n", token);
			//art[0].orden = (int) token;
			// Sólo en la primera pasamos la cadena; en las siguientes pasamos NULL
				//Asignamos el Nro de orden
			/* token = strtok(NULL, ";");
			if (token != NULL) {
				art[i].orden = atoi(token);
			} */
			//art[0].idarticulo = strtok(NULL, delimitador);
			//art[0].descripcion = strtok(NULL, delimitador);
			//art[0].costo = strtok(NULL, delimitador);
			//art[0].anio = strtok(NULL, delimitador);
			//art[0].precio_venta = strtok(NULL, delimitador);
			//strcpy(aux[i], token);
			//aux[i] = token;
			strcpy(aux[i],token);
			//printf("%s\n", token);
			token = strtok(NULL, delimitador);
			i++;
			}
		
			art[0].orden =  atoi(aux[0]);
			printf("%d\n",(art[0].orden));
			strcpy(art[0].idarticulo,aux[1]);
			printf("%s\n",art[0].idarticulo);
			strcpy(art[0].descripcion, aux[2]);
			printf("%s \n",art[0].descripcion);
			art[0].costo = atof (aux[3]);
			printf("%f \n",art[0].costo);
			strcpy(art[0].tipo, aux[4]);
			printf("%s \n",art[0].tipo);
			art[0].anio =  atoi(aux[5]);
			printf("%d \n",art[0].anio);
			art[0].precio_venta =  atof(aux[6]);
			printf("%f \n",art[0].precio_venta);
			
			for(int j=0;j<=6;j++){
				//printf("%i \n",art[j].orden);
				//printf("%s \n",art[j].idarticulo);
				//printf("%s \n",aux[j]);
	
			}
			printf("\n");
		}
		}
}
	
	
	
/** Funcion para  ordenar por anio el array */
	/* int ordenar_anio(articulos art, int cantidad)
	{	int i;
		int j;
		articulos aux;
		int movimientos;
		movimientos = 0;
		for (int i = 0; i < cantidad - 1; i++)
		{
			for (j = 1; j < cantidad; j++)
			{
				if (art[j].anio < art[j-1].anio)
				{   // si el elemento anterior es mayor, hacemos el cambio
					aux = art[j];
					art[j] = art[j-1];
					art[j-1] = aux_elem;
					movimientos++;
				}
			}
		}
		return movimientos;
	} */
	/** Funcion Que muestra el archivo */
	
	void mostrar(){
		printf("probando si llega");
		printf("%i \n", art[0].orden);
		printf("%s\n", art[0].idarticulo);
		printf("%s \n", art[0].descripcion);
	}
	
