//
// Created by anton on 22-10-2024.
//

#ifndef ARBOL_H
#define ARBOL_H
#include "Nodo.h"


class Arbol {

private:
    Nodo* raiz;

public:
    Arbol();
    //Privadas(?)
    int altura(Nodo* nodo);
    Nodo* rotarDerecha(Nodo* nodo);
    Nodo* rotarIzquierda(Nodo* nodo);
    int obtenerPesos(Nodo* nodo);
    Nodo* insertarNodo(Nodo* nodo, int numero);

    void insertarNumero(int numero);
    void preOrder();
    void PreOrderHelper(Nodo* raiz);


};



#endif //ARBOL_H
