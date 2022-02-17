#include <iostream>

#define LINUX 1
#define WINDOWS 2

#define MYSYSTEM 1
#define cuadrado(x) (x) * (x)

#ifndef _MATH_H
    #define PI 3.1416
#endif

void clear_console();


using namespace std;

int main(){
    char bandera = 'y';
    float radio;
    while(bandera == 'y'){
        clear_console();
        cout << "----------AREA DE UN CIRCULO------" << endl;
        cout << "Ingresa el radio de tu circulo: ";
        cin >> radio;

        #undef PI
        float PI = 3.141588800;
        cout << "El area de tu circulo es " << PI * cuadrado(radio) << endl;
        cout << "¿Quieres continuar?[y/n]: ";
        cin >> bandera;
        clear_console();
    }
    return 0;
}

void clear_console(){
    #if MYSYSTEM == LINUX
    system("clear");
    #elif MYSYSTEM == WINDOWS
    system("cls");
    #else
        #error Sistema desconocido
    #endif
}
