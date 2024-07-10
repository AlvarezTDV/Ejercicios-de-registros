#include <iostream>
#include <string>
using namespace std;

//SE CREA EL REGISTRO "contactoEmail"
struct contactoEmail {
	string nombresCompletos;
	string sexo;
	int edad;
	string telefono;
	string email;
	string nacionalidad;
};

//FUNCION AGREGAR UN CONTACTO
void agregarContacto( int cantidadContactos ) {
	contactoEmail contact[cantidadContactos];
	
	for( int i = 0; i < cantidadContactos; i++ ) {
		cout << "// AGREGAR UN CONTACTO Nro: " << i + 1 << " //" << endl;
		cout << "Ingrese nombres completos: ";
		cin.ignore();
		getline(cin, contact[i].nombresCompletos);
		
		cout << "Ingrese el genero: ";
		cin >> contact[i].sexo;
			
		cout << "Ingrese la edad: ";
		cin >> contact[i].edad;
		
		cout << "Ingrese el telefono: ";
		cin >> contact[i].telefono;
			
		cout << "Ingrese el email: ";
		cin >> contact[i].email;
			
		cout << "Ingrese la nacionalidad: ";
		cin >> contact[i].nacionalidad;
	}
}

//FUNCION SWITCH PARA EL MENU DE OPCIONES
void programa( int decision, bool &bucle ) {
	int cantidadContactos;
	switch ( decision ) {
		case 1:
			cout << "Ingrese cuantos contactos desea agregar: ";
			cin >> cantidadContactos;
			agregarContacto( cantidadContactos );	
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			bucle = true;
			break;
		default:
			cout << "Ingreso un numero invalido" << endl;
			break;
	}
}

int main() {
	int decision;
	bool bucle = false;
	
	do {
		cout << "1) Agregar un contacto" << endl;
		cout << "2) Eliminar un contacto" << endl;
		cout << "3) Mostrar contactos registrados" << endl;
		cout << "4) Mostrar contactos existentes, ordenado por servidor de correo" << endl;
		cout << "5) Salir del programa" << endl;
		cin >> decision;
		programa( decision, bucle );
	} while ( bucle != true );
	
	return 0;
}
