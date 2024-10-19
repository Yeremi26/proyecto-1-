#include <iostream>
#include <iomanip> // Para manejar la precisión decimal
#include <string>  // Para manejar cadenas de texto
using namespace std;

// Constantes globales
const double PRECIO_GALERIA = 6000.0;
const double PRECIO_PALCO = 12000.0;
const double DESCUENTO_NINO_ADULTO_MAYOR = 0.30;
const double IMPUESTO_VENTA = 0.13;

int main() {
    // Variables de control
    int numeroFactura = 1;
    char continuar;

    // Estadísticas
    int totalEntradasGaleria = 0, totalEntradasPalco = 0;
    double acumuladoGaleria = 0, acumuladoPalco = 0;
    int totalEntradasGeneral = 0;
    double acumuladoGeneral = 0;

    do {
        // Variables para datos de la venta
        string cedula, nombre;
        int tipoCliente, tipoTiquete, cantidad;
        double precioUnitario, montoVenta, descuento = 0, subtotal, impuesto, totalPagar;

        // Entrada de datos con validaciones
        cout << "----- Registro de Venta -----" << endl;
        cout << "Cedula del cliente: ";
        cin >> cedula;
        cout << "Nombre del cliente: ";
        cin.ignore();
        getline(cin, nombre);

        do {
            cout << "Tipo de cliente (1=Niño o adulto mayor, 2=Adulto): ";
            cin >> tipoCliente;
        } while (tipoCliente < 1 || tipoCliente > 2);

        do {
            cout << "Tipo de tiquete (1=Galería, 2=Palco): ";
            cin >> tipoTiquete;
        } while (tipoTiquete < 1 || tipoTiquete > 2);

        do {
            cout << "Cantidad de tiquetes: ";
            cin >> cantidad;
        } while (cantidad <= 0);

        // Determinar el precio unitario según el tipo de tiquete
        if (tipoTiquete == 1) {
            precioUnitario = PRECIO_GALERIA;
        } else {
            precioUnitario = PRECIO_PALCO;
        }

        // Calcular monto de venta
        montoVenta = precioUnitario * cantidad;

        // Calcular descuento si aplica
        if (tipoCliente == 1) {
            descuento = montoVenta * DESCUENTO_NINO_ADULTO_MAYOR;
        }

        // Calcular subtotal, impuesto y total a pagar
        subtotal = montoVenta - descuento;
        impuesto = subtotal * IMPUESTO_VENTA;
        totalPagar = subtotal + impuesto;

        // Mostrar factura
        cout << fixed << setprecision(2);
        cout << "\n----- Factura #" << numeroFactura << " -----" << endl;
        cout << "Cedula: " << cedula << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Tipo de Cliente: " << (tipoCliente == 1 ? "Niño o Adulto Mayor" : "Adulto") << endl;
        cout << "Tipo de Tiquete: " << (tipoTiquete == 1 ? "Galería" : "Palco") << endl;
        cout << "Cantidad: " << cantidad << endl;
        cout << "Precio Unitario: " << precioUnitario << " colones" << endl;
        cout << "Monto de Venta: " << montoVenta << " colones" << endl;
        cout << "Descuento: " << descuento << " colones" << endl;
        cout << "Subtotal: " << subtotal << " colones" << endl;
        cout << "Impuesto (13%): " << impuesto << " colones" << endl;
        cout << "Total a Pagar: " << totalPagar << " colones" << endl;

        // Actualizar estadísticas
        if (tipoTiquete == 1) {
            totalEntradasGaleria += cantidad;
            acumuladoGaleria += totalPagar;
        } else {
            totalEntradasPalco += cantidad;
            acumuladoPalco += totalPagar;
        }
        totalEntradasGeneral += cantidad;
        acumuladoGeneral += totalPagar;

        // Incrementar el número de factura
        numeroFactura++;

        // Preguntar si se desea registrar otra venta
        cout << "\n¿Desea registrar otra venta? (s/n): ";
        cin >> continuar;

    } while (continuar == 's' || continuar == 'S');

    // Mostrar estadísticas finales
    cout << "\n----- Estadísticas Finales -----" << endl;
    cout << "Total Entradas Galería: " << totalEntradasGaleria << endl;
    cout << "Acumulado Dinero Galería: " << acumuladoGaleria << " colones" << endl;
    cout << "Total Entradas Palco: " << totalEntradasPalco << endl;
    cout << "Acumulado Dinero Palco: " << acumuladoPalco << " colones" << endl;
    cout << "Total General de Entradas: " << totalEntradasGeneral << endl;
    cout << "Acumulado General Dinero: " << acumuladoGeneral << " colones" << endl;
    cout << "Promedio General por Venta: " 
         << (numeroFactura > 1 ? acumuladoGeneral / (numeroFactura - 1) : 0) 
         << " colones" << endl;

    return 0;
}

