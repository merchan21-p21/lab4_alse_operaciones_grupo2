#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_FILE_SIZE 10000

void ayuda( int bandera);
void version( int bandera);
void leer_mat1(char *mat1,char *mat2);



int main(int argc, char * const argv[])
{
	int bandera=0;
	int 	m=0;
	char mat1[MAX_FILE_SIZE];
	char mat2[MAX_FILE_SIZE];
	char help[MAX_FILE_SIZE];
	strcmp (help , argv[1]);
	
	
	
	if(argc != 5)
	{
	
		if(strcmp(argv[1] , "--help")==0)
		{	
			ayuda(bandera);

		}
		else if(strcmp(argv[1] , "-v")==0)
			
		{
			version(bandera);
		}
		else if(strcmp(argv[1] , "-s")==0)
		{
			
			leer_mat1(mat1,mat2);
			printf("%s\n",mat1);
			printf("\n\n%s\n",mat2);
			
				
		}
	}
	
	
}

void ayuda(int bandera)
{
	if(bandera == 0)
	{
		printf("\nMenu de ayuda : ");
		printf("\n-v : version, autores y fecha de desarrollo. ");
		printf("\n-t : traspuesta de matrices. ");
		printf("\n-a : suma de las dos matrices. ");
		printf("\n-r : resta las dos matrices. ");
		printf("\n-w : ruta del archivo. \n");
	}
	else{
		printf("Error en los argumentos de entrada.\n");
	}
}

void version(int bandera)
{
	if(bandera == 0)
	{
		printf("Esta es la version 1.0\n");
		printf("Autor: juan pablo merchan\n");
	}
}	

void leer_mat1(char *mat1, char *mat2)
{
	FILE *flujo1 =0;
	FILE *flujo2;
	char m1[MAX_FILE_SIZE];
	char m2[MAX_FILE_SIZE];
	flujo1 = fopen("mat1.csv","r");
	flujo2 = fopen("mat2.csv","r");
	if(flujo1 == NULL || flujo2 == NULL)
	{
		printf("Error en la apertura del archivo ");
	}
	fseek(flujo1,0,SEEK_END);//mover hasta el final del archivo
	fseek(flujo2,0,SEEK_END);
	int num_elementos = ftell(flujo1);//donde estan los datos cantidad
	int num_elementos2 = ftell(flujo2);
	rewind(flujo1);//mover al inicio del archivo
	rewind(flujo2);
	char *cadena1 =(char *) calloc(sizeof(char), num_elementos);
	char *cadena2 =(char *) calloc(sizeof(char), num_elementos2);
	if(cadena1 == NULL || cadena2 ==NULL)
	{
		printf("Error en la reserva de memoria ");
	}
	
	int num_elementos_leidos = fread(cadena1, sizeof(char), num_elementos, flujo1);
	int num_elementos_leidos2 = fread(cadena2, sizeof(char), num_elementos2, flujo2);
	if(num_elementos_leidos != num_elementos)
	{
		printf("Error en la lectura de archivos");
	}
	
	fclose(flujo1);
	fclose(flujo2);
	
	strcpy(mat1, cadena1);
	strcpy(mat2, cadena2);
	int val[MAX_FILE_SIZE];
	int cont,cont1 =0;
	char mt1[MAX_FILE_SIZE];
	/*for (int i=0; i < num_elementos,i++)
	{
		//cont =0;
		if(m1[i] == ";")
		{
		strcat(mat1[cont], val);
		cont++;
		}
		if(m1[i]== 13 || m1[i]==10)
		{
			
		}
		else
		{
			
			strcat(mt1[i], m1[i]);
			val[cont1] = atoi(mt1[i]);
			cont1++;	
			
		}
	}*/	
	//printf("\n%s\n", mat1);
	//printf("\n%s\n", mat2);
	
}
