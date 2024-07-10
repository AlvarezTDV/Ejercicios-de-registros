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

// FUNCION PARA BUSCAR UN PRODUCTO POR NOMBRE
void buscarProducto() {
    string nombreBuscar;
    cout << "\n=== BUSCAR PRODUCTO ===" << endl;
    cout << "Ingrese el nombre del producto a buscar: ";
    getline(cin, nombreBuscar);

    bool encontrado = false;
    for (int i = 0; i < numProductos; i++) {
        if (inventario[i].nombre == nombreBuscar) {
            cout << "Producto encontrado:" << endl;
            cout << "Nombre: " << inventario[i].nombre << endl;
            cout << "Precio: $" << inventario[i].precio << endl;
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "Producto no encontrado." << endl;
    }
}

// FUNCION PARA ACTUALIZAR LOS DATOS DE UN PRODUCTO
void actualizarProducto() {
    string nombreActualizar;
    cout << "\n=== ACTUALIZAR PRODUCTO ===" << endl;
    cout << "Ingrese el nombre del producto a actualizar: ";
    getline(cin, nombreActualizar);

    bool encontrado = false;
    for (int i = 0; i < numProductos; i++) {
        if (inventario[i].nombre == nombreActualizar) {
            cout << "Ingrese el nuevo nombre del producto: ";
            getline(cin, inventario[i].nombre);

            cout << "Ingrese el nuevo precio del producto: ";
            cin >> inventario[i].precio;
            cin.ignore();

            cout << "Producto actualizado exitosamente." << endl;
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "Producto no encontrado." << endl;
    }
}

// FUNCION PARA ELIMINAR UN PRODUCTO
void eliminarProducto() {
    string nombreEliminar;
    cout << "\n=== ELIMINAR PRODUCTO ===" << endl;
    cout << "Ingrese el nombre del producto a eliminar: ";
    getline(cin, nombreEliminar);

    bool encontrado = false;
    for (int i = 0; i < numProductos; i++) {
        if (inventario[i].nombre == nombreEliminar) {
            for (int j = i; j < numProductos - 1; j++) {
                inventario[j] = inventario[j + 1];
            }
            numProductos--;
            cout << "Producto eliminado exitosamente." << endl;
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "Producto no encontrado." << endl;
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
            	buscarProducto();
                break;
            case 'D':
            	actualizarProducto();
                break;
            case 'E':
            	eliminarProducto();
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
