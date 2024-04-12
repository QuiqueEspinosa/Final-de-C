#include <iostream>
#include <stdio.h>
#include <string.h>

//char sNombre[]="C:/Users/Quique/Desktop/trabajoLenguaje/archivo.csv";
char sNombre[]="archivo.csv";
struct articulos{
	int orden;
	char idarticulo[30];
	char descripcion[30];
	float costo;
	char tipo[30];
	int anio;
	float precio_venta;
};
articulos art[50];
int tamanio;



/**Funcion para leer el archivo generado*/  
void leerArchivo(){
	char delimitador[] = ";";
	int cont=0;
	char bandera='T';
	char aux[7][30];
	char linea[255];//buffer en el cual leer el archivo
	FILE *manejador_archivo = NULL;
	manejador_archivo = fopen(sNombre, "r");
	if(manejador_archivo == NULL ) {
		printf("No fue posible abrir el archivo\n");
		return;
	}
	int j=0;
	while (!feof(manejador_archivo)){
		if(bandera== 'T')
		{  bandera= 'F';
			fgets(linea,255,manejador_archivo);
		} else
		   {
		cont++;
		fgets(linea,255,manejador_archivo);
		char *token = strtok(linea, delimitador);
		int i=0;
		if(token != NULL){  
			while(token!=NULL){
				strcpy(aux[i],token);
				token = strtok(NULL, delimitador);
				i++;
			}
		}
		art[j].orden =  atoi(aux[0]);
		strcpy(art[j].idarticulo,aux[1]);
		strcpy(art[j].descripcion, aux[2]);
		art[j].costo = atof (aux[3]);
		strcpy(art[j].tipo, aux[4]);
		art[j].anio =  atoi(aux[5]);
		art[j].precio_venta =  atof(aux[6]);
		j++;
	}
	}
	
	
	fclose(manejador_archivo);
	tamanio=cont;
}
	
	
	
	//Funcione de ORDENAMIENTOS:
	
		
		/** Funcion para  ordenar por ORDEN el array */
		void ordenar_orden(){
			articulos aux;
			for (int i = 0; i < tamanio; i++)
			{
				for (int j = 1; j < tamanio; j++)
				{
					if (art[j].orden < art[j-1].orden)
					{   // si el elemento anterior es mayor, hacemos el cambio
						aux = art[j];
						art[j] = art[j-1];
						art[j-1] = aux;
					}
				}
			}
		}
			
			/** Funcion para  ordenar por Nombre el array */
			void ordenar_nombre(){	
				articulos aux;
				for (int i = 0; i < tamanio; i++)
				{
					for (int j = 0; j < (tamanio-1); j++)
					{	
						if (strcmp(art[j].idarticulo,art[j+1].idarticulo) > 0 )
						{   // si el elemento anterior es mayor, hacemos el cambio
							aux = art[j];
							art[j] = art[j+1];
							art[j+1] = aux;
						}
					}
				}
			}
				
			/** Funcion para  ordenar por descripcion el array */
				void ordenar_descripcion(){	
					
					articulos aux;
					for (int i = 0; i < tamanio; i++)
					{
						for (int j = 0; j < (tamanio-1); j++)
						{	
							if (strcmp(art[j].descripcion,art[j+1].descripcion) > 0 )
							{   // si el elemento anterior es mayor, hacemos el cambio
								aux = art[j];
								art[j] = art[j+1];
								art[j+1] = aux;
							}
						}
					}
				}	
				
				
			/** Funcion para  ordenar por Precio de COSTO el array */
					void ordenar_costo(){
						int j;
						articulos aux;
						for (int i = 0; i < tamanio; i++)
						{
							for ( j = 1; j < tamanio; j++)
							{
								if (art[j].costo < art[j-1].costo)
								{   // si el elemento anterior es mayor, hacemos el cambio
									aux = art[j];
									art[j] = art[j-1];
									art[j-1] = aux;
								}
							}
						}
					} 
						
			/** Funcion para  ordenar por TIPO DE ARTICULO array */
						void ordenar_Tipo(){	
							articulos aux;
							for (int i = 0; i < tamanio; i++)
							{
								for (int j = 0; j < (tamanio-1); j++)
								{	
									if (strcmp(art[j].tipo,art[j+1].tipo) > 0 )
									{   // si el elemento anterior es mayor, hacemos el cambio
										aux = art[j];
										art[j] = art[j+1];
										art[j+1] = aux;
									}
								}
							}
						}			
						
						
						
						
				
			/** Funcion para  ordenar por anio el array */
				void ordenar_anio(){
					articulos aux;
					for (int i = 0; i < tamanio; i++)
					{
						for (int j = 1; j < tamanio; j++)
						{
							if (art[j].anio < art[j-1].anio)
							{   // si el elemento anterior es mayor, hacemos el cambio
								aux = art[j];
								art[j] = art[j-1];
								art[j-1] = aux;
							}
						}
					}
				} 
					
					
					/** Funcion para  ordenar por PRECIO DE VENTA el array */
					void ordenar_PrecioVenta(){
						articulos aux;
						for (int i = 0; i < tamanio; i++)
						{
							for (int j = 1; j < tamanio; j++)
							{
								if (art[j].precio_venta < art[j-1].precio_venta)
								{   // si el elemento anterior es mayor, hacemos el cambio
									aux = art[j];
									art[j] = art[j-1];
									art[j-1] = aux;
								}
							}
						}
					} 
						
					
					//funcione DE BUSQUEDAS
					
				
				/** Funcion busca un nro de Orden en el arreglo */
				void busqueda_orden() {
					int numero, i=0;
					char band = 'F';
					printf("Ingrese un numero para buscar en el arreglo: \n");
					scanf("%d", &numero);
					while ((band == 'F') && (i < tamanio)) {
						if (art[i].orden == numero) {
							band = 'V';
						}
						i++;
					}
					if (band == 'F') {
						printf("El numero de orden no existe en el arreglo\n");
					} else {
						if (band == 'V') {
							printf("El numero fue encontrado en la posicion: %d\n", i);
							printf("%d \n",art[i - 1].orden);
							printf("%s \n",art[i - 1].idarticulo);
							printf("%s \n",art[i - 1].descripcion);
							printf("%f \n",art[i - 1].costo);
							printf("%s \n",art[i - 1].tipo);
							printf("%d \n",art[i - 1].anio);
							printf("%f \n",art[i - 1].precio_venta);
							printf("\n");
						}
					}
				}
				
				
				
				/** Funcion busca por el nombre del Articulo en el arreglo */
				void busqueda_nombre() {
					char nombre[30];
					int i=0;
					char band = 'F';
					printf("Ingrese el nombre del Articulo para buscar en el arreglo: \n");
					scanf("%s", &nombre);
					while ((band == 'F') && (i < tamanio)) {
						
						if (strcmp(art[i].idarticulo,nombre)==0) 
						{
							band = 'V';
						}
						i++;
					}
					if (band == 'F') {
						printf("El nombre de descripcion no existe en el arreglo\n");
					} else {
						if (band == 'V') {
							printf("El numero fue encontrado en la posicion: %d\n", i );
							printf("%d |\n",art[i - 1].orden);
							printf("%s |\n",art[i - 1].idarticulo);
							printf("%s |\n",art[i - 1].descripcion);
							printf("%s |\n",art[i - 1].tipo);
							printf("%f |\n",art[i - 1].costo);
							printf("%d |\n",art[i - 1].anio);
							printf("%f |\n",art[i - 1].precio_venta);
							printf("\n");
						}
					}
				}
				
				/** Funcion busca por el nombre de descripcion en el arreglo */
				void busqueda_descripcion() {
					char nombre[30];
					int i=0;
					char band = 'F';
					printf("Ingrese el nombre de detalle para buscar en el arreglo: \n");
					scanf("%s", &nombre);
					while ((band == 'F') && (i < tamanio)) {
						
						if (strcmp(art[i].descripcion,nombre)==0) 
						{
							band = 'V';
						}
						i++;
					}
					if (band == 'F') {
						printf("El nombre de descripcion no existe en el arreglo\n");
					} else {
						if (band == 'V') {
							printf("El numero fue encontrado en la posicion: %d\n", i);
							printf("\n ");
							printf("%d |\n",art[i - 1].orden);
							printf("%s |\n",art[i - 1].idarticulo);
							printf("%s |\n",art[i - 1].descripcion);
							printf("%s |\n",art[i - 1].tipo);
							printf("%f |\n",art[i - 1].costo);
							printf("%d |\n",art[i - 1].anio);
							printf("%f |\n",art[i - 1].precio_venta);
							printf("\n ");
							printf("\n ");
						}
					}
				}
				
				
				/** Funcion busca un nro de COSTO en el arreglo */
				void busqueda_costo() {
					int numero, i=0;
					char band = 'F';
					printf("Ingrese un numero de costo para buscar en el arreglo: \n");
					scanf("%d", &numero);
					while ((band == 'F') && (i < tamanio)) {
						if (art[i].costo == numero) {
							band = 'V';
						}
						i++;
					}
					if (band == 'F') {
						printf("El numero de orden no existe en el arreglo\n");
					} else {
						if (band == 'V') {
							printf("El numero fue encontrado en la posicion: %d\n", i);
							printf("\n");
							printf("%d \n",art[i - 1].orden);
							printf("%s \n",art[i - 1].idarticulo);
							printf("%s \n",art[i - 1].descripcion);
							printf("%f \n",art[i - 1].costo);
							printf("%s \n",art[i - 1].tipo);
							printf("%d \n",art[i - 1].anio);
							printf("%f \n",art[i - 1].precio_venta);
							printf("\n");
						}
					}
				}
				
				
				
				
				
				/** Funcion busca por el TIPO DE ARCHIVO en el arreglo */
				void busqueda_tipo() {
					char nombre[30];
					int i=0;
					char band = 'F';
					printf("Ingrese el nombre del Tipo para buscar en el arreglo: \n");
					scanf("%s", &nombre);
					while ((band == 'F') && (i < tamanio)) {
						
						if (strcmp(art[i].tipo,nombre)==0) 
						{
							band = 'V';
						}
						i++;
					}
					if (band == 'F') {
						printf("El nombre de descripcion no existe en el arreglo\n");
					} else {
						if (band == 'V') {
							printf("El numero fue encontrado en la posicion: %d\n", i);
							printf("\n ");
							printf("%d |\n",art[i - 1].orden);
							printf("%s |\n",art[i - 1].idarticulo);
							printf("%s |\n",art[i - 1].descripcion);
							printf("%s |\n",art[i - 1].tipo);
							printf("%f |\n",art[i - 1].costo);
							printf("%d |\n",art[i - 1].anio);
							printf("%f |\n",art[i - 1].precio_venta);
							printf("\n ");
							printf("\n ");
						}
					}
				}
				
				/** Funcion busca un nro de COSTO en el arreglo */
				void busqueda_anio() {
					int numero, i=0;
					char band = 'F';
					printf("Ingrese un numero deL ANIO para buscar en el arreglo: \n");
					scanf("%d", &numero);
					while ((band == 'F') && (i < tamanio)) {
						if (art[i].anio == numero) {
							band = 'V';
						}
						i++;
					}
					if (band == 'F') {
						printf("El numero de orden no existe en el arreglo\n");
					} else {
						if (band == 'V') {
							printf("El numero fue encontrado en la posicion: %d\n", i);
							printf("\n");
							printf("%d \n",art[i - 1].orden);
							printf("%s \n",art[i - 1].idarticulo);
							printf("%s \n",art[i - 1].descripcion);
							printf("%f \n",art[i - 1].costo);
							printf("%s \n",art[i - 1].tipo);
							printf("%d \n",art[i - 1].anio);
							printf("%f \n",art[i - 1].precio_venta);
							printf("\n");
						}
					}
				}
				
				
				
				/** Funcion busca un nro de COSTO en el arreglo */
				void busqueda_precioVenta() {
					int numero, i=0;
					char band = 'F';
					printf("Ingrese un numero deL PRECIO DE VENTA para buscar en el arreglo: \n");
					scanf("%d", &numero);
					while ((band == 'F') && (i < tamanio)) {
						if (art[i].precio_venta == numero) {
							band = 'V';
						}
						i++;
					}
					if (band == 'F') {
						printf("El numero de orden no existe en el arreglo\n");
					} else {
						if (band == 'V') {
							printf("El numero fue encontrado en la posicion: %d\n", i);
							printf("\n");
							printf("%d \n",art[i - 1].orden);
							printf("%s \n",art[i - 1].idarticulo);
							printf("%s \n",art[i - 1].descripcion);
							printf("%f \n",art[i - 1].costo);
							printf("%s \n",art[i - 1].tipo);
							printf("%d \n",art[i - 1].anio);
							printf("%f \n",art[i - 1].precio_venta);
							printf("\n");
						}
					}
				}
				
				
				
				
				
				
				
				//funciones de muestra
				/** Funcion Que muestra el archivo */
				void mostrar(){
					
					printf("ORDEN IDARTICULO DESCRIPCION COSTO TIPO ANIO PRECIO_VENTA \n\n");
					for(int j=0;j<tamanio;j++){
						printf("%d ",art[j].orden);
						printf("%s ",art[j].idarticulo);
						printf("%s ",art[j].descripcion);
						printf("%.2f ",art[j].costo);
						printf("%s ",art[j].tipo);
						printf("%d ",art[j].anio);
						printf("%.2f ",art[j].precio_venta);
					
						printf("\n");
					}
				}
					
					
					//funciones para guardar el Archivo 
					/**Funcion para guardar el archivo generado*/  
					void guardarArchivo(){
						
						
						FILE *manejador_archivo = NULL;
						manejador_archivo = fopen(sNombre, "wt");
						if(manejador_archivo == NULL ) {
							printf("No fue posible abrir el archivo\n");
							return;
						}
						fprintf(manejador_archivo,"%s","ORDEN;IDARTICULO;DESCRIPCION;COSTO;TIPO;ANIO;PRECIO_VENTA\n");
						for(int i=0;i<tamanio;i++){
							fprintf(manejador_archivo,"%d",art[i].orden );
							fprintf(manejador_archivo,";");
							fprintf(manejador_archivo,art[i].idarticulo);
							fprintf(manejador_archivo,";");
							fprintf(manejador_archivo,art[i].descripcion);
							fprintf(manejador_archivo,";");
							fprintf(manejador_archivo,"%.2f",art[i].costo);
							fprintf(manejador_archivo,";");
							fprintf(manejador_archivo,art[i].tipo);
							fprintf(manejador_archivo,";");
							fprintf(manejador_archivo,"%d",art[i].anio);
							fprintf(manejador_archivo,";");
							fprintf(manejador_archivo,"%.2f",art[i].precio_venta);
							if(  i < tamanio-1){
								fprintf(manejador_archivo,"\n");
							}
						}
						fclose(manejador_archivo);
					
					}
						
						
						//Funcion Carga Archivo
						/**Funcion para Agregar un elemento al Archivo*/ 
						void agregar(){
							tamanio++;
							printf("- - - - Agregar un elemento nuevo %d- - - -\n\n",tamanio);
							printf("Agregue un Numero De Orden\n");
							fflush(stdin);
							scanf("%d",&art[tamanio-1].orden);
							printf("Agregue un Codigo de articulo\n");
							fflush(stdin);
							scanf("%s",&art[tamanio-1].idarticulo);
							printf("Agregue una Descripcion del articulo\n");
							fflush(stdin);
							scanf("%s",&art[tamanio-1].descripcion);
							printf("Agregue el Costo del articulo\n");
							fflush(stdin);
							scanf("%f",&art[tamanio-1].costo);
							printf("Agregue el Tipo del articulo(REMERA/CALZADO/ETC)\n");
							fflush(stdin);
							scanf("%s",&art[tamanio-1].tipo);
							printf("Agregue el Anio del articulo\n");
							fflush(stdin);
							scanf("%d",&art[tamanio-1].anio);
							
							// EL PRECIO SE CARGA SOLO CUANDO SE CALCULA
							
							art[tamanio-1].precio_venta= 100;//((art[tamanio].costo)* 2);
							
							printf("%d ",art[tamanio-1].orden);
							printf("%s ",art[tamanio-1].idarticulo);
							printf("%s ",art[tamanio-1].descripcion);
							printf("%s ",art[tamanio-1].tipo);
							printf("%.2f ",art[tamanio-1].costo);
							printf("%d ",art[tamanio-1].anio);
							printf("%.2f ",art[tamanio-1].precio_venta);
							printf("\n");
						}
							
							/**Funcion para Agregar un elemento al Archivo*/ 
							void eliminar(){
								articulos aux;
								int buscado,posicion;
								mostrar();
								printf("\n");
								printf("Ingrese el Nro de linea que desee eliminar:\n");
								scanf("%d",&buscado);
								posicion= buscado-1;//buscar_orden(array,buscado);
								if (posicion!= -1){
									for (int i = posicion; i < tamanio; i++)
									{
										
										//aux = art[j];
										art[i] = art[i+1];
										//art[j-1] = aux;
									}
									
									printf("Se elimino el registro\n\n");
									
								}
								tamanio--;
								mostrar();
							}	
								
								
