#include <iostream>
#include <conio.h>
#include <string>
#include <stdlib.h>
#include <windows.h>

using namespace std;

const char *TipoRol[] = {
	"Estudiante de Pregrado",
	"Estudiante de Postgrado",
	"Docente",
	"Autoridad",
	"Personal Administrativo",
	"Personal de Servicios"
};

struct Voluntariado {
	int FE;
	int Codigo;
	string Nombre;
	string Objetivo;
	int cupomax;
	Voluntariado *izq, *der;
};

struct Misericordioso {
	int FE;
	int Cedula;
	string Nombre;
	string Apellido;
	int Rol;
	bool Vol;
	int Voluntariados;
	int Amigos;
	bool Ami;
	int Apostolados;
	bool Apos;
	Voluntariado *V;
	Misericordioso *sig;
};

struct ArbolM{
	int FE;
	int Cedula;
	string Nombre;
	string Apellido;
	int Rol;
	bool Vol;
	int Voluntariados;
	int Amigos;
	bool Ami;
	int Apostolados;
	bool Apos;
	ArbolM *izq, *der;
};
void Final() {
	cout << "Presione cualquier tecla para continuar";
	getch();
	system("CLS");
}

void MostrarMisericordioso (Misericordioso *P) {
	cout << "Cedula: " << P -> Cedula << endl;
	cout << "Nombres: " << P -> Nombre << endl;
	cout << "Apellidos: " << P -> Apellido << endl;
	cout << "Rol: " << TipoRol[P -> Rol] << endl;
	if (P -> Vol) {
		cout << "Cantidad de voluntariados: " << P -> Voluntariados << endl;
	}
	if (P -> Ami) {
		cout << "Cantidad de asociados AVESSOC: " << P -> Amigos << endl;
	}
	if (P -> Apos) {
		cout << "Cantidad de apostolados: " << P -> Apostolados << endl;
	}
}


void AVLvol(Voluntariado *&raiz,int dato, int &cen,bool &a) {	
	Voluntariado *q,*r,*x;
	if (raiz!=NULL) {
		if (dato < raiz->Codigo) {
			AVLvol(raiz -> izq,dato,cen,a);
			if (cen==1) {
				switch(raiz->FE) {
					case 1 : {
						raiz->FE=0;
						cen=0;
						break;
					}
					case 0 : {
						raiz->FE=-1;
						break;
					}
					case -1 : {
						q=raiz->izq;
						if (q->FE<=0) {
						//rotacion I.I.
							raiz->izq=q->der;
							q->der=raiz;
							raiz->FE=0;
							raiz=q;
						}
						else {
					//rotacion I.D.
							r=q->der;
							raiz->izq=r->der;	
							r->der=raiz;
							q->der=r->izq;
							r->izq=q;
					 		if (r->FE==-1)
								raiz->FE=1;
							else
								raiz->FE=0;
					 		if (r->FE==1)
								q->FE=-1;
					 		else
								q->FE=0;
							raiz=r;	
						}
						raiz->FE=0;
						cen=0;
						break;
					}
				}
			}		
		}
		else {
			if (dato > raiz->Codigo) {
				AVLvol(raiz->der,dato,cen,a);
				if (cen==1)	{
					switch(raiz->FE) {
						case -1 : {
							raiz->FE=0;
							cen=0;
							break;
						}
						case 0 : {
							raiz->FE=1;
							break;
						}
						case 1 : {
							q=raiz->der;
							if (q->FE>=0){
								//rotacion D.D.
								raiz->der=q->izq;
								q->izq=raiz;
								raiz->FE=0;
								raiz=q;
							}
							else {		
							//rotacion D.I.
								r=q->izq;
								raiz->der=r->izq;
								r->izq=raiz;
								q->izq=r->der;
								r->der=q;
								if (r->FE==1)
									raiz->FE=-1;	
								else
									raiz->FE=0;
								if (r->FE==-1)
									q->FE=1;
								else
									q->FE=0;
								raiz=r;
							}
							raiz->FE=0;
							cen=0;
							break;
						}
					}
				}
			}
		 	else {
				system("CLS");
				cout<<"La clave"<< raiz->Codigo<<" ya existe";
				getch();
			}
		}
	}
	else {
	
	raiz= new(Voluntariado);
		raiz->Codigo=dato;
			raiz->izq=NULL;

		raiz->der=NULL;

		raiz->FE=0;

		cen=1; }
		if (!a){
		
		cout<<"Ingrese el nombre de la agrupacion"<<endl; //cambiar con las constantes
		getline(cin,raiz->Nombre);
		
		cout<<"Ingrese el objetivo de la agrupacion"<<endl;
		getline(cin,raiz->Objetivo); 
		cout<<"Ingrese el cupo maximo"<<endl;
		cin>>raiz->cupomax; cin.ignore(); a=true;
		}
}

void RVoluntariado (Voluntariado *&V, int &Cen) {
	int Dato; bool a=false;
	cout << "Codigo de agrupacion: ";
	cin >> Dato;
	cin.ignore(); 
		AVLvol(V,Dato,Cen,a);
	getch();
}

void Registro (Misericordioso *&P, int &Cen) {
	int Decision; 
	bool Menu = true;
	P = new Misericordioso;
	P -> V = NULL;
	P -> Vol = false;
	P -> Ami = false;
	P -> Apos = false;
	cout << "Ingrese la cedula del misericordioso: ";
	cin >> P -> Cedula;
	cin.ignore();
	cout << "Ingrese los nombres del misericordioso: ";
	getline(cin, P -> Nombre);
	cout << "Ingrese los apellidos del misericordioso: ";
	getline(cin, P -> Apellido);
	cout << "Ingrese el rol del misericordioso" << endl;
	cout << "[1] ESTUDIANTE DE PREGRADO" << endl;
	cout << "[2] ESTUDIANTE DE POSTGRADO" << endl;
	cout << "[3] DOCENTE" << endl;
	cout << "[4] AUTORIDAD" << endl;
	cout << "[5] PERSONAL ADMINISTRATIVO" << endl;
	cout << "[6] PERSONAL DE SERVICIOS" << endl;
	Decision = getch();
	switch (Decision) {
		case 0x31 :{
			P -> Rol = 0;
			break;
		}
		case 0x32 : {
			P -> Rol = 1;
			break;
		}
		case 0x33 : {
			P -> Rol = 2;
			break;
		}
		case 0x34 : {
			P -> Rol = 3;				
			break;
		}
		case 0x35 : {
			P -> Rol = 4;				
			break;
		}
		case 0x36 : {
			P -> Rol = 5;
			break;
		}
	}
	system("CLS");
	while (Menu) {
		MostrarMisericordioso(P);
		cout << endl;
		cout << "[1] AGREGAR SOLICITUD DE VOLUNTARIADO" << endl;
		cout << "[2] AGREGAR COMO AMIGO SOLIDARIO" << endl;
		cout << "[3] AGREGAR APOSTOLADO" << endl;
		cout << "[4] USUARIO FINALIZADO" << endl;
		Decision = getch();
		switch(Decision) {
			case 0x31 : {
				system("CLS");				
				P -> Vol = true;
				RVoluntariado(P -> V, Cen);
				P -> Voluntariados++;
				system("CLS");				
				break;
			}
			case 0x32 : {
				system("CLS");				
				P -> Ami = true;
				P -> Amigos++;
				system("CLS");
				break;
			}
			case 0x33 : {
				system("CLS");
				P -> Apos = true;
				P -> Apostolados++;
				system("CLS");
				break;
			}
			case 0x34 : {
				Menu = false;
				system("CLS");
				break;
			}
		}
	}
}

void CrearMisericordioso (Misericordioso *&P, bool Usuarios) {
	Misericordioso *Q = NULL, *T = NULL;
	int N, Cen = 0;
	bool Primero = false;
	cout << "Cuantos misericordiosos desea agregar?: ";					
	cin >> N;
	cin.ignore();
	system("CLS");
	if (!Usuarios) {
		for (int i = 1; i <= N; i++) {										
			if (!Primero) {													
				Registro(P, Cen);
				P -> sig = NULL;
				T = P;
				Primero = true;
			}
			else {
				Registro(Q, Cen);
				Q -> sig = NULL;
				T -> sig = Q;
				T = Q;
			}
		}
	}
	else {
		for (int i = 1; i <= N; i++) {									
			while (T -> sig != NULL)									
				T = T -> sig;
			Registro(Q, Cen);									
			Q -> sig = NULL;																						
			T -> sig = Q;
		}
	}
}

void Preorden (Voluntariado *V) {
	if (V != NULL) {
    	cout << V -> Codigo << endl;
    	cout<<V->Nombre<<endl;
		Preorden(V -> izq);
        Preorden(V -> der);
	}
}

void AVLM(ArbolM *&raiz,Misericordioso *P,int dato, int &cen,bool &b) {	
	ArbolM *q,*r,*x;
	if (raiz != NULL) {
		if (dato < raiz->Cedula) {
			AVLM(raiz -> izq,P,dato,cen,b);
			if (cen==1) {
				switch(raiz->FE) {
					case 1 : {
						raiz->FE=0;
						cen=0;
						break;
					}
					case 0 : {
						raiz->FE=-1;
						break;
					}
					case -1 : {
						q=raiz->izq;
						if (q->FE<=0) {
						//rotacion I.I.
							raiz->izq=q->der;
							q->der=raiz;
							raiz->FE=0;
							raiz=q;
						}
						else {
					//rotacion I.D.
							r=q->der;
							raiz->izq=r->der;	
							r->der=raiz;
							q->der=r->izq;
							r->izq=q;
					 		if (r->FE==-1)
								raiz->FE=1;
							else
								raiz->FE=0;
					 		if (r->FE==1)
								q->FE=-1;
					 		else
								q->FE=0;
							raiz=r;	
						}
						raiz->FE=0;
						cen=0;
						break;
					}
				}
			}		
		}
		else {
			if (dato > raiz->Cedula) {
				AVLM(raiz->der,P,dato,cen,b);
				if (cen==1)	{
					switch(raiz->FE) {
						case -1 : {
							raiz->FE=0;
							cen=0;
							break;
						}
						case 0 : {
							raiz->FE=1;
							break;
						}
						case 1 : {
							q=raiz->der;
							if (q->FE>=0){
								//rotacion D.D.
								raiz->der=q->izq;
								q->izq=raiz;
								raiz->FE=0;
								raiz=q;
							}
							else {		
							//rotacion D.I.
								r=q->izq;
								raiz->der=r->izq;
								r->izq=raiz;
								q->izq=r->der;
								r->der=q;
								if (r->FE==1)
									raiz->FE=-1;	
								else
									raiz->FE=0;
								if (r->FE==-1)
									q->FE=1;
								else
									q->FE=0;
								raiz=r;
							}
							raiz->FE=0;
							cen=0;
							break;
						}
					}
				}
			}
		 	else {
				system("CLS");
				cout<<"La clave"<< raiz->Cedula<<" ya existe";
				getch();
			}
		}
	} else {
			raiz= new ArbolM;
		raiz-> Cedula = P->Cedula; 
			raiz->izq =NULL;
		raiz-> der = NULL;
		raiz -> FE = 0; 
		cen = 1; 
	}
	if (!b){
		
			raiz ->Nombre = P->Nombre; 
		raiz->Apellido=P->Apellido;
		raiz->Rol=P->Rol;
		raiz->Amigos=P->Amigos;
		raiz->Apostolados=P->Apostolados;
		raiz->Ami=P->Ami;
		raiz->Apos=P->Apos;
		raiz->Vol=P->Vol;
		raiz->Voluntariados=P->Voluntariados; b=true;
	}

}

void PreordenM (ArbolM *M) {
	if (M != NULL) {
    	
    	cout << "Cedula: " << M -> Cedula << endl;
		cout << "Nombres: " << M -> Nombre << endl;
		cout << "Apellidos: " << M -> Apellido << endl;
		cout << "Rol: " << TipoRol[M-> Rol] << endl;
		if (M -> Vol) {
			cout << "Cantidad de voluntariados: " << M-> Voluntariados << endl;
			}
		if (M -> Ami) {
			cout << "Cantidad de asociados AVESSOC: " << M -> Amigos << endl;
		}
		if (M -> Apos) {
			cout << "Cantidad de apostolados: " << M -> Apostolados << endl;
		}
		PreordenM(M -> izq);
        PreordenM(M -> der);
	}
}

void ConsultasM(ArbolM *M,int &consulta,int &cedula) {
	if (M != NULL) {
    	if (consulta==1){
    		if (M->Cedula==cedula){
    				cout << "Cedula: " << M -> Cedula << endl;
					cout << "Nombres: " << M -> Nombre << endl;
					cout << "Apellidos: " << M -> Apellido << endl;
					cout << "Rol: " << TipoRol[M-> Rol] << endl;
					if (M -> Vol) {
							cout << "Cantidad de voluntariados: " << M-> Voluntariados << endl;
					}
					if (M -> Ami) {
						cout << "Cantidad de asociados AVESSOC: " << M -> Amigos << endl;
					}
					if (M -> Apos) {
					cout << "Cantidad de apostolados: " << M -> Apostolados << endl;
					}	
			}
		}
		if (consulta==2){
			if (M->Voluntariados>=2){
				cout << "Cedula: " << M -> Cedula << endl;
				cout << "Nombres: " << M -> Nombre << endl;
				cout << "Apellidos: " << M -> Apellido << endl;
				cout << "Rol: " << TipoRol[M-> Rol] << endl;
				
				if (M -> Ami) {
				cout << "Cantidad de asociados AVESSOC: " << M -> Amigos << endl;
				}
				if (M -> Apos) {
				cout << "Cantidad de apostolados: " << M -> Apostolados << endl;
				}	
			}
		}
		if (consulta==3){
			if (!M->Apos){
					cout << "Cedula: " << M -> Cedula << endl;
					cout << "Nombres: " << M -> Nombre << endl;
					cout << "Apellidos: " << M -> Apellido << endl;
					cout << "Rol: " << TipoRol[M-> Rol] << endl;
					if (M -> Vol) {
					cout << "Cantidad de voluntariados: " << M-> Voluntariados << endl;
					}
					if (M -> Ami) {
					cout << "Cantidad de asociados AVESSOC: " << M -> Amigos << endl;
					}
	
			}
		}
		ConsultasM(M -> izq,consulta,cedula);
        ConsultasM(M -> der,consulta,cedula);
	}
}

void MenuConsultas(ArbolM *M){
	int consulta,Decision,cedula;
	cout << "[1] DESPLEGAR DATOS DE UN MISERICORDIOSO" << endl;
	cout << "[2] DESPLEGAR DATOS DE MISERICORDIOSOS CON AL MENOS DOS VOLUNTARIADOS" << endl;
	cout << "[3] DESPLEGR DATOS DE MISERICORDIOSOS QUE NO HAN CONSUMADO ALGUN APOSTOLADO" << endl;
	Decision = getch();
	switch (Decision) {
		case 0x31 :{
			cout<<"Cedula a buscar"<<endl;
			cin>>cedula; cin.ignore(); consulta=1;
			ConsultasM(M,consulta,cedula);
			break;
		}
		case 0x32 : { consulta=2;
			ConsultasM(M,consulta,cedula); 
			break;
		}
		case 0x33 : { consulta=3;
			ConsultasM(M,consulta,cedula);
			break;
		}
	}
}

void DatosArbolM(Misericordioso *P, ArbolM *&M){
	int cen=0,dato; bool b=false; 
	while (P!=NULL){  
		AVLM(M,P,P->Cedula,cen,b);
		b=false;
	
		P=P->sig;
	}
	
}


int main() {
	Misericordioso *P = NULL; ArbolM *M=NULL;
	bool Usuarios = false;
	CrearMisericordioso(P, Usuarios); 
 	Preorden(P -> V); 

	DatosArbolM(P,M);
	cout<<"////////////////"<<endl;
	PreordenM(M);
	MenuConsultas(M);
	
	getch();
}
