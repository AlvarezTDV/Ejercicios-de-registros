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

// FUNCI�N AGREGAR UN CONTACTO
void agregarContacto(contactoEmail contactos[], int &contadorContactos) {
    if (contadorContactos < 10) {
        cout << "// AGREGAR UN CONTACTO Nro: " << contadorContactos + 1 << " //" << endl;
        cin.ignore();
        cout << "Ingrese nombres completos: ";
        getline(cin, contactos[contadorContactos].nombresCompletos);

        cout << "Ingrese el genero: ";
        getline(cin, contactos[contadorContactos].sexo);

        cout << "Ingrese la edad: ";
        cin >> contactos[contadorContactos].edad;
        cin.ignore();

        cout << "Ingrese el telefono: ";
        getline(cin, contactos[contadorContactos].telefono);

        cout << "Ingrese el email: ";
        getline(cin, contactos[contadorContactos].email);

        cout << "Ingrese la nacionalidad: ";
        getline(cin, contactos[contadorContactos].nacionalidad);

        contadorContactos++;
    } else {
        cout << "No se pueden agregar m�s contactos. L�mite alcanzado." << endl;
    }
}

// FUNCI�N ELIMINAR UN CONTACTO
void eliminarContacto(contactoEmail contactos[], int &contadorContactos) {
    if (contadorContactos == 0) {
        cout << "No hay contactos para eliminar." << endl;
        return;
    }

    int indice;
    cout << "Ingrese el n�mero del contacto que desea eliminar (1-" << contadorContactos << "): ";
    cin >> indice;

    if (indice < 1 || indice > contadorContactos) {
        cout << "N�mero de contacto inv�lido." << endl;
        return;
    }

    indice--;

    for (int i = indice; i < contadorContactos - 1; i++) {
        contactos[i] = contactos[i + 1];
    }

    contadorContactos--;
    cout << "Contacto eliminado exitosamente." << endl;
}

// FUNCI�N SWITCH PARA EL MEN� DE OPCIONES
void programa(int decision, bool &bucle, contactoEmail contactos[], int &contadorContactos) {
    switch (decision) {
        case 1:
            agregarContacto(contactos, contadorContactos);
            break;
        case 2:
        	eliminarContacto(contactos, contadorContactos);
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
    contactoEmail contactos[10];
    int contadorContactos = 0;

    do {
        cout << "1) Agregar un contacto" << endl;
        cout << "2) Eliminar un contacto" << endl;
        cout << "3) Mostrar contactos registrados" << endl;
        cout << "4) Mostrar contactos existentes, ordenado por servidor de correo" << endl;
        cout << "5) Salir del programa" << endl;
        cin >> decision;
        programa(decision, bucle, contactos, contadorContactos);
	} while ( bucle != true );
	
	return 0;
}
