#include <iostream>
#include <time.h>
#include<math.h>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int menu(); //FUNCION MENU

void trianguloPascal(int,int,int[],int[]);

double desviacionEstandar(int[]);//EJERCICIO 2
void imprimirArreglo(int [], int n);

void graficosBarra();//EJERCICIO 3

int main(int argc, char** argv) {
	int opcion=0;
	int a = 0;
	while(a!=4){
		switch(a = menu()){
			case 1:{
				int max_n=0;
				cout<<"Ingrese el maximo (mayor que 0): ";
				cin>>max_n;
				while(max_n<1 || max_n>99){
					cout<<"Por favor, ingrese un maximo mayor que 0 y menor que 100: ";
					cin>>max_n;
				}
				int res_anterior[100],salida[100];
				for(int i=0; i<100; i++){
					res_anterior[i]=0;
				}
				for(int i=0; i<100; i++){
					salida[i]=0;
				}
				trianguloPascal(0,max_n,res_anterior,salida);
				break;
			}	
			case 2:{
				int x[20];
				srand(time(NULL));
				for(int i=0; i<20; i++){
					x[i]=1+rand()%(100);
				}
				imprimirArreglo(x,20);
				cout<<desviacionEstandar(x)<<endl;
				break;
			}	
			case 3:{
				graficosBarra();
				break;
			}	
			case 4:{
				break;			
			}
			default: 
				cout<<"Opcion no valida, ingresela nuevamente"<<endl;
	    }
   }//FIN DEL WHILE
	
	return 0;
}//FIN DE LA FUNCION MAIN

int menu(){//funcion menu
	int opc=0;
	while(opc!=4){
		cout<<"MENU"<<endl
		<<"1. Ejercicio 1 (Triangulo de Pascal)"<<endl
		<<"2. Ejercicio 2 (Desviacion estandar)"<<endl
		<<"3. Ejercicio 3 (ASCII)"<<endl
		<<"4. Salir"<<endl
		<<"Opcion: ";
		cin>>opc;
		if(opc>=1&&opc<=4){
			break;
		}			
   }
   return opc;	
}//fin de la funcion menu

void graficosBarra(){//METODO DE EJERCICIO 3
	int x[10],y[10];
	srand(time(NULL));
	for(int i=0; i<10; i++){ //llenando arreglos con random
		x[i]=1+rand()%(20);
	}
	
	for(int i=0; i<10; i++){
		y[i]=1+rand()%(20);
	}
	//Mostrando los arreglos random
	cout<<"Sus arreglos son: "<<endl;
	cout<<"[ ";
	for(int i=0; i<10; i++){
		cout<<x[i]<<" ";
	}
	cout<<"]"<<endl;
	
	cout<<"[ ";
	for(int i=0; i<10; i++){
		cout<<y[i]<<" ";
	}
	cout<<"]"<<endl;
	//fin de mostrar los arreglos
	
	char c1 = 177;
	char c2 = 178;
	for(int i=0; i<10; i++){
		cout<<i+1;
		for(int j=0; j<x[i]; j++){
			cout<<c1;
		}
		cout<<endl;
		for(int k=0; k<y[i]; k++){
			cout<<c2;
		}
		cout<<endl;
		cout<<endl;
	}
}

double desviacionEstandar(int x[]){//METODO EJERCICIO 2
	int temp[20];
	double promedio;
	double acum=0;
	for(int i=0; i<20; i++){
		acum+=x[i];
	}
	promedio=acum/20;
	//cout<<promedio;
	
	for(int i=0; i<20; i++){
		temp[i]= ( (x[i])-promedio) * ( (x[i])-promedio);
	}
	//cout<<temp[0];
	
	acum=0;
	for(int i=0; i<20; i++){
		acum+=temp[i];
	}
	//cout<<acum;
	
	double div;
	div=acum/20;
	
	cout<<"La desviacion estandar es: ";
	return sqrt(div);
}

void imprimirArreglo(int x[], int n){ //metodo para imrpimir arreglo
	cout<<"Su arreglo es: "<<endl;
	for(int i=0; i<n; i++){
		cout<<x[i]<<" ";
	}
	cout<<endl;
}

void trianguloPascal(int n, int max_n, int res_anterior[],int salida[]){
	if(n==max_n){
		/*for(int i=0; i<100; i++){
			if(salida[i]!=0){
				cout<<salida[i]<<" ";
			}
		}
		cout<<endl;
		*/
	}
	else{
		n++;
		salida[0]=1;
		if(n==1){//la primera vez solo imprimo el 1 que está en la primera posicion del arreglo
			cout<<n<<endl;
			trianguloPascal(n,max_n,res_anterior,salida);//vuelvo a entrar a la funcion 
		}
		else{
			//n=2,3
			cout<<salida[0]<<""; //siempre imprimo el primer 1
			for(int i=1;i<n;i++){
				salida[i]=salida[i]+n-1;
				if(salida[i]!=0){
					if(i==n-1){
						cout<<"1";
					}
					else{
						cout<<salida[i]-1;
					}
					
				}
			}
			cout<<endl;
			trianguloPascal(n,max_n,res_anterior,salida);
		}
		
	}
}

