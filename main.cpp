#include <iostream>
#include <stdlib.h>
#define f_osc 8000000
using namespace std;

class AN{
	private:				//Encapsulamiento (como caja negra)
		short int resolucion;				//DAtos o caracteristicas Abstraidas
		int Fs;
		short int canal;
		float lectura;
	public:
		AN();				
		void muestraDatos();
		// 				Getters & Setters	 Metodos constructores y modificadores
		void captura();	
};
/************************************************
    DECLARACION DEL CONSTRUCTOR (INICIALIZA ATRIBUTOS DEL OBJETO)
************************************************/
AN::AN(){
	resolucion = 0;
	Fs = 0;
	canal = 0;
	lectura = 0;
}
/************************************************
    METODOS
************************************************/
void AN::muestraDatos(){
	cout<<"Canal: "<<canal<<endl;
	cout<<"Resolucion: "<<resolucion<<endl;
	cout<<"Fs: "<<Fs<<endl;
	cout<<"Lectura: "<<lectura<<endl;
}
/************************************************
    SETTER
************************************************/
void AN::captura(){
	cout<<"Dame resolucion deseada (8, 10 o 12): ";
	cin>> resolucion;
  if(resolucion==8 || resolucion==10 || resolucion==12);
  else{
    cout<<"Dato incorrecto ";
    exit (1);
  }
	cout<<"Dame la frecuencia de muestreo ";
	cin>> Fs;  
	cout<<"Dame canal a leer (1 a 32): ";
  cin>> canal;
  if(canal>0 && canal<33);
  else{
    cout<<"Dato incorrecto ";
    exit (1);
  }
	cout<<"Dame la lectura: ";
	cin>> lectura;
  if(lectura>=0 && lectura<3.4);
  else{
    cout<<"Dato incorrecto ";
    exit (1);
  }
}
/************************************************
   MAIN
************************************************/
int main(int argc, char** argv) {
  int canales;
  cout<<"Dame cantidad de canales ADC a leer: ";
	cin>> canales;
  AN AN[canales];

	//Capturando Datos  
	cout<<endl<<"** Introduce Datos **"<<endl;
  for (int i=0;i<canales;i++){
	  cout<<"\nToma: "<<i+1<<endl;
    AN[i].captura();
  }
	
	//Imprimiendo Datos
  cout<<endl<<"** Imprimiendo Datos **"<<endl;
	for (int i=0;i<canales;i++){
		cout<<"\nToma: "<<i+1<<endl;
    AN[i].muestraDatos();
	}
		
	system("pause");
	return 0;
}