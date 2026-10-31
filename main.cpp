#include <iostream>
#include "Matriz.hpp"

int main() {
    int n, m;

    std::cout << "=======================================\n";
    std::cout << "   CALCULADORA DE MATRIZ TRASPUESTA    \n";
    std::cout << "=======================================\n\n";

    std::cout << "Ingrese el numero de filas (N): ";
    std::cin >> n;
    std::cout << "Ingrese el numero de columnas (M): ";
    std::cin >> m;

    if (n <= 0 || m <= 0) {
        std::cout << "Dimensiones invalidas. El programa terminara.\n";
        return 1;
    }

    // Instancia de la clase usando el Namespace
    Algebra::Matriz matrizOriginal(n, m);

    std::cout << "\n--- Llenado de la Matriz Original ---\n";
    matrizOriginal.leerDeConsola();

    std::cout << "\n--- Matriz Original (NxM) ---\n";
    matrizOriginal.mostrar();

    // Generación de la traspuesta (Aprovechando la distribución de responsabilidades)
    Algebra::Matriz* matrizTraspuesta = matrizOriginal.crearTraspuesta();

    std::cout << "\n--- Matriz Traspuesta (MxN) ---\n";
    matrizTraspuesta->mostrar();

    // Liberamos el objeto dinámico creado en el heap por el método de trasposición
    delete matrizTraspuesta;

    // Evita que la terminal se cierre abruptamente en Windows/Linux sin usar 'system("pause")'
    std::cout << "\n=======================================\n";
    std::cout << "Presione ENTER para salir...";
    std::cin.ignore();
    std::cin.get(); 

    return 0;
}
