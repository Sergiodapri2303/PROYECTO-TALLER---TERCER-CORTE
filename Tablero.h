#pragma once
#include "Pieza.h"
#include <iostream>
#include <iomanip>

class Tablero {
public:
    Pieza celdas[10][10];
    void inicializar();
    void mostrar() const;
    bool dentro(int r, int c) const;
};
