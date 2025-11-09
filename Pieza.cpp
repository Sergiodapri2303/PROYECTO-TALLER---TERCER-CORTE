#include "Pieza.h"

char Pieza::simbolo() const {
    if (tipo == 1) return 'w';
    if (tipo == 2) return 'b';
    if (tipo == 3) return 'W';
    if (tipo == 4) return 'B';
    return '.';
}
