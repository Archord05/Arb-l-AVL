//
// Created by anton on 22-10-2024.
//


#include "Nodo.h"

Nodo::Nodo(int numero) {
    this->numero = numero;
    this->hojaDerecha = nullptr;
    this->hojaIzquierda = nullptr;
    this->altura = 1;

}

//* Get´s
Nodo * Nodo::getHojaDerecha() {
    return this->hojaDerecha;
}

Nodo * Nodo::getHojaIzquierda() {
    return this->hojaIzquierda;
}

int Nodo::getNumero() {
    return this->numero;
}

int Nodo::getAltura() {
    return this->altura;
}

//* Set´s

void Nodo::setHojaDerecha(Nodo *hojaDerecha) {
    this->hojaDerecha = hojaDerecha;
}

void Nodo::setHojaIzquierda(Nodo *hojaIzquierda) {
    this->hojaIzquierda = hojaIzquierda;
}

void Nodo::setNumero(int numero) {
    this->numero = numero;
}

void Nodo::setAltura(int altura) {
    this->altura = altura;
}
