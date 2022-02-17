#include <stdio.h>
#include <stdlib.h>
//#define PI 3.1415926535897
#ifdef PI
  #define area( r ) ( PI * (r) * (r) )
#else
  #define area( r ) (3.1416 * (r) * (r) )
#endif

// Este es un programa de prueba, para verificar
// el funcionamiento del sistema de procesamiento de lenguaje

int main ( void ) {
  printf( "Hola Mundo!\n" ) ; // Funcion para imprimir hola mundo
  float miarea = area(3) ; // soy un comentario...
  printf( "Resultado : %f \n" , miarea );
  return 0;
}
