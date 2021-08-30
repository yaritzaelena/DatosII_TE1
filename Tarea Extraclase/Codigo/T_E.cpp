//Yaritza lopez Bustos

//Librerias
#include<iostream>
#include<conio.h>
#include<fstream>
#include<stdlib.h>
#include<stdio.h>

using namespace std;
void quickSort(int array[], int first, int last);
void escribir();

//Variables globales
int *Numeros;
int i;

/*
* Principal, donde se inicializa todo
*/
int main(){
	
	
	//Variables 
	FILE *Texto; 
	int Num; 
	int P;
	

	
	
	
	Num = 256; //Cantidad de enteros
	Numeros = (int *) malloc(sizeof(int) *Num); //Memoria dinamica/Puntero.
	Texto = fopen ("archivo.txt", "r"); //Arbir el archivo que contiene los numeros enteros.

	
	i=1;
	while (!feof(Texto) && i<257){ //While para manejar el documento e ir asignando los numeros al puntero
		fscanf(Texto, "%d,", &P);
		cout << P;
		Numeros[i]=P; // Ir agregando los numeros del documento al puntero. 
		i++;
	
	
	}

	fclose(Texto);

	
	int sizeOfArray = sizeof(Numeros); 
    	int sizeOfDataType = sizeof(int);
    	int size = sizeOfArray/sizeOfDataType;
    	quickSort(Numeros,0,size-1); //Inicializar el quickSort
    	cout<<"Sorted array"<<endl;
    	cout<<size<<endl;
    	for(int k = 1; k < size; k++){ 
           cout<<Numeros[k]<<",";
    	}
    	cout<<""<<endl;
	
	
	escribir(); //Inicializar la funcion de escribir en el documento
	free(Numeros); //Liberacion del puntero
	system("pause");
	
	
	return 0;
		
}



// Metodo para el ordenamiento de los numeros
void quickSort(int array[], int first, int last){
    int ii, jj, mid;
    int pivote;

    mid = (first + last) / 2;
    pivote = array[mid];
    ii = first;
    jj = last;

    do{
        while(array[ii] < pivote) ii++;
        while(array[jj] > pivote) jj--;

        if(ii <= jj){
            swap(array[ii], array[jj]);
            ii++;
            jj--;
        }
    }
	while(ii <= jj);{
		if(first < jj){
        quickSort(array, first, jj); //se ordena la sublista izquierda
    	}
    	if(ii < last){
        quickSort(array, ii, last); //se ordena la sublista derecha
    	}
	}

}


//Escribir sobre el nuevo archivo
void escribir (){
	ofstream archivo;
	
	archivo.open("archivo_resultado.txt", ios::out); //Creacion del nuevo archivo
	if(archivo.fail()){ 
		exit(1);
	}
	for (int m =1 ; m<257; m++){ //Recorre el puntero y lo va escribiendo en el archivo de resultado
		archivo<< Numeros[m];
	}
	archivo.close();
}
