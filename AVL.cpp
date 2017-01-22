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
	Misericordioso *sig, *der, *izq;
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

void AVLvol(Voluntariado *&raiz,int dato, int &cen) {	
	Voluntariado *q,*r,*x;
	if (raiz != NULL) {
		if (dato < raiz->Codigo) {
			AVLvol(raiz -> izq,dato,cen);
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
				AVLvol(raiz->der,dato,cen);
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
		raiz = new Voluntariado;
		raiz -> Codigo = dato;
		raiz -> izq = NULL;
		raiz -> der = NULL;
		raiz -> FE = 0;
		cen = 1;
	}
}

void RVoluntariado (Voluntariado *&V, int &Cen) {
	int Dato;
	cout << "Codigo de agrupacion: ";
	cin >> Dato;
	cin.ignore();
	if (V != NULL) {
		cout << "Nombre de la agrupacion: ";
		getline(cin, V -> Nombre);
		cout << "Objetivo de la agrupacion: ";
		getline(cin, V -> Objetivo);
	}
	AVLvol(V,Dato,Cen);
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
		Preorden(V -> izq);
        Preorden(V -> der);
	}
}

int main() {
	Misericordioso *P = NULL;
	bool Usuarios = false;
	CrearMisericordioso(P, Usuarios);
	Preorden(P -> V);
	getch();
}
