#include "Juego.h"
#include <cmath>
#include <iostream>
using namespace std;

Juego::Juego() { turno = 1; }

void Juego::iniciar() {
    tablero.inicializar();
    cout << "Damas Internacionales - Version Basica\nHecho por Sergio Prieto\n";
    while (true) {
        tablero.mostrar();
        cout << "Turno jugador " << (turno == 1 ? "1 (w)" : "2 (b)") << "\n";

        if (contarPiezas(turno) == 0) {
            cout << (turno == 1 ? "Jugador 2 gana!\n" : "Jugador 1 gana!\n");
            break;
        }

        bool obligatoria = hayCaptura(turno);
        if (obligatoria) cout << "Captura obligatoria.\n";

        cout << "Ingrese movimiento r1 c1 r2 c2 (1..10) o 0 para salir: ";
        int a; cin >> a;
        if (a == 0) { cout << "Saliendo...\n"; break; }
        int b, c, d; cin >> b >> c >> d;
        int r1 = a - 1, c1 = b - 1, r2 = c - 1, c2 = d - 1;

        bool ok = false;
        if (obligatoria) ok = capturar(r1, c1, r2, c2);
        else ok = mover(r1, c1, r2, c2) || capturar(r1, c1, r2, c2);

        if (!ok) {
            cout << "Movimiento invalido.\n";
            continue;
        }
        coronar(r2, c2);
        turno = (turno == 1 ? 2 : 1);
    }
}

bool Juego::mover(int r1, int c1, int r2, int c2) {
    if (!tablero.dentro(r1, c1) || !tablero.dentro(r2, c2)) return false;
    Pieza &p = tablero.celdas[r1][c1];
    if (p.tipo == 0) return false;
    if (tablero.celdas[r2][c2].tipo != 0) return false;

    int dr = r2 - r1, dc = c2 - c1;
    if (abs(dr) != 1 || abs(dc) != 1) return false;
    if (p.tipo == 1 && dr > 0) return false;
    if (p.tipo == 2 && dr < 0) return false;

    tablero.celdas[r2][c2] = p;
    tablero.celdas[r1][c1] = Pieza(0);
    return true;
}

bool Juego::capturar(int r1, int c1, int r2, int c2) {
    if (!tablero.dentro(r1, c1) || !tablero.dentro(r2, c2)) return false;
    Pieza &p = tablero.celdas[r1][c1];
    if (p.tipo == 0) return false;

    int dr = r2 - r1, dc = c2 - c1;
    if (abs(dr) != 2 || abs(dc) != 2) return false;

    int mr = (r1 + r2) / 2, mc = (c1 + c2) / 2;
    Pieza &enemigo = tablero.celdas[mr][mc];

    if (p.esBlanca() && !enemigo.esNegra()) return false;
    if (p.esNegra() && !enemigo.esBlanca()) return false;

    tablero.celdas[mr][mc] = Pieza(0);
    tablero.celdas[r2][c2] = p;
    tablero.celdas[r1][c1] = Pieza(0);
    return true;
}

bool Juego::puedeCapturarDesde(int r, int c, int jugador) {
    int dirs[4][2] = {{-1,-1},{-1,1},{1,-1},{1,1}};
    Pieza &p = tablero.celdas[r][c];
    if (p.tipo == 0) return false;

    for (int d = 0; d < 4; d++) {
        int r1 = r + dirs[d][0], c1 = c + dirs[d][1];
        int r2 = r + 2 * dirs[d][0], c2 = c + 2 * dirs[d][1];
        if (!tablero.dentro(r2, c2)) continue;
        Pieza &enemigo = tablero.celdas[r1][c1];
        if (p.esBlanca() && enemigo.esNegra() && tablero.celdas[r2][c2].tipo == 0) return true;
        if (p.esNegra() && enemigo.esBlanca() && tablero.celdas[r2][c2].tipo == 0) return true;
    }
    return false;
}

bool Juego::hayCaptura(int jugador) {
    for (int r = 0; r < 10; r++)
        for (int c = 0; c < 10; c++)
            if (tablero.celdas[r][c].tipo != 0)
                if ((jugador == 1 && tablero.celdas[r][c].esBlanca()) ||
                    (jugador == 2 && tablero.celdas[r][c].esNegra()))
                    if (puedeCapturarDesde(r, c, jugador)) return true;
    return false;
}

void Juego::coronar(int r, int c) {
    Pieza &p = tablero.celdas[r][c];
    if (p.tipo == 1 && r == 0) p.tipo = 3;
    if (p.tipo == 2 && r == 9) p.tipo = 4;
}

int Juego::contarPiezas(int jugador) {
    int cont = 0;
    for (int r = 0; r < 10; r++)
        for (int c = 0; c < 10; c++) {
            Pieza &p = tablero.celdas[r][c];
            if (jugador == 1 && p.esBlanca()) cont++;
            if (jugador == 2 && p.esNegra()) cont++;
        }
    return cont;
}
