#include "Tablero.h"
using namespace std;

void Tablero::inicializar() {
    for (int r = 0; r < 10; r++)
        for (int c = 0; c < 10; c++)
            celdas[r][c] = Pieza(0);

    for (int r = 0; r < 4; r++)
        for (int c = 0; c < 10; c++)
            if ((r + c) % 2 == 1) celdas[r][c] = Pieza(2);

    for (int r = 6; r < 10; r++)
        for (int c = 0; c < 10; c++)
            if ((r + c) % 2 == 1) celdas[r][c] = Pieza(1);
}

void Tablero::mostrar() const {
    cout << "\n    ";
    for (int c = 0; c < 10; c++) cout << setw(2) << (c + 1);
    cout << "\n";
    for (int r = 0; r < 10; r++) {
        cout << setw(2) << (r + 1) << "  ";
        for (int c = 0; c < 10; c++) {
            if ((r + c) % 2 == 0) cout << " ";
            cout << setw(2) << celdas[r][c].simbolo();
        }
        cout << "\n";
    }
    cout << "\n";
}

bool Tablero::dentro(int r, int c) const {
    return r >= 0 && r < 10 && c >= 0 && c < 10;
}
