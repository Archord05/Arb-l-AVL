#include <iostream>

#include "Model/Arbol.h"


int main() {

    Arbol arbol;

    arbol.insertarNumero(10);
    arbol.insertarNumero(20);
    arbol.insertarNumero(30);
    arbol.insertarNumero(40);
    arbol.insertarNumero(50);
    arbol.insertarNumero(25);

    std::cout << "Recorrido en preoOrden: \n";

    arbol.preOrder();
}
