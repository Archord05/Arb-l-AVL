//
// Created by anton on 22-10-2024.
//

#ifndef NODO_H
#define NODO_H



class Nodo {

private:
    int numero;
    Nodo* hojaDerecha;
    Nodo* hojaIzquierda;
    int altura;

public:
    Nodo(int numero);

    //Get´s
    Nodo*getHojaDerecha();
    Nodo*getHojaIzquierda();
    int getNumero();
    int getAltura();

    //Set´s
    void setHojaDerecha(Nodo* hojaDerecha);
    void setHojaIzquierda(Nodo* hojaIzquierda);
    void setNumero(int numero);
    void setAltura(int altura);

};



#endif //NODO_H
