#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <string>
using namespace std;
enum Rol {
	EstudioPregrado=0,EstudioPosgrado,Docentes,Autoridades,PersonalAdministrativo,PersonalServicios
};
const char *TipoRol[]{
	"Estudiante De Pregrado",
	"Estudiante De Posgrado",
	"Docentes",
	"Autoridades",
	"Personal Administrativo",
	"Personal De Servicios"
};

struct ArbolV {
	int codigo,fe;
	string nombre;
	string objetivo;
	int cupomax;
	ArbolV *der,*izq;
};
struct ListaM {
       int cedula;
       string nombre;
       string apellido;
       int rol;
       int CantV;
       int CantAS;
       int CantAP;
        ListaM *sig;
        ArbolV *V;
};

struct ArbolM{
	int cedula,fe;
    string nombre;
    string apellido;
     int rol;
     int CantV;
     int CantAS;
     int CantAP;
     ArbolM *der,*izq;	
	
};

/*void AVLm(ArbolM *&raiz,int dato)
{

nodo *q,*r,*x;
int cen = 0;

if (raiz != NULL)

{

if (dato < raiz->inf)

{

inserta_avl(raiz -> izq,dato);

if (cen==1)

{

switch(raiz->fe)

{

case 1:raiz->fe=0;

cen=0;

break;

case 0:raiz->fe=-1;

break;

case -1:q=raiz->izq;

if (q->fe<=0)

{

//rotacion I.I.

raiz->izq=q->der;

q->der=raiz;

raiz->fe=0;

raiz=q;

}

else

{

//rotacion I.D.

r=q->der;

raiz->izq=r->der;

r->der=raiz;

q->der=r->izq;

r->izq=q;



if (r->fe==-1)

raiz->fe=1;

else

raiz->fe=0;



if (r->fe==1)

q->fe=-1;

else

q->fe=0;



raiz=r;

}

raiz->fe=0;

cen=0;

break;

}

}

}

else

{

if (dato > raiz->inf)

{

inserta_avl(raiz->der,dato);

if (cen==1)

{

switch(raiz->fe)

{

case -1:raiz->fe=0;

cen=0;

break;

case 0:raiz->fe=1;

break;

case 1:q=raiz->der;

if (q->fe>=0)

{

//rotacion D.D.

raiz->der=q->izq;

q->izq=raiz;

raiz->fe=0;

raiz=q;

}

else

{

//rotacion D.I.

r=q->izq;

raiz->der=r->izq;

r->izq=raiz;

q->izq=r->der;

r->der=q;



if (r->fe==1)

raiz->fe=-1;

else

raiz->fe=0;



if (r->fe==-1)

q->fe=1;

else

q->fe=0;



raiz=r;

}

raiz->fe=0;

cen=0;

break;

}

}

}

else

{

system("CLS");

cout<<"La clave"<< raiz-> inf<<" ya existe";

getch();

}

}

}

else

{

raiz = new(nodo);

raiz->inf=dato;

raiz->izq=NULL;

raiz->der=NULL;

raiz->fe=0;

cen=1;

}

//return (raiz);

} */

void AVLvol(ArbolV *&raiz,int dato, int &cen)
{

ArbolV *q,*r,*x;

if (raiz != NULL) {

	if (dato < raiz->codigo){

		AVLvol(raiz -> izq,dato,cen);

		if (cen==1){

			switch(raiz->fe){

				case 1:raiz->fe=0;

				cen=0;

				break;

				case 0:raiz->fe=-1;

				break;

				case -1:q=raiz->izq;

				if (q->fe<=0){

					//rotacion I.I.

					raiz->izq=q->der;

					q->der=raiz;

					raiz->fe=0;

					raiz=q;

				}

				else
				{

				//rotacion I.D.

					r=q->der;

					raiz->izq=r->der;

					r->der=raiz;

					q->der=r->izq;

					r->izq=q;



				 if (r->fe==-1)

						raiz->fe=1;

					else

						raiz->fe=0;



				 if (r->fe==1)

					q->fe=-1;

				 else

					q->fe=0;



				raiz=r;

				}

			raiz->fe=0;

			cen=0;

			break;

			}

		}		

	}

	else {

		if (dato > raiz->codigo){

			AVLvol(raiz->der,dato,cen);

			if (cen==1)	{

				switch(raiz->fe){

					case -1:raiz->fe=0;

						cen=0;

					break;

					case 0:raiz->fe=1;

					break;

					case 1:q=raiz->der;

					if (q->fe>=0){

							//rotacion D.D.

						raiz->der=q->izq;

						q->izq=raiz;

						raiz->fe=0;

						raiz=q;

					}

					else {		

						//rotacion D.I.

						r=q->izq;

						raiz->der=r->izq;

						r->izq=raiz;

						q->izq=r->der;

						r->der=q;



							if (r->fe==1)

								raiz->fe=-1;	

							else

								raiz->fe=0;



							if (r->fe==-1)

								q->fe=1;

							else

								q->fe=0;
								raiz=r;

					}

						raiz->fe=0;

						cen=0;

				break;

				}

			}

		}

	 	else {

			system("CLS");

			cout<<"La clave"<< raiz->codigo<<" ya existe";

			getch();

		}

	}

}



//return (raiz);

} 

void Registro(ArbolV *&V, int &cen){
	int dato; 
	cout<<"Ingrese el codigo de la agrupacion"<<endl;
	cin>>dato;
	if (V!=NULL){
	
	cout<<"Ingrese el nombre de la agrupacion"<<endl; //cambiar con las constantes
	cin>>V->nombre;
	cout<<"Ingrese el objetivo de la agrupacion"<<endl;
	cin>>V->objetivo;
	cout<<"Ingrese el cupo maximo"<<endl;
	cin>>V->cupomax;
	AVLvol(V,dato,cen);
	}
	else{
			V= new(ArbolV);
		cout<<"Ingrese el nombre de la agrupacion"<<endl; //cambiar con las constantes
		cin>>V->nombre;
		cout<<"Ingrese el objetivo de la agrupacion"<<endl;
		cin>>V->objetivo;
		cout<<"Ingrese el cupo maximo"<<endl;
		cin>>V->cupomax;
		V->codigo=dato;

		V->izq=NULL;

		V->der=NULL;

		V->fe=0;

		cen=1;
		
	}

}

void LlenarLista(ListaM *&M){
		ListaM *Q,*T; T=M;
	int j; int cen=0;
	if (M==NULL){
	
		M= new ListaM;
		cout <<"ingrese cedula"<<endl;
		cin>>M->cedula; }
	else {
	
		while (T->sig!=NULL){
			T=T->sig;
		}
		Q = new ListaM;
		cout<<"ingrese cedula "<<endl;
		cin>>Q->cedula;
		
	}
	cout<<"cuantos voluntarios desea agregar"<<endl;
		cin>>j;
		
		for (int i=1;i<=j;i++){
			Registro(M->V,cen);
			system("CLS");
		}
		Q->sig=NULL;
		T->sig=Q;
}
int main() {
    ListaM *P=NULL;
    P->V=NULL;
    ArbolM *M=NULL;
    LlenarLista(*&P);

    getch();
}
