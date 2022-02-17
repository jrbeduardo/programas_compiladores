#ifndef __AFD_HPP__
#define __AFD_HPP__

#include <iostream>
#include <map>
#include <string>
#include <fstream>
using namespace std;


const int ENTERO = 1;
const int REAL = 2;
const int ERROR = -2;

void init(string);
bool open_file(string);
char next_char();
int next_token();
void close_file();

#endif // !__AFD_HPP__
