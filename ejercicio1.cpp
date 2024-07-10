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

// FUNCIÓN AGREGAR UN CONTACTO
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
        cout << "No se pueden agregar más contactos. Límite alcanzado." << endl;
    }
}

// FUNCIÓN ELIMINAR UN CONTACTO
void eliminarContacto(contactoEmail contactos[], int &contadorContactos) {
    if (contadorContactos == 0) {
        cout << "No hay contactos para eliminar." << endl;
        return;
    }

    int indice;
    cout << "Ingrese el numero del contacto que desea eliminar (1-" << contadorContactos << "): ";
    cin >> indice;

    if (indice < 1 || indice > contadorContactos) {
        cout << "Numero de contacto inválido." << endl;
        return;
    }

    indice--;

    for (int i = indice; i < contadorContactos - 1; i++) {
        contactos[i] = contactos[i + 1];
    }

    contadorContactos--;
    cout << "Contacto eliminado exitosamente." << endl;
}

// FUNCIÓN MOSTRAR CONTACTOS
void mostrarContactos(contactoEmail contactos[], int contadorContactos) {
    if (contadorContactos == 0) {
        cout << "No hay contactos registrados." << endl;
        return;
    }

    for (int i = 0; i < contadorContactos; i++) {
        cout << "// CONTACTO Nro: " << i + 1 << " //" << endl;
        cout << "Nombres completos: " << contactos[i].nombresCompletos << endl;
        cout << "Género: " << contactos[i].sexo << endl;
        cout << "Edad: " << contactos[i].edad << endl;
        cout << "Teléfono: " << contactos[i].telefono << endl;
        cout << "Email: " << contactos[i].email << endl;
        cout << "Nacionalidad: " << contactos[i].nacionalidad << endl;
        cout << "------------------------" << endl;
    }
}

// FUNCIÓN PARA EXTRAER EL DOMINIO DEL CORREO
string extraerDominio(const string &email) {
    size_t pos = email.find('@');
    if (pos != string::npos) {
        return email.substr(pos + 1);
    }
    return "";
}

// FUNCIÓN MOSTRAR CONTACTOS ORDENADOS POR DOMINIO
void mostrarContactosOrdenadosPorDominio(contactoEmail contactos[], int contadorContactos) {
    if (contadorContactos == 0) {
        cout << "No hay contactos registrados." << endl;
        return;
    }

    for (int i = 0; i < contadorContactos - 1; i++) {
        for (int j = 0; j < contadorContactos - i - 1; j++) {
            if (extraerDominio(contactos[j].email) > extraerDominio(contactos[j + 1].email)) {
                contactoEmail temp = contactos[j];
                contactos[j] = contactos[j + 1];
                contactos[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < contadorContactos; i++) {
        cout << "// CONTACTO Nro: " << i + 1 << " //" << endl;
        cout << "Nombres completos: " << contactos[i].nombresCompletos << endl;
        cout << "Género: " << contactos[i].sexo << endl;
        cout << "Edad: " << contactos[i].edad << endl;
        cout << "Teléfono: " << contactos[i].telefono << endl;
        cout << "Email: " << contactos[i].email << endl;
        cout << "Nacionalidad: " << contactos[i].nacionalidad << endl;
        cout << "Dominio: " << extraerDominio(contactos[i].email) << endl;
        cout << "------------------------" << endl;
    }
}

// FUNCIÓN SWITCH PARA EL MENÚ DE OPCIONES
void programa(int decision, bool &bucle, contactoEmail contactos[], int &contadorContactos) {
    switch (decision) {
        case 1:
            agregarContacto(contactos, contadorContactos);
            break;
        case 2:
        	eliminarContacto(contactos, contadorContactos);
            break;
        case 3:
        	mostrarContactos(contactos, contadorContactos);
            break;
        case 4:
        	mostrarContactosOrdenadosPorDominio(contactos, contadorContactos);
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
