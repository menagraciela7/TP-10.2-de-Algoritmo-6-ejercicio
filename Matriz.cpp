#include "Matriz.hpp"

namespace Algebra {

    // Inicializa las dimensiones y pide memoria
    Matriz::Matriz(int f, int c) : filas(f), columnas(c), datos(nullptr) {
        asignarMemoria(filas, columnas);
    }

    // El destructor garantiza que no queden fugas de memoria (Memory Leaks)
    Matriz::~Matriz() {
        liberarMemoria();
    }

    void Matriz::asignarMemoria(int f, int c) {
        datos = new int*[f];
        for (int i = 0; i < f; ++i) {
            datos[i] = new int[c]{0}; // Inicialización en cero
        }
    }

    void Matriz::liberarMemoria() {
        if (datos != nullptr) {
            for (int i = 0; i < filas; ++i) {
                delete[] datos[i];
            }
            delete[] datos;
            datos = nullptr;
        }
    }

    int Matriz::getFilas() const { return filas; }
    int Matriz::getColumnas() const { return columnas; }

    void Matriz::setValor(int f, int c, int valor) {
        if (f >= 0 && f < filas && c >= 0 && c < columnas) {
            datos[f][c] = valor;
        }
    }

    int Matriz::getValor(int f, int c) const {
        if (f >= 0 && f < filas && c >= 0 && c < columnas) {
            return datos[f][c];
        }
        return 0; 
    }

    void Matriz::leerDeConsola() {
        for (int i = 0; i < filas; ++i) {
            for (int j = 0; j < columnas; ++j) {
                std::cout << "Elemento [" << i << "][" << j << "]: ";
                std::cin >> datos[i][j];
            }
        }
    }

    void Matriz::mostrar() const {
        for (int i = 0; i < filas; ++i) {
            std::cout << "[ ";
            for (int j = 0; j < columnas; ++j) {
                std::cout << datos[i][j] << " ";
            }
            std::cout << "]\n";
        }
    }

    // Algoritmo de trasposición utilizando punteros y abstracción de la clase
    Matriz* Matriz::crearTraspuesta() const {
        // La traspuesta intercambia dimensiones: Filas de la original pasan a ser Columnas
        Matriz* traspuesta = new Matriz(columnas, filas);
        
        for (int i = 0; i < filas; ++i) {
            for (int j = 0; j < columnas; ++j) {
                // La fila i, columna j va a la fila j, columna i de la traspuesta
                traspuesta->setValor(j, i, this->getValor(i, j));
            }
        }
        return traspuesta;
    }

} // namespace Algebra
