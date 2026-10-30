#include <iostream>
#include <locale>
#include <vector>
using namespace std;

void aceleradorParticulas(){
    int tamaño;
    int opción;

    do{
      cout << " Ingrese el tamaño del acelerador de la simulación (número impar entre 5 y 15): ";
      cin >> tamaño;

    }while (tamaño < 5 || tamaño > 15 || tamaño % 2 == 0);
    
    int velocidad = 0;
    int posX = 0;
    int posY = 0;

    do {
        system("cls");
        cout << " La velocidad actual es " << velocidad << "u/s" << endl;

        for (int i = 0; i < tamaño; i++) {
            for (int j = 0; j < tamaño; j++) {
                if (i == posX && i == posY) {
                    cout << "[°]";

                }else if ((i == 0 || i == tamaño - 1 || j == 0 || j == tamaño - 1) && !( (i == 0 && j == 0) || (i == 0 && j == tamaño - 1) || (i == tamaño - 1 && j == 0) || (i == tamaño - 1 && j == tamaño - 1) )){
                    cout << "[+]";

                }else if (i == tamaño / 2 && j == tamaño / 2) {
                    cout << "[+]";

                }else{
                    cout << " [ ] ";
                }
            }
            cout << endl;
        }
        cout << " 1. Agregar Velocidad " << endl;
        cout << " 2. Quitar Velocidad " << endl;
        cout << " 3. Continuar " << endl;
        cout << " 4. Detener y Salir " << endl;
        cout << " Ingrese una opcion: ";
        cin >> opción;

        switch (opción) {
            case 1:
             velocidad++;
             cout << " Se aumento la velocidad en 1 unidad " << endl;

            case 2:
              if (velocidad > 0) velocidad--;
              cout << " Se disminuyo la velocidad " << endl;

            case 3:
                cout << " Se mantiene la velocidad " << endl;
        }
        if (velocidad > 0) {
            posY = (posY + 1) % tamaño;
            if (posY == 0) {
                posX = (posX + 1) % tamaño;
            }
        }

    }while (opción != 4);
}
void teseractoSimulado() {
    int tamaño;
    do {
        cout << "Ingrese tamaño del teseracto en la simulación (número impar entre 5 y 15): ";
        cin >> tamaño;
    } while (tamaño < 5 || tamaño > 15 || tamaño % 2 == 0);

    int*** teseracto = new int** [tamaño];
    for (int i = 0; i < tamaño; i++) {
        teseracto[i] = new int* [tamaño];
        for (int j = 0; j < tamaño; j++) {
            teseracto[i][j] = new int[tamaño];
            for (int k = 0; k < tamaño; k++) {
                teseracto[i][j][k] = 0;
            }
        }
    }

    for (int i = 0; i < tamaño; i++) {
        for (int j = 0; j < tamaño; j++) {
            for (int k = 0; k < tamaño; k++) {
                if (i == 0 || i == tamaño - 1 || j == 0 || j == tamaño - 1 || k == 0 || k == tamaño - 1) {
                    teseracto[i][j][k] = 1;
                }
                if (i >= tamaño / 4 && i <= tamaño - 1 - tamaño / 4 && j >= tamaño / 4 && j <= tamaño - 1 - tamaño / 4 && k >= tamaño / 4 && k <= tamaño - 1 - tamaño / 4) {
                    if (i == tamaño / 4 || i == tamaño - 1 - tamaño / 4 || j == tamaño / 4 || j == tamaño - 1 - tamaño / 4 || k == tamaño / 4 || k == tamaño - 1 - tamaño / 4) {
                        teseracto[i][j][k] = 1;
                    }
                }
            }
        }
    }

    cout << "Teseracto finalizado. Imprimiendo teseracto por partes:" << endl;
    for (int k = 0; k < tamaño; k++) {
        cout << "Fase No. " << k + 1 << endl;
        for (int i = 0; i < tamaño; i++) {
            for (int j = 0; j < tamaño; j++) {
                if (teseracto[k][i][j] == 1) {
                    cout << "o ";
                }
                else {
                    cout << ". ";
                }
            }
            cout << endl;
        }
        cout << endl;
    }

    for (int i = 0; i < tamaño; i++) {
        for (int j = 0; j < tamaño; j++) {
            delete[] teseracto[i][j];
        }
        delete[] teseracto[i];
    }
    delete[] teseracto;
}
void genoma() {
    int n;
    cout << "BIENVENIDO AL SIMULADOR DE GENOMA" << endl;
    do {
        cout << "Ingrese tamaño de la cadena de ADN en la simulación (número par entre mayor a 20): ";
        cin >> n;
    } while (n <= 20 || n % 2 != 0);

    srand(time(0));
    vector<char> helice1;
    vector<char> helice2;
    char nucleotidos[4] = { 'A', 'T', 'C', 'G' };

    for (int i = 0; i < n; i++) {
        char n1 = nucleotidos[rand() % 4];
        char n2;
        if (n1 == 'A') n2 = 'T';
        else if (n1 == 'T') n2 = 'A';
        else if (n1 == 'C') n2 = 'G';
        else n2 = 'C';

        helice1.push_back(n1);
        helice2.push_back(n2);
    }

    for (int i = 0; i < n; i++) {
        cout << "[" << helice1[i] << "]";
        int espacios = (i % 5) + 1;
        for (int j = 0; j < espacios; j++) {
            cout << "-";
        }
        cout << "[" << helice2[i] << "]" << endl;
    }
}




int main() {
    setlocale(LC_ALL, "spanish");

    int opción;
    do {
        cout << " --- MENU PRINCIPAL --- " << endl;
        cout << " 1. Acelerador de Partículas " << endl;
        cout << " 2. Teseracto Simulado " << endl;
        cout << " 3. Simulador de Cadenas Genoma " << endl;
        cout << " 0. Salir " << endl;
        cout << " Ingrese una opción: ";
        cin >> opción;

        switch (opción) {

            case 1:
                cout << " Acelerador de Particulas " << endl;
                aceleradorParticulas();
                break;

            case 2:
                cout << " Teseracto Simulado " << endl;
                teseractoSimulado();
                break;

            case 3:
                cout << " Simulador de Cadenas Genoma " << endl;

                break;

            case 0:
                cout << " Saliendo del programa " << endl;
                break;

            default:
                cout << " La opción es invalida " << endl;
        }

    } while (opción != 0);
}

