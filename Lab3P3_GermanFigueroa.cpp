#include <iostream>
#include <locale>
using namespace std;

int main() {
    setlocale (LC_ALL, "spanish")
    int opcion;
    do {
        cout << " --- MENU PRINCIPAL --- " << endl;
        cout << " 1. Acelerador de Particulas " << endl;
        cout << " 2. Teseracto Simulado " << endl;
        cout << " 3. Simulador de Cadenas Genoma " << endl;
        cout << " 0. Salir " << endl;
        cout << " Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {

            case 1:
                cout << " Acelerador de Particulas " << endl;

            case 2:
                cout << " Teseracto Simulado " << endl;

            case 3:
                cout << " Simulador de Cadenas Genoma " << endl;

            case 0:
                cout << " Saliendo del programa " << endl;

            default:
                cout << " La opcion es invalida"
        }

    } while (opcion != 0);
}

