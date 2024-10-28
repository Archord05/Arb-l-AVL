//
// Created by anton on 22-10-2024.
//

#include "Arbol.h"

#include <algorithm>
#include <iostream>

#include "Nodo.h"


Arbol::Arbol() {
    this->raiz = nullptr;
}

int Arbol::altura(Nodo* nodo) {
    if (nodo == nullptr) {
        return 0;
    }
    return nodo->getAltura();
}

Nodo * Arbol::rotarDerecha(Nodo* nodo) {


    //* el nodo recibido por parametro es la raiz del subArbol el cual esta desbalanceado
    //* El nodo Izquierdo sera la nueva raiz del subArbol
    //* aux es el subArbol derecho del NodoIzquierdo

    Nodo* nodoIzquierdo = nodo->getHojaIzquierda();
    Nodo* aux = nodoIzquierdo->getHojaDerecha();

    //*Rotación

    //* El nodoIzquierdo se vuele la nueva raiz referenciando a la raiz original a la derecha
    //* y la raiz original ahora referenciara al auxiliar.

    nodoIzquierdo->setHojaDerecha(nodo);
    nodo->setHojaIzquierda(aux);

    //* Alturas
    //* Balance factor = Cuantity node left - Cuantity node right
    nodo->setAltura(1 + std::max(altura(nodo->getHojaIzquierda()), altura(nodo->getHojaDerecha())));
    nodoIzquierdo->setAltura(1 + std::max(altura(nodoIzquierdo->getHojaIzquierda()), altura(nodoIzquierdo->getHojaDerecha())));

    return nodoIzquierdo;

}

Nodo * Arbol::rotarIzquierda(Nodo* nodo) {

    Nodo* nodoDerecho = nodo->getHojaDerecha();
    Nodo* aux = nodoDerecho->getHojaIzquierda();

    nodoDerecho->setHojaIzquierda(nodo);
    nodo->setHojaDerecha(aux);

    nodo->setAltura(1 + std::max(altura(nodo->getHojaIzquierda()), altura(nodo->getHojaDerecha())));
    nodoDerecho->setAltura(1+ std::max(altura(nodoDerecho->getHojaIzquierda()), altura(nodoDerecho->getHojaDerecha())));

    return nodoDerecho;

}

int Arbol::obtenerPesos(Nodo* nodo) {
    if (nodo == nullptr) {
        return 0;
    }
    return altura(nodo->getHojaIzquierda()) - altura(nodo->getHojaDerecha());
}


Nodo * Arbol::insertarNodo(Nodo* nodo, int numero) {
    // Si el nodo es nulo, crear un nuevo nodo
    if (nodo == nullptr) {
        return new Nodo(numero);
    }

    // Inserción recursiva
    if (numero < nodo->getNumero()) {
        // Corregido: se pasaba el nodo actual en lugar del hijo izquierdo
        nodo->setHojaIzquierda(insertarNodo(nodo->getHojaIzquierda(), numero));
    }
    else if (numero > nodo->getNumero()) {
        // Corregido: se pasaba el nodo actual en lugar del hijo derecho
        nodo->setHojaDerecha(insertarNodo(nodo->getHojaDerecha(), numero));
    }
    else {
        // Si el número ya existe, retornar el nodo sin cambios
        return nodo;
    }

    // Actualizar altura
    nodo->setAltura(1 + std::max(altura(nodo->getHojaIzquierda()), altura(nodo->getHojaDerecha())));

    // Calcular factor de balance
    int peso = obtenerPesos(nodo);

    // Casos de rotación
    // Caso Left Left
    if (peso > 1 && numero < nodo->getHojaIzquierda()->getNumero()) {
        return rotarDerecha(nodo);
    }
    // Caso Right Right
    if (peso < -1 && numero > nodo->getHojaDerecha()->getNumero()) {
        return rotarIzquierda(nodo);
    }
    // Caso Left Right
    if (peso > 1 && numero > nodo->getHojaIzquierda()->getNumero()) {
        nodo->setHojaIzquierda(rotarIzquierda(nodo->getHojaIzquierda()));
        return rotarDerecha(nodo);
    }
    // Caso Right Left
    if (peso < -1 && numero < nodo->getHojaDerecha()->getNumero()) {
        nodo->setHojaDerecha(rotarDerecha(nodo->getHojaDerecha()));
        return rotarIzquierda(nodo);
    }

    return nodo;
}


void Arbol::insertarNumero(int numero) {
    raiz = insertarNodo(raiz , numero);
}

void Arbol::preOrder() {

    PreOrderHelper(raiz);
}

void Arbol::PreOrderHelper(Nodo* raiz) {
    if (raiz != nullptr){

        std::cout << raiz->getNumero() << '\n';
        PreOrderHelper(raiz->getHojaIzquierda());
        PreOrderHelper(raiz->getHojaDerecha());
    }
}


