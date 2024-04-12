#include <iostream>
#include <stdio.h>
#include <string.h>

void menuOrdenamiento();
void menuBusqueda();


void ordenar_orden();
void ordenar_nombre();
void ordenar_descripcion();
void ordenar_costo();
void ordenar_Tipo();
void ordenar_anio();
void ordenar_PrecioVenta();


void busqueda_orden();
void busqueda_nombre();
void busqueda_descripcion();
void busqueda_costo();
void busqueda_tipo();
void busqueda_anio();
void busqueda_precioVenta();




void guardarArchivo();
void mostrar();
void agregar();
void eliminar();

void menuPricipal()
{	int op;
do
{	
system("cls");

printf("BIENVENIDO AL MENU PRINCIPAL \n\n");
printf("1. Mostrar el arreglo \n");
printf("2. Menu de Ordenamiento \n");
printf("3. Menu de busqueda\n");
printf("4. Agregar un nuevo articulo\n");
printf("5. Eliminar un articulo\n");
printf("0. GUARDAR Y SALIR \n\n");

fflush(stdin);

scanf("%d",&op);

switch (op)
{
case 1: 
	system("cls");
	mostrar();
	system("pause");
	break;
	
case 2: system("cls");
menuOrdenamiento();

break;

case 3: system("cls");
menuBusqueda();

break;

case 4: system("cls");
agregar();
system("pause");
break;

case 5: system("cls");
eliminar();
system("pause");
break;

case 0: guardarArchivo();
return;
//Aca Guardaria el arreglo en el archivo antes de salir;
break;

default: printf ("\n La opcion seleccionada es incorrecta \n");
system("pause");

}
}while(op!=0);
} 









//funcion MENU DE ORDENAMIENTO 


void menuOrdenamiento()
{	
	
int op;
do
{	system("cls");
printf("BIENVENIDO AL MENU DE ORDENAMIENTO \n\n");
printf("1. Mostrar el archivo \n");
printf("2. Ordenar el archivo por NUMERO DE ORDEN \n");
printf("3. Ordenar el archivo por NOMBRE DE ARTICULO  \n");
printf("4. Ordenar el archivo DESCRIPCION \n");
printf("5. Ordenar el archivo COSTO\n");
printf("6. Ordenar el archivo por el TIPO\n");
printf("7. Ordenar el archivo por ANIO\n");
printf("8. Ordenar el archivo por PRECIO DE VENTA\n\n");

printf("0. Menu Pricipal \n\n");
fflush(stdin);
scanf("%d",&op);

switch (op)
{
case 1: 
	system("cls");
	mostrar();
	system("pause");
	break;
	
case 2: system("cls");
ordenar_orden();
mostrar();
system("pause");
break;

case 3: system("cls");
ordenar_nombre();
mostrar();
system("pause");
break;

case 4: system("cls");
ordenar_descripcion();
mostrar();
system("pause");
break;

case 5: system("cls");
ordenar_costo();
mostrar();
system("pause");
break;

case 6: system("cls");
ordenar_Tipo();
mostrar();
system("pause");
break;

case 7: system("cls");
ordenar_anio();
mostrar();
system("pause");
break;


case 8: system("cls");
ordenar_PrecioVenta();
mostrar();
system("pause");
break;


case 0: return;
break;

default: printf ("\n La opcion seleccionada es incorrecta \n");
system("pause");

}
}while(op!=0);
} 






//Funcion de Busquedas

void menuBusqueda()
{	int op;
do
{	
	system("cls");
	
	printf("BIENVENIDO AL MENU DE BUSQUEDA \n\n");
	printf("1. Mostrar el ARCHIVO \n");
	printf("2. Buscar un elemento por el id(ORDEN) \n");
	printf("3. Buscar un elemento por NOMBRE DEL ARTICULO\n");
	printf("4. Buscar un elemento por la DESCRIPCION \n");
	printf("5. Buscar un elemento por EL COSTO \n");
	printf("6. Buscar un elemento por EL TIPO \n");
	printf("7. Buscar un elemento por EL ANIO\n");
	printf("8. Buscar un elemento por EL PRECIO DE VENTA\n\n");
	
	printf("0. Menu Principal \n\n");
	fflush(stdin);
	scanf("%d",&op);
	
	switch (op)
	{
	case 1: 
		system("cls");
		mostrar();
		system("pause");
		break;
		
	case 2: system("cls");
	busqueda_orden();
	system("pause");
	break;
	
	
	case 3: system("cls");
	busqueda_nombre();
	mostrar();
	system("pause");
	break;
	
	
	case 4: system("cls");
	busqueda_descripcion();
	system("pause");
	break;
	
	case 5: system("cls");
	busqueda_costo();
	system("pause");
	break;
	
	case 6: system("cls");
	busqueda_tipo();
	system("pause");
	break;
	
	
	case 7: system("cls");
	busqueda_anio();
	system("pause");
	break;
	
	case 8: system("cls");
	busqueda_precioVenta();
	system("pause");
	break;
	
	
	

	
	case 0: return;
	break;
	
	default: printf ("\n La opcion seleccionada es incorrecta \n");
	system("pause");
	
	}
}while(op!=0);
} 
