#pragma once
#include "Tablero.h"

class Juego {
private:
    Tablero tablero;
    int turno; // 1 blanco, 2 negro
public:
    Juego();
    void iniciar();
    void turnoJugador();
    bool mover(int r1, int c1, int r2, int c2);
    bool capturar(int r1, int c1, int r2, int c2);
    bool hayCaptura(int jugador);
    bool puedeCapturarDesde(int r, int c, int jugador);
    void coronar(int r, int c);
    int contarPiezas(int jugador);
};
