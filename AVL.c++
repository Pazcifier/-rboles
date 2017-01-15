#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <iostream>
#include <conio.h>
using namespace std;

struct nodo {
       int inf, fe;
       nodo *izq, *der;
};

void inserta_avl(nodo *&raiz,int dato)

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

}

void Preorden (nodo *raiz) {
     if (raiz != NULL) {
              Preorden(raiz -> izq);
              cout << raiz -> inf << endl;
              Preorden(raiz -> der);
     }
}

int main() {
    nodo *raiz = NULL;
    int dato;
    for (int i = 1; i <= 5; i++) {
        cout << "Inserta un numero: ";
        cin >> dato;
        inserta_avl(raiz, dato);
    }
    Preorden(raiz);
    getch();
}
