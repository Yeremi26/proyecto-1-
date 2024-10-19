#include <iostream>
using namespace std;

int main() {
    int numero, inverso, residuo;
    char continuar;

    do {
        // Solicitar n�mero con validaci�n
        do {
            cout << "Ingrese un numero entero (maximo 5 digitos): ";
            cin >> numero;
        } while (numero < 0 || numero > 99999);  // Validar que el n�mero est� entre 0 y 99999

        // Proceso para hallar el inverso matem�ticamente
        inverso = 0;  // Inicializar el inverso
        int temp = numero;  // Guardar el valor original para mostrar al final

        while (temp > 0) {
            residuo = temp % 10;      // Extraer el �ltimo d�gito
            inverso = inverso * 10 + residuo;  // Agregar el d�gito extra�do al inverso
            temp /= 10;              // Eliminar el �ltimo d�gito del n�mero
        }

        // Mostrar el resultado
        cout << "Numero ingresado: " << numero << endl;
        cout << "Numero inverso: " << inverso << endl;

        // Preguntar si desea realizar otra operaci�n
        cout << "\n�Desea ingresar otro n�mero? (s/n): ";
        cin >> continuar;

    } while (continuar == 's' || continuar == 'S');

    return 0;
}

