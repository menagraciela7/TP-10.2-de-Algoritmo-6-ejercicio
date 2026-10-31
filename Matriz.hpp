#ifndef MATRIZ_HPP
#define MATRIZ_HPP

#include <iostream>

namespace Algebra {

    class Matriz {
    private:
        int** datos;
        int filas;
        int columnas;

        // Métodos auxiliares privados (Ocultamiento de información)
        void asignarMemoria(int f, int c);
        void liberarMemoria();

    public:
        // Constructores y Destructor (Abstracción y ciclo de vida)
        Matriz(int f, int c);
        ~Matriz();

        // Evitar copias accidentales que rompan la memoria dinámica
        Matriz(const Matriz& otra) = delete;
        Matriz& operator=(const Matriz& otra) = delete;

        // Getters y Setters (Encapsulación)
        int getFilas() const;
        int getColumnas() const;
        void setValor(int f, int c, int valor);
        int getValor(int f, int c) const;

        // Operaciones de la solución (Distribución de responsabilidades)
        void leerDeConsola();
        void mostrar() const;
        Matriz* crearTraspuesta() const; // Retorna un puntero a un nuevo objeto reusable
    };

} // namespace Algebra

#endif // MATRIZ_HPP
