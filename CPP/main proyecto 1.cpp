#include <iostream>
#include <climits>
#include <vector>
using namespace std;

// Funci�n para verificar si un n�mero es primo
bool esPrimo(int numero) {
    if (numero <= 1) return false; // 0 y 1 no son primos
    for (int i = 2; i * i <= numero; i++) {
        if (numero % i == 0) return false;
    }
    return true;
}

int main() {
    vector<int> numeros; // Guardar los n�meros ingresados
    int num, opcion;
    int mayor = INT_MIN; // Para identificar el mayor n�mero
    int posMayor = -1;   // Posici�n del mayor n�mero

    // Variables para estad�sticas
    int cantidadPrimos = 0, sumaPrimos = 0;
    int cantidadNoPrimos = 0, sumaNoPrimos = 0;

    do {
        cout << "Ingrese un numero entero: ";
        cin >> num;
        numeros.push_back(num); // Guardar el n�mero en el vector

        // Verificar si es el mayor n�mero ingresado hasta ahora
        if (num > mayor) {
            mayor = num;
            posMayor = numeros.size(); // Guardar la posici�n (1-indexada)
        }

        // Verificar si el n�mero es primo o no
        if (esPrimo(num)) {
            cout << "El numero " << num << " es un Numero Primo.\n";
            cantidadPrimos++;
            sumaPrimos += num;
        } else {
            cout << "El numero " << num << " No es un Numero Primo.\n";
            cantidadNoPrimos++;
            sumaNoPrimos += num;
        }

        cout << "�Desea ingresar otro n�mero? (1: S�, 0: No): ";
        cin >> opcion;
    } while (opcion != 0);

    // Mostrar estad�sticas finales
    cout << "\n--- Estad�sticas ---\n";
    cout << "N�mero Mayor Ingresado: " << mayor << " en la posici�n " << posMayor << "\n";
    cout << "Cantidad de N�meros Primos: " << cantidadPrimos << "\n";
    cout << "Sumatoria de los N�meros Primos: " << sumaPrimos << "\n";
    if (cantidadPrimos > 0)
        cout << "Promedio de los N�meros Primos: " << (double)sumaPrimos / cantidadPrimos << "\n";
    else
        cout << "Promedio de los N�meros Primos: N/A\n";

    cout << "Cantidad de N�meros No Primos: " << cantidadNoPrimos << "\n";
    cout << "Sumatoria de los N�meros No Primos: " << sumaNoPrimos << "\n";
    if (cantidadNoPrimos > 0)
        cout << "Promedio de los N�meros No Primos: " << (double)sumaNoPrimos / cantidadNoPrimos << "\n";
    else
        cout << "Promedio de los N�meros No Primos: N/A\n";

    return 0;
}
