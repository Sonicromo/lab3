#include <iostream>
#include <stdlib.h>
#define OCHO 255
#define DIEZ 1023
#define DOCE 4095
using namespace std;

class AN{
	private:				//Encapsulamiento (como caja negra)
		short int resolucion;				//DAtos o caracteristicas Abstraidas
		int Fs;
		short int canal;
		float lectura;
    float lect;
	public:
		AN();				
		void muestraDatos();
		// 				Getters & Setters	 Metodos constructores y modificadores
		void captura(int, int);	
};
/************************************************
    DECLARACION DEL CONSTRUCTOR (INICIALIZA ATRIBUTOS DEL OBJETO)
************************************************/
AN::AN(){
	resolucion = 0;
	Fs = 0;
	canal = 0;
	lectura = 0;
  lect = 0;
}
/************************************************
    METODOS
************************************************/
void AN::muestraDatos(){
	cout<<"Canal: "<<canal<<endl;
	cout<<"Resolucion: "<<resolucion<<endl;
	cout<<"Fs: "<<Fs<<endl;
	cout<<"Lectura: "<<lectura<<endl;
	cout<<"Lectura digital: "<<lect<<endl;
}
/************************************************
    SETTER
************************************************/
void AN::captura(int res, int F){
	resolucion = res;
  Fs = F;
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
  if(resolucion == 8){
    lect = (lectura/3.3)*OCHO;
  }
  if(resolucion == 10){
    lect = (lectura/3.3)*DIEZ;
  }
  if(resolucion == 12){
    lect = (lectura/3.3)*DOCE;
  }
}
/************************************************
   MAIN
************************************************/
int main(int argc, char** argv) {
  int canales, res, F;
  cout<<"Dame cantidad de canales ADC a leer: ";
	cin>> canales;
  AN AN[canales];
  cout<<"Dame resolucion deseada (8, 10 o 12): ";
	cin>> res;
  if(res==8 || res==10 || res==12);
  else{
    cout<<"Dato incorrecto ";
    exit (1);
  }
	cout<<"Dame la frecuencia de muestreo ";
	cin>> F;  
	//Capturando Datos  
	cout<<endl<<"** Introduce Datos **"<<endl;
  for (int i=0;i<canales;i++){
	  cout<<"\nToma: "<<i+1<<endl;
    AN[i].captura(res, F);
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