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

const char *Grupos[] = {
	"Sociedad de Ingenieros Automotrices (FSAE)",
	"Eco UCAB",
	"Voluntariado de Trabajo en Establecimientos Penitenciarios (VTEP)",
	"Voluntariado  de Trabajo en Asesoria Juridica (VTAJ)",
	"Voluntariado de Letras (Volet)",
	"Escuela de Comunicacion Social",
	"Voluntariado de la Escuela de Educacion (EDUCAB)",
	"Voluntariado de Administracion y Contaduria (VAC)",
	"Voluntariado de Economia (VEC)",
	"Voluntarios en Red",
	"Voluntarios Profesionales",
	"Voluntarios Las Mayas",
	"Pastoral",
	"Coral Infantil, Narra Cuentos",
	"Propedeutico Verbal",
	"Propedeutico Numerico",
	"Proyecto de Voluntariado de Ciencias Sociales (PROVOCS)",
	"Voluntariado de Psicologia",
	"Voluntariado de Derechos Humanos"
};

struct Voluntariado {
	int FE;
	int Codigo;
	string Nombre;
	string Objetivo;
	int CupoMax;
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

struct ArbolM {
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

int VoluntariadosUCAB() {					//Función que muestra todos los código de voluntariado del sistema
	int Codigo;
	do {
		system("CLS");
		cout << endl << "		VOLUNTARIADOS UCAB" << endl << endl;
		cout << "1001 - Sociedad de Ingenieros Automotrices (FSAE)" << endl;
		cout << "1002 - Eco UCAB" << endl;
		cout << "1003 - Voluntariado de Trabajo en Establecimientos Penitenciarios (VTEP)" << endl;
		cout << "1004 - Voluntariado  de Trabajo en Asesoria Juridica (VTAJ)" << endl;
		cout << "1005 - Voluntariado de Letras (Volet)" << endl;		
		cout << "1006 - Escuela de Comunicacion Social" << endl;
		cout << "1007 - Voluntariado de la Escuela de Educacion (EDUCAB)" << endl;
		cout << "1008 - Voluntariado de Administracion y Contaduria (VAC)" << endl;		
		cout << "1009 - Voluntariado de Economia (VEC)" << endl;
		cout << "1010 - Voluntarios en Red" << endl;
		cout << "1011 - Voluntarios Profesionales" << endl;
		cout << "1012 - Voluntarios Las Mayas" << endl;
		cout << "1013 - Pastoral" << endl;
		cout << "1014 - Coral Infantil, Narra Cuentos" << endl;
		cout << "1015 - Propedeutico Verbal" << endl;
		cout << "1016 - Propedeutico Numerico" << endl;
		cout << "1017 - Proyecto de Voluntariado de Ciencias Sociales (PROVOCS)" << endl;
		cout << "1018 - Voluntariado de Psicologia" << endl;
		cout << "1019 - Voluntariado de Derechos Humanos" << endl;
		cout << endl << "Ingrese codigo de agrupacion del voluntariado: ";
		cin >> Codigo;
	} while ((Codigo < 1001) || (Codigo > 1019));	//Dependiendo de si este está en el rango o no, se registra el código en el sistema
	return Codigo;
}

void LlenadoV (Misericordioso *&P, int Codigo) {		//Funcion de llenado de Voluntariado
	string Nombre;			
	switch (Codigo) {									//Dependiendo del código que se de, se asignará cupo y nombre del voluntariado
		case 1001 : {
			Nombre = "Sociedad de Ingenieros Automotrices (FSAE)";
			P -> V -> CupoMax = 15;
			break;
		}
		case 1002 : {
			Nombre = "Eco UCAB";
			P -> V -> CupoMax = 20;
			break;
		}
		case 1003 : {
			Nombre = "Voluntariado de Trabajo en Establecimientos Penitenciarios (VTEP)";
			P -> V -> CupoMax = 15;
			break;
		}
		case 1004 : {
			Nombre = "Voluntariado de Trabajo en Asesoria Juridica (VTAJ)";
			P -> V -> CupoMax = 7;
			break;
		}
		case 1005 : {
			Nombre = "Voluntariado de Letras (Volet)";
			P -> V -> CupoMax = 18;
			break;
		}
		case 1006 : {
			Nombre = "Escuela de Comunicación Social";
			P -> V -> CupoMax = 35;
			break;
		}
		case 1007 : {
			Nombre = "Voluntariado de la Escuela de Educacion (EDUCAB)";
			P -> V -> CupoMax = 60;
			break;
		}
		case 1008 : {
			Nombre = "Voluntariado de Administración y Contaduría (VAC)";
			P -> V -> CupoMax = 15;
			break;
		}
		case 1009 : {
			Nombre = "Voluntariado de Economía (VEC)";
			P -> V -> CupoMax = 20;
			break;
		}
		case 1010 : {
			Nombre = "Voluntarios en Red" ;
			P -> V -> CupoMax = 40;
			break;
		}
		case 1011 : {
			Nombre = "Voluntarios Profesionales";
			P -> V -> CupoMax = 4;
			break;
		}
		case 1012 : {
			Nombre = "Voluntarios Las Mayas";
			P -> V -> CupoMax = 5;
			break;
		}
		case 1013 : {
			Nombre = "Pastoral";
			P -> V -> CupoMax = 10;
			break;
		}
		case 1014 : {
			Nombre = "Coral Infantil, Narra Cuentos";
			P -> V -> CupoMax = 10;
			break;
		}
		case 1015 : {
			Nombre = "Propedeutico Verbal";
			P -> V -> CupoMax = 15;
			break;
		}
		case 1016 : {
			Nombre = "Propedeutico Numerico";
			P -> V -> CupoMax = 21;
			break;
		}
		case 1017 : {
			Nombre = "Proyecto de Voluntariado de Ciencias Sociales";
			P -> V -> CupoMax = 12;
			break;
		}
		case 1018 : {
			Nombre = "Voluntariado de Psicologia";
			P -> V -> CupoMax = 42;
			break;
		}
		case 1019 : {
			Nombre = "Voluntario de Derechos Humanos";
			P -> V -> CupoMax = 500;
			break;
		}
	}
	P -> V -> Nombre = Nombre;
	P -> V -> Codigo = Codigo;
	cout << "Ingrese el objetivo de la agrupacion: ";
	getline(cin, P -> V -> Objetivo);	
}

void MostrarMisericordiosoArbol (ArbolM *M) {	//Función que muestra todos los datos del arbol de misericordiosos
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
	cout << endl;
}

void MostrarMisericordioso (Misericordioso *P) {	//Función que muestra todos los datos de la lista de misericordiosos
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

void MostrarVoluntariado (Voluntariado *V) {		//Función que muestra los voluntariados de un misericordioso
	cout << "Codigo de la agrupacion: " << V -> Codigo << endl;
	cout << "Nombre de la agrupacion: " << V -> Nombre << endl;
	cout << "Objetivo de la agrupacion: " << V -> Objetivo << endl;
	cout << "Cupo maximo: " << V -> CupoMax << endl;
	cout << endl;
}

void AVLvol(Misericordioso *P, Voluntariado *&raiz,int dato, int &cen,bool &a) {	//Función que crea el árbol de voluntariados
	Voluntariado *q,*r,*x;
	if (raiz!=NULL) {		//Se observa si la raíz es distinto de NULL
		if (dato < raiz->Codigo) {			//Si el dato dado es menor que el dato de la raíz, entonces se llama de nuevo a la función y se lleva al otro caso (cuando el dato es menor)
			AVLvol(P, raiz -> izq,dato,cen,a);
			if (cen==1) {		//Cuando se crea un nodo, se colocan los factores de equilibrios necesarios
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
						if (q->FE<=0) {		//Y se revisa cada uno de los nodos para ver si es necesaria hacer una rotación
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
			if (dato > raiz->Codigo) {			//El mismo caso ocurre para cuando el dato dado es mayor que el de la raíz
				AVLvol(P, raiz->der,dato,cen,a);
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
		 	else {		//Si un misericordioso se le ingresa el mismo codigo, se da a conocer que no se puede ingresar el mismo dato
				system("CLS");
				cout<<"La clave"<< raiz->Codigo<<" ya existe";
				getch();
			}
		}
	}
	else {		//Si no hay raiz, se crea una
		raiz= new(Voluntariado);
		raiz->Codigo=dato;
		raiz->izq=NULL;
		raiz->der=NULL;
		raiz->FE=0;
		cen=1;
		P -> Voluntariados++;
	}
	if (!a) {		//Función de ingreso para obtener el codigo y la descripcion
		LlenadoV(P, dato);
	}
}

void RVoluntariado (Misericordioso *P, Voluntariado *&V, int &Cen) { //Función encargada de todos los llamados de voluntariados
	int Dato; 
	bool a = false;
	Dato = VoluntariadosUCAB();
	cin.ignore(); 
	AVLvol(P,V,Dato,Cen,a);
}

void AmigoSolidarioInfo () {				//Funcion encargada del registo de amigos solidarios de un misericordioso			
	int Decision, Aporte, Frecuencias;
	string Codigo, Nombre;
	do {
		cout << "Ingrese el codigo de carnet de Amigo Solidario (tres numeros/caracteres): 4M150L-";	
		getline(cin, Codigo);																																	
	} while (Codigo.length() != 3);																		
	do {
		cout << "Ingrese el codigo de asociado AVESSOC (tres numeros/caracteres): 4V3550C-";
		getline(cin, Codigo);
	} while (Codigo.length() != 3);
	cout << "Ingrese el nombre de asociado AVESSOC: ";
	getline(cin, Nombre);
	cout << "Tipo de aporte de Amigo Solidario" << endl << endl;	
	cout << "[1] MONETARIO" << endl;
	cout << "[2] INSUMOS MEDICOS" << endl;
	cout << "[3] MEDICINAS" << endl;
	cout << "[4] OTROS" << endl;
	Decision = getch();
	cout << "Frecuencia de pago" << endl << endl;
	cout << "[1] MENSUAL" << endl;
	cout << "[2] BIMENSUAL" << endl;
	cout << "[3] TRIMESTRAL" << endl;
	cout << "[4] SEMESTRAL" << endl;
	cout << "[5] ANUAL" << endl;
	cout << "[6] UNICO" << endl;
	Decision = getch();
}

void ApostoladoInfo () {			//Funcion encargada del registro de apostolados de un misericordioso			
	int Decision;
	string Descripcion;
	cout << "Ingrese tipo de apostolado" << endl << endl;
	cout << "[1] TESTIMONIO" << endl;
	cout << "[2] PALABRA" << endl;
	cout << "[3] ACCION" << endl;
	cout << "[4] ORACION" << endl;
	cout << "[5] SACRIFICIO" << endl;
	Decision = getch();
	cout << "Ingrese la descripcion de apostolado: ";
	getline(cin, Descripcion);	
}

void Registro (Misericordioso *&P, int &Cen) {	//Función encargada del registro completo de misericordioso
	int Decision;
	bool Menu = true;
	P = new Misericordioso;
	P -> V = NULL;
	P -> Vol = false;
	P -> Ami = false;
	P -> Apos = false;
	P -> Voluntariados = 0;
	P -> Amigos = 0;
	P -> Apostolados = 0;
	cout << "Ingrese la cedula del misericordioso: ";			//Se pide su cédula, nombre, apellido y rol en la universidad
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
	while (Menu) {			//Posteriormente, se da el llenado de sus actividades, cada opción es una actividad distinta
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
				RVoluntariado(P, P -> V, Cen);
				system("CLS");				
				break;
			}
			case 0x32 : {
				system("CLS");				
				P -> Ami = true;
				AmigoSolidarioInfo();
				P -> Amigos++;
				system("CLS");
				break;
			}
			case 0x33 : {
				system("CLS");
				P -> Apos = true;
				ApostoladoInfo();
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

void CrearMisericordioso (Misericordioso *&P, bool Usuarios) { //Función encargada de la creacion de misericordiosos
	Misericordioso *Q = NULL, *T = NULL;
	int N, Cen = 0;
	bool Primero = false;
	cout << "Cuantos misericordiosos desea agregar?: ";					//Se pide la cantidad de misericordiosos a agregar
	cin >> N;
	cin.ignore();
	system("CLS");
	if (!Usuarios) {									//Dependiendo de si hay misericordiosos registados o no, se hará una creación de listas inserando al final o una inserción al final
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

void AVLM(ArbolM *&raiz,Misericordioso *P,int dato, int &cen,bool &b) {	//Función encargada de la creación de árbol de misericordiosos
	ArbolM *q,*r,*x;							//Posee el mismo proceso de la creación del árbol de voluntariados, a excepción que se toma de la lista de misericordiosos ya creada
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
	} 
	else {
		raiz= new ArbolM;
		raiz-> Cedula = P->Cedula; 
		raiz->izq =NULL;
		raiz-> der = NULL;
		raiz -> FE = 0; 
		cen = 1; 
	}
	if (!b) {		
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

void PreordenV (Voluntariado *V) {			//Funciones de recorridos de los árboles
	if (V != NULL) {
    	MostrarVoluntariado(V); 
		PreordenV(V -> izq);
        PreordenV(V -> der);
	}
}

void InordenV (Voluntariado *V) {
	if (V != NULL) {
		InordenV(V -> izq);
		MostrarVoluntariado(V); 
        InordenV(V -> der);
	}
}

void PosordenV (Voluntariado *V) {
	if (V != NULL) {
        PosordenV(V -> der);
    	MostrarVoluntariado(V);  
		PosordenV(V -> izq);      
	}
}

void PreordenM (ArbolM *M) {
	if (M != NULL) {   	
    	MostrarMisericordiosoArbol(M);
		PreordenM(M -> izq);
        PreordenM(M -> der);
	}
}

void InordenM (ArbolM *M) {
	if (M != NULL) {   	
		InordenM(M -> izq);
    	MostrarMisericordiosoArbol(M);		
        InordenM(M -> der);
	}
}

void PosordenM (ArbolM *M) {
	if (M != NULL) {   	
        PosordenM(M -> der);
    	MostrarMisericordiosoArbol(M);		
		PosordenM(M -> izq);
	}
}

void DatosArbolM(Misericordioso *P, ArbolM *&M){	//Función encargada de llamar y convertir la lista de misericordiosos a árbol
	int cen=0,dato; bool b=false; 
	while (P!=NULL) {  
		AVLM(M,P,P->Cedula,cen,b);
		b=false;	
		P=P->sig;
	}	
}
							// /////// FUNCIONES DE CONSULTAS /////// //
							
void BuscarCodigoVoluntariado (Misericordioso *P, int X, bool Primero) {	//Función encargada de buscar a los voluntariados con un código dado
	if (P != NULL) {		//Se recorre por cada nodo de la lista de misericordiosos su árbol, si este tiene el código que se dio anteriormente, se imprime
		if ((P -> Vol) && (P -> V -> Codigo == X)) {
			if (!Primero) {
				cout << "Estos son los misericordiosos que pertenecen a este voluntariado:" << endl << endl;
				Primero = true;
			}
			MostrarMisericordioso(P);
			cout << endl;
		}
		BuscarCodigoVoluntariado(P -> sig, X, Primero);
	}
}

void MayorCantidad (Misericordioso *P, int &Mayor) {		//Función encargada de buscar al misericordioso con el mayor número de voluntariados
	if (P != NULL) {									//Se recorre cada nodo de la lista de misericordiosos y se compara quién posee mayor cantidad de voluntariados
		if (P -> Voluntariados > Mayor) {
			Mayor = P -> Voluntariados;
		}
		MayorCantidad(P -> sig, Mayor);
	}
}

void MasVoluntariados (Misericordioso *P, bool Primero, int X) {	//Función que imprime al misericordioso con la mayor cantidad de voluntariados
	if (P != NULL) {							//Dada la función anterior, se compara cada cantidad de voluntariados de los misericordiosos y se imprimen los que coincidan en cantidad con el mayor
		if (P -> Voluntariados == X) {
			if (!Primero) {
				cout << "Estos son los misericordiosos con la mayor cantidad de voluntariados:" << endl << endl;
				Primero = true;
			}
			MostrarMisericordioso(P);
			cout << endl;
		}
		MasVoluntariados(P -> sig, Primero, X);
	}
}

void CedulaNombre (Misericordioso *P) {		//Función que se encarga de mostrar la cédula y el nombre del misericordioso de forma recursiva
	if (P != NULL) {
		cout << " " << P -> Cedula << "		";
		cout << P -> Nombre << " " << P -> Apellido;
		cout << endl;
		CedulaNombre(P -> sig);
	}
}

void MostrarCedulaNombre (Misericordioso *P) {		//Función que ordena y muestra las cédulas de los misericordiosos registrados
	cout << endl;
	cout << "  CEDULA";
	cout << "		    NOMBRE Y APELLIDO" << endl << endl;
	CedulaNombre(P);
	cout << endl;
}

void BuscarMisericordioso (Misericordioso *&P, int X) {		//Función que dada una cédula, imprime a un misericoridoso
	if ((P != NULL) && (P -> Cedula != X)) {
		BuscarMisericordioso(P -> sig, X);
	}
}

void ConsultasM(ArbolM *M,int &consulta,int &cedula) {		//Función que imrpime las consultas 1, 2 y 3
	if (M != NULL) {
    	if (consulta==1) {			//CONSULTA 1: Dada una cédula, mostrar los datos del misericordioso en el árbol
    		if (M->Cedula==cedula) {		//Se da una cédula y se busca coincidencia, si la hay, se imprime
				MostrarMisericordiosoArbol(M);	
			}
		}
		if (consulta==2) {		//CONSULTA 2: Mostrar los misericordiosos con más de dos voluntariados
			if (M->Voluntariados>=2) {			//Se leen cada una de las cantidades de voluntariados de los misericordiosos, si son más de dos, se imprime
				cout << "Estos son los misericordiosos con mas de dos voluntariados" << endl << endl;
				MostrarMisericordiosoArbol(M);	
			}
		}
		if (consulta==3) {		//CONSULTA 3: Mostrar los misericordiosos sin apostolados
			if (!M->Apos ) {			//Se leen cada una de las cantidades de apostolados, si esta es 0, entonces se imprime
				cout << "Estos son los misericordiosos sin apostolados" << endl << endl;
				MostrarMisericordiosoArbol(M);	
			}
		}
		ConsultasM(M -> izq,consulta,cedula);			//Cada una de las consultas, dependiendo la eleguida se repite con cada nodo del árbol en preorden
        ConsultasM(M -> der,consulta,cedula);
	}
}

void MenuConsultas (ArbolM *M, Misericordioso *P, bool ArbolMisericordioso) {	//Función que muestra el menú de consultas
	int consulta, Decision, Cedula, Codigo, Mayor = 0;
	bool Menu = true, Primero = false;
	while (Menu) {
		cout << "	Por favor, elija una opcion" << endl << endl;
		if (ArbolMisericordioso) {
			cout << "[1] MOSTRAR TODOS LOS DATOS DE UN MISERICORDIOSO" << endl;
			cout << "[2] MOSTRAR MISERICORDIOSOS CON DOS VOLUNTARIADOS O MAS" << endl;
			cout << "[3] MOSTRAR MISERICORDIOSOS SIN APOSTOLADOS" << endl;
		}
		cout << "[4] MOSTRAR TODOS LOS MISERICORDIOSOS EN UN VOLUNTARIADO DADO" << endl;
		cout << "[5] MOSTRAR AL/LOS MISERICORDIOSO/S CON LA MAYOR CANTIDAD DE VOLUNTARIADOS" << endl;
		cout << "[6] MOSTRAR EL VOLUNTARIADO CON MAYOR CANTIDAD DE MIEMBROS" << endl;
		cout << "[7] REGRESAR AL MENU" << endl;
		Decision = getch();
		switch (Decision) {
			case 0x31 : {
				system("CLS");
				if (ArbolMisericordioso) {
					cout << "Introduzca la cedula del misericordioso a recorrer sus voluntariados: ";
					cin >> Cedula;
					system("CLS");
					cout << endl;
					consulta=1;
					ConsultasM(M,consulta,Cedula);
					Final();
				}
				break;
			}
			case 0x32 : { 
				system("CLS");
				if (ArbolMisericordioso) {
					consulta=2;
					ConsultasM(M,consulta,Cedula);
					Final();
				}
				break;
			}
			case 0x33 : {
				system("CLS");
				if (ArbolMisericordioso) {
					consulta=3;
					ConsultasM(M,consulta,Cedula);
					Final();
				}
				break;
			}
			case 0x34 : {
				system("CLS");
				cout << "Ingrese codigo de voluntariado a buscar: ";
				cin >> Codigo;
				system("CLS");
				BuscarCodigoVoluntariado(P, Codigo, Primero);
				Final();
				break;
			}
			case 0x35 : {
				system("CLS");
				MayorCantidad(P, Mayor);
				MasVoluntariados(P, Primero, Mayor);
				Final();
				break;
			}
			case 0x36 : {
				system("CLS");
				cout << "No hicimos esta parte profesor";
				Final();
				break;
			}
			case 0x37 : {
				Menu = false;
				break;
			}
		}
	}
}

int main() {			//Programa principal
	int Codigo, Mayor = 0, Decision;
	Misericordioso *P = NULL, *auxP = NULL;
	ArbolM *M = NULL;
	bool Usuarios = false, Primero = false, Menu = true, MenuRecorridos = true, ArbolMisericordioso = false;
	while (Menu) {
		system("CLS");
		cout << "	Bienvenido al registro de misericordiosos v.47801es" << endl;
		cout << "		Por favor, elija una opcion" << endl << endl;
		cout << "[1] AGREGAR MISERICORDIOSO" << endl;
		if (Usuarios) {
			cout << "[2] CREAR ARBOL DE MISERICORDIOSOS" << endl;
			cout << "[3] ACTUALIZAR VOLUNTARIADO" << endl;
			cout << "[4] RECORRER ARBOLES" << endl;
			cout << "[5] CONSULTAS" << endl;
		}
		cout << "[6] SALIR" << endl;
		Decision = getch();
		switch (Decision) {
			case 0x31 : {
				system("CLS");
				CrearMisericordioso(P, Usuarios);
				Usuarios = true;
				ArbolMisericordioso = false;
				break;
			}
			case 0x32 : {
				system("CLS");
				if (Usuarios) {
					DatosArbolM(P, M);
					cout << "Arbol de misericordiosos creado" << endl;
					Final();
					ArbolMisericordioso = true;
				}
				break;
			}
			case 0x33 : {
				cout << "No hicimos esto profesor";
				Final();
				break;
			}
			case 0x34 : {
				system("CLS");
				if (Usuarios) {
					MenuRecorridos = true;
					cout << "Por favor, elija que arbol desea recorrer" << endl << endl;
					if (ArbolMisericordioso) {
						cout << "[1] ARBOL DE MISERICORDIOSOS" << endl;
					}
					cout << "[2] ARBOL DE VOLUNTARIADOS" << endl;
					cout << "[3] REGRESAR AL MENU" << endl;
					Decision = getch();
					switch (Decision) {
						case 0x31 : {
							system("CLS");
							if (ArbolMisericordioso) {
								while (MenuRecorridos) {
									cout << "Por favor eliga modo de recorrido" << endl << endl;
									cout << "[1] RECORRIDO PREORDEN" << endl;
									cout << "[2] RECORRIDO INORDEN" << endl;
									cout << "[3] RECORRIDO POSORDEN" << endl;
									cout << "[4] REGRESAR AL MENU" << endl;
									Decision = getch();
									switch (Decision) {
										case 0x31 : {
											system("CLS");
											cout << "Estos son los misericordiosos registrados en Preorden" << endl << endl;
											PreordenM(M);
											Final();
											break;
										}
										case 0x32 : {
											system("CLS");
											cout << "Estos son los misericordiosos registrados en Inorden" << endl << endl;
											InordenM(M);
											Final();
											break;
										}
										case 0x33 : {
											system("CLS");
											cout << "Estos son los misericordiosos registrados en Posorden" << endl << endl;
											PosordenM(M);
											Final();
											break;
										}
										case 0x34 : {
											system("CLS");
											MenuRecorridos = false;
											break;
										}
									}
								}
							}
							break;
						}
						case 0x32 : {
							system("CLS");
							auxP = P;
							MostrarCedulaNombre(P);
							cout << "Introduzca la cedula del misericordioso a recorrer sus voluntariados: ";
							cin >> Codigo;
							BuscarMisericordioso(auxP, Codigo);
							system("CLS");
							while (MenuRecorridos) {
								cout << "Por favor eliga modo de recorrido" << endl << endl;
								cout << "[1] RECORRIDO PREORDEN" << endl;
								cout << "[2] RECORRIDO INORDEN" << endl;
								cout << "[3] RECORRIDO POSORDEN" << endl;
								cout << "[4] REGRESAR AL MENU" << endl;
								Decision = getch();
								switch (Decision) {
									case 0x31 : {
										system("CLS");
										cout << "Estos son los voluntariados del misericordioso en Preorden" << endl << endl;
										PreordenV(auxP -> V);
										Final();
										break;
									}
									case 0x32 : {
										system("CLS");
										cout << "Estos son los voluntariados del misericordioso en Inorden" << endl << endl;
										InordenV(auxP -> V);
										Final();
										break;
									}
									case 0x33 : {
										system("CLS");
										cout << "Estos son los voluntariados del misericordioso en Posorden" << endl << endl;
										PosordenV(auxP -> V);
										Final();
										break;
									}
									case 0x34 : {
										system("CLS");
										MenuRecorridos = false;
										break;
									}
								}
							}
							break;
						}
					}
				}
				break;
			}
			case 0x35 : {
				system("CLS");
				if (Usuarios) {
					MenuConsultas(M, P, ArbolMisericordioso);
				}
				break;
			}
			case 0x36 : {
				system("CLS");
				Menu = false;
				break;
			}
		}
	}
}
