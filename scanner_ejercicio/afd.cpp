#include "afd.hpp"

ifstream input;
bool is_open;
char d;
string tvalue;

map<int, map<char, int>> table = {
    {
        0,
        {
            //digitos
            {'0',1},{'1',1},{'2',1},{'3',1},{'4',1},{'5',1},{'6',1},{'7',1},{'8',1},{'9',1}, 
            //punto
            {'.', 2}, 
            //espacio
            {' ', 4}, {'\n', 4},  {'\t', 4}, {'\r', 4}
        }
    },
    {
        1,
        {
            //digitos
            {'0',1},{'1',1},{'2',1},{'3',1},{'4',1},{'5',1},{'6',1},{'7',1},{'8',1},{'9',1}, 
            //punto
            {'.', 2} 
        }
    },
    {
        2,
        {
            //digitos
            {'0',3},{'1',3},{'2',3},{'3',3},{'4',3},{'5',3},{'6',3},{'7',3},{'8',3},{'9',3}  
        }
    },

    {
        3,
        {
            //digitos
            {'0',3},{'1',3},{'2',3},{'3',3},{'4',3},{'5',3},{'6',3},{'7',3},{'8',3},{'9',3},  
        }
    },

    {
        4,
        {
            //espacio
            {' ', 4}, {'\n', 4},  {'\t', 4}, {'\r', 4}        
        }
    },
};


void init(string file){
    is_open = open_file(file);
    d = next_char();
}

bool open_file(string file){
    input.open(file);
    return input.is_open();
}

void close_file(){
    if(input.is_open()) input.close();
}

char next_char(){
    if(is_open)
        if( !input.eof() ){
            return input.get();
        } 
    return EOF;
}

int next_token(){
    int q = 0;
    char c =d;        
    string buffer="";
    map<char, int>::iterator row;
     
    while(true){
        row = table[q].find(c);    
        if(c == EOF && buffer == "") return EOF;
        if(row != table[q].end()){
            buffer += c;
            q =  row->second;
            c = next_char();
        }else{
            tvalue = buffer;
            d = c;
            switch (q)
            {
            case 1: 
                return ENTERO;
            case 3:
                return REAL;                
            case 4:
                q=0;
                buffer = "";
                break;              
            default:
                tvalue = c;
                d = next_char();
                return ERROR;
            }
        }
    }
}