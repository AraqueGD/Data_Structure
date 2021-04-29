#ifndef list_h
#define list_h

#include "library.h"

typedef struct Nodo
{
    Libro libro;
    struct Nodo *siguiente;
} Nodo;

typedef struct Lista
{
    Nodo *cabeza;
    int longitud;
} Lista;

#endif list_h