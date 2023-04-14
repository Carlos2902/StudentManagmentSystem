#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Estudiante {
    string nombre, apellido1, apellido2;
    int edad;
    float promedio;
};

//el tipo de elemento: Estudiante.
vector<Estudiante> catalogo; //La variable 'catálogo' representará al vector.

void altaEstudiante() {
    Estudiante nuevoEstudiante; //creación de estudiante nuevo (nuevoEstudiante)
    cout << "Nombre: ";
    cin >> nuevoEstudiante.nombre;

    cout << "Apellido paterno: ";
    cin >> nuevoEstudiante.apellido1;

    cout << "Apellido materno: ";
    cin >> nuevoEstudiante.apellido2;

    cout << "Edad: ";
    cin >> nuevoEstudiante.edad;

    cout << "Promedio: ";
    cin >> nuevoEstudiante.promedio;

    catalogo.push_back(nuevoEstudiante); //se agrega el nuevoEstudiante al véctor dinámico de nombre 'catálogo'
    cout << "El estudiante ha sido dado de alta correctamente.\n\n";
}

void bajaEstudiante() {
    string nombre, apellido1, apellido2;
    cout << "Nombre del estudiante a eliminar: ";
    cin >> nombre;
    
    cout << "Apellido paterno: ";
    cin >> apellido1;

    cout << "Apellido materno: ";
    cin >> apellido2;

    for (int i = 0; i < catalogo.size(); i++) {
        if (catalogo[i].nombre == nombre && catalogo[i].apellido1 == apellido1 && catalogo[i].apellido2 == apellido2 ) {
            catalogo.erase(catalogo.begin() + i);
            cout << "El estudiante ha sido eliminado correctamente.\n\n";
            return;
        }
    }
    cout << "No se encontró al estudiante en el catálogo.\n\n";
}

void modificarEstudiante() {
    string nombre, apellido1, apellido2;
    cout << "Nombre del estudiante a modificar: ";
    cin >> nombre;

    cout << "Apellido paterno: ";
    cin >> apellido1;

    cout << "Apellido materno: ";
    cin >> apellido2; 

    for (int i = 0; i < catalogo.size(); i++) {
        if (catalogo[i].nombre == nombre && catalogo[i].apellido1 == apellido1 && catalogo[i].apellido2 == apellido2)  {
            cout << "Nuevo nombre: ";
            cin >> catalogo[i].nombre;

            cout << "Nuevo apellido paterno: ";
            cin >> catalogo[i].apellido1;

            cout << "Nuevo apellido materno: ";
            cin >> catalogo[i].apellido2;

            cout << "Nueva edad: ";
            cin >> catalogo[i].edad;
            cout << "Nuevo promedio: ";
            cin >> catalogo[i].promedio;
            cout << "El estudiante ha sido modificado correctamente.\n\n";
            return;
        }
    }
    cout << "No se encontró al estudiante en el catálogo.\n\n";
}

void mostrarCatalogo() {
    if (catalogo.empty()) {
        cout << "No hay estudiantes en el catálogo.\n\n";
        return;
    }
    cout << "Catalogo de estudiantes:\n";
    for (int i = 0; i < catalogo.size(); i++) {
        cout << i+1 << ". " << catalogo[i].nombre << " " << catalogo[i].apellido1 << " " << catalogo[i].apellido2 << ", " << catalogo[i].edad << " años, promedio: " << catalogo[i].promedio << endl;
    }
    cout << endl;
}

void buscarEstudiante() {
    string nombre, apellido1, apellido2;
    cout << "Nombre del estudiante a buscar: ";
    cin >> nombre;

    cout << "Apellido paterno: ";
    cin >> apellido1;

    cout << "Apellido materno: ";
    cin >> apellido2;

    for (int i = 0; i < catalogo.size(); i++) {
        if (catalogo[i].nombre == nombre && catalogo[i].apellido1 == apellido1 && catalogo[i].apellido2 == apellido2) {
            cout << "Estudiante encontrado:\n";
            cout << "Nombre: " << catalogo[i].nombre << ", Apellido paterno: " << catalogo[i].apellido1 << ", Apellido materno: " << catalogo[i].apellido2  << ", Edad: " << catalogo[i].edad << " años, Promedio: " << catalogo[i].promedio  << endl;
            return;
        }
    }
    cout << "No se encontró al estudiante en el catálogo.\n\n";
}

int main() {
    int opcion = 0;
    do {
        cout << "Menu de opciones:\n";
        cout << "1. Alta de estudiantes\n";
        cout << "2. Baja de estudiantes\n";
        cout << "3. Modificaciones de estudiantes\n";
        cout << "4. Mostrar todos\n";
        cout << "5. Buscar estudiante\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cout << endl;

        switch (opcion) {
            case 1:
                altaEstudiante();
                break;
            case 2:
                bajaEstudiante();
                break;
            case 3:
                modificarEstudiante();
                break;
            case 4:
                mostrarCatalogo();
                break;
            case 5:
                buscarEstudiante();
                break;
            case 6:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion invalida.\n\n";
        }
    } while (opcion != 6);

    return 0;
}
