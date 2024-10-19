#include <iostream>
using namespace std;

int main() {
    int numero, inverso, residuo;
    char continuar;

    do {
        // Solicitar número con validación
        do {
            cout << "Ingrese un numero entero (maximo 5 digitos): ";
            cin >> numero;
        } while (numero < 0 || numero > 99999);  // Validar que el número esté entre 0 y 99999

        // Proceso para hallar el inverso matemáticamente
        inverso = 0;  // Inicializar el inverso
        int temp = numero;  // Guardar el valor original para mostrar al final

        while (temp > 0) {
            residuo = temp % 10;      // Extraer el último dígito
            inverso = inverso * 10 + residuo;  // Agregar el dígito extraído al inverso
            temp /= 10;              // Eliminar el último dígito del número
        }

        // Mostrar el resultado
        cout << "Numero ingresado: " << numero << endl;
        cout << "Numero inverso: " << inverso << endl;

        // Preguntar si desea realizar otra operación
        cout << "\n¿Desea ingresar otro número? (s/n): ";
        cin >> continuar;

    } while (continuar == 's' || continuar == 'S');

    return 0;
}

