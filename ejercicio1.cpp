#include <iostream>
#include <string>
using namespace std;

//SE CREA EL REGISTRO "contactoEmail"
struct contactoEmail {
	string nombresCompletos;
	bool sexo;
	int edad;
	char telefono;
	string email;
	char nacionalidad;
};

//FUNCION SWITCH PARA EL MENU DE OPCIONES
void programa( int decision, bool &bucle ) {
	switch ( decision ) {
		case 1:
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
