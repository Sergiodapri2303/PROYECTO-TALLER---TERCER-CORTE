# ♟️ Proyecto: Damas Internacionales - Versión Básica y Modular

**Autor:** Sergio Prieto Vargas  
**Lenguaje:** C++  
**Modo de juego:** Consola  
**Materia:** Pensamiento algoritmico 

---

## 🧩 Descripción general
Este proyecto recrea el clásico juego **Damas Internacionales** en un tablero de **10x10** casillas.  
Está desarrollado en **C++**, bajo una estructura **modular** y con un diseño claro que facilita la comprensión del código.  

El objetivo del juego es capturar todas las piezas del oponente o bloquearlo para que no tenga más movimientos válidos.  
Cada jugador comienza con 20 piezas colocadas en las casillas oscuras de su lado del tablero.

---

## ⚙️ Estructura del proyecto
Damas│
├── Pieza.h
├── Pieza.cpp
├── Tablero.h
├── Tablero.cpp
├── Juego.h
├── Juego.cpp
├── main.cpp


---

## 🕹️ Cómo jugar

- Al iniciar se muestra el tablero de **10x10**.  
- Cada jugador tiene **20 piezas** (`w` = blancas, `b` = negras).  
- Las piezas se mueven **en diagonal hacia adelante**.  
- Se capturan piezas rivales **saltando sobre ellas** hacia una casilla vacía.  
- **La captura es obligatoria** si hay una disponible.  
- Cuando una pieza llega al extremo opuesto, **se convierte en Dama** (`W` o `B`).  
- Para salir del juego, ingresa **0**.  

---

## 📘 Reglas básicas implementadas

1. Tablero de **10x10** alternando colores.  
2. Cada jugador inicia con **20 piezas**.  
3. Movimiento diagonal simple hacia adelante.  
4. Captura obligatoria hacia adelante o hacia atrás.  
5. **Coronación automática** de damas.  
6. **Detección automática de victoria.**  
7. Validación de entradas y errores.  

---

## 💡 Innovaciones implementadas

### 🧱 Estructura modular (POO básica)
El código está dividido en clases (`Pieza`, `Tablero`, `Juego`) y archivos `.h` / `.cpp`, siguiendo buenas prácticas de programación orientada a objetos.

### 👑 Coronación automática de damas
Las piezas se convierten automáticamente en dama (`W` o `B`) al llegar al otro extremo del tablero.

### ⚔️ Capturas obligatorias
El sistema detecta cuando un jugador tiene capturas disponibles y no permite movimientos normales hasta que se capture.

### ✅ Validación y control de reglas
Se comprueban coordenadas válidas, movimientos dentro del tablero y turnos correctos para evitar errores o comportamientos incorrectos.

### 🧭 Interfaz textual amigable
Se muestra un tablero numerado, los turnos actuales, mensajes claros y un formato ordenado que facilita la experiencia del jugador.

### 🏁 Detección automática de fin de juego
Cuando un jugador se queda sin piezas, el programa declara automáticamente al ganador y finaliza la partida.

### 💾 Código claro, funcional y escalable
Aunque se mantiene básico, la estructura permite extender fácilmente el juego con futuras funciones (guardado, tiempo por turno, IA, colores, etc.).

---

## 🚀 Instrucciones de compilación y ejecución

### 💻 Compilar
En consola o terminal (Linux, macOS o Windows con g++):
```bash
g++ main.cpp Juego.cpp Tablero.cpp Pieza.cpp -o damas -std=c++17



