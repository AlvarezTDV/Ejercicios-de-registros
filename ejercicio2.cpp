#include <iostream>
#include <string>
using namespace std;

struct Producto {
    string nombre;
    float precio;
};

struct Venta {
    int idVenta;
    string producto;
    int cantidad;
    float precioTotal;
};

const int MAX_PRODUCTOS = 100;
Producto inventario[MAX_PRODUCTOS];
int numProductos = 0;

const int MAX_VENTAS = 100;
Venta historialVentas[MAX_VENTAS];
int numVentas = 0;

// FUNCION PARA MOSTRAR EL MENU
char mostrarMenu() {
    cout << "\n=== MENU ===" << endl;
    cout << "A: Registrar un nuevo producto." << endl;
    cout << "B: Listar los productos registrados." << endl;
    cout << "C: Buscar un producto por nombre." << endl;
    cout << "D: Actualizar los datos de un producto." << endl;
    cout << "E: Eliminar un producto." << endl;
    cout << "F: Registrar una venta." << endl;
    cout << "G: Listar las ventas realizadas." << endl;
    cout << "H: Calcular el total de ventas realizadas." << endl;
    cout << "S: Salir del programa." << endl;

    char opcion;
    cout << "\nIngrese su opcion: ";
    cin >> opcion;
	cin.ignore();
    return toupper(opcion);
}

// FUNCION PARA REGISTRAR NUEVO PRODUCTO
void registrarProducto() {
    if (numProductos < MAX_PRODUCTOS) {
        cout << "\n=== REGISTRAR NUEVO PRODUCTO ===" << endl;
        cout << "Ingrese el nombre del producto: ";
        getline(cin, inventario[numProductos].nombre);

        cout << "Ingrese el precio del producto: ";
        cin >> inventario[numProductos].precio;
        cin.ignore();

        numProductos++;
        cout << "Producto registrado exitosamente." << endl;
    } else {
        cout << "No es posible registrar más productos. Límite alcanzado." << endl;
    }
}

// FUNCION PARA LISTAR LOS PRODUCTOS REGISTRADOS
void listarProductos() {
    if (numProductos == 0) {
        cout << "No hay productos registrados." << endl;
    } else {
        cout << "\n=== LISTA DE PRODUCTOS ===" << endl;
        for (int i = 0; i < numProductos; i++) {
            cout << "Producto " << i + 1 << ": " << endl;
            cout << "Nombre: " << inventario[i].nombre << endl;
            cout << "Precio: $" << inventario[i].precio << endl;
            cout << "------------------------" << endl;
        }
    }
}

int main() {
    char opcion;
    do {
        opcion = mostrarMenu();
        switch (opcion) {
            case 'A':
            	registrarProducto();
                break;
            case 'B':
            	listarProductos();
                break;
            case 'C':
                break;
            case 'D':
                break;
            case 'E':
                break;
            case 'F':
                break;
            case 'G':
                break;
            case 'H':
                break;
            case 'S':
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    } while (opcion != 'S');

    return 0;
}
