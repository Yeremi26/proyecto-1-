#include <iostream>
#include <climits>
#include <vector>
using namespace std;

// Función para verificar si un número es primo
bool esPrimo(int numero) {
    if (numero <= 1) return false; // 0 y 1 no son primos
    for (int i = 2; i * i <= numero; i++) {
        if (numero % i == 0) return false;
    }
    return true;
}

int main() {
    vector<int> numeros; // Guardar los números ingresados
    int num, opcion;
    int mayor = INT_MIN; // Para identificar el mayor número
    int posMayor = -1;   // Posición del mayor número

    // Variables para estadísticas
    int cantidadPrimos = 0, sumaPrimos = 0;
    int cantidadNoPrimos = 0, sumaNoPrimos = 0;

    do {
        cout << "Ingrese un numero entero: ";
        cin >> num;
        numeros.push_back(num); // Guardar el número en el vector

        // Verificar si es el mayor número ingresado hasta ahora
        if (num > mayor) {
            mayor = num;
            posMayor = numeros.size(); // Guardar la posición (1-indexada)
        }

        // Verificar si el número es primo o no
        if (esPrimo(num)) {
            cout << "El numero " << num << " es un Numero Primo.\n";
            cantidadPrimos++;
            sumaPrimos += num;
        } else {
            cout << "El numero " << num << " No es un Numero Primo.\n";
            cantidadNoPrimos++;
            sumaNoPrimos += num;
        }

        cout << "¿Desea ingresar otro número? (1: Sí, 0: No): ";
        cin >> opcion;
    } while (opcion != 0);

    // Mostrar estadísticas finales
    cout << "\n--- Estadísticas ---\n";
    cout << "Número Mayor Ingresado: " << mayor << " en la posición " << posMayor << "\n";
    cout << "Cantidad de Números Primos: " << cantidadPrimos << "\n";
    cout << "Sumatoria de los Números Primos: " << sumaPrimos << "\n";
    if (cantidadPrimos > 0)
        cout << "Promedio de los Números Primos: " << (double)sumaPrimos / cantidadPrimos << "\n";
    else
        cout << "Promedio de los Números Primos: N/A\n";

    cout << "Cantidad de Números No Primos: " << cantidadNoPrimos << "\n";
    cout << "Sumatoria de los Números No Primos: " << sumaNoPrimos << "\n";
    if (cantidadNoPrimos > 0)
        cout << "Promedio de los Números No Primos: " << (double)sumaNoPrimos / cantidadNoPrimos << "\n";
    else
        cout << "Promedio de los Números No Primos: N/A\n";

    return 0;
}
