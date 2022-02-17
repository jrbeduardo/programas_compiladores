#include <iostream>
#include "afd.hpp"
using namespace std;
extern string tvalue;

int main(int argc, char *argv[]){
    if (argc < 2 ){
        cout << "Faltan argumentos a main" << endl;
        return -1;
    }
    init( argv[1] );
    auto token = next_token();    
    while( token != EOF ){         
        cout<<"Valor: "<<tvalue<<", Clase:"<<token<<endl;
        token = next_token();
    }
    close_file();
    return 0;    
}