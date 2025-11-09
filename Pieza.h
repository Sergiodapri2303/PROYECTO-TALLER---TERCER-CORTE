#pragma once
struct Pieza {
    int tipo; // 0 vacío, 1 blanco, 2 negro, 3 dama blanca, 4 dama negra
    Pieza(int t = 0) { tipo = t; }
    bool esBlanca() const { return tipo == 1 || tipo == 3; }
    bool esNegra() const { return tipo == 2 || tipo == 4; }
    bool esDama() const { return tipo == 3 || tipo == 4; }
    char simbolo() const;
};
