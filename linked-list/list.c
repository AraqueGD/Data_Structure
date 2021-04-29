#include "list.h"
#include <stdlib.h>
#include <string.h>

Nodo *CrearNodo(Libro *libro)
{
    Nodo *nodo = (Nodo *)malloc(sizeof(Nodo));
    strcpy(nodo->libro.titulo, libro->titulo, 50);
    strcpy(nodo->libro.autor, libro->autor, 50);
    strcpy(nodo->libro.codigo, libro->codigo, 13);
    nodo->siguiente = NULL;

    return nodo;
}

void DestruirNodo(Nodo *nodo)
{
    free(nodo);
}

void InsertarPrincipio(Lista *lista, Libro *libro)
{
    Nodo *nodo = CrearNodo(libro);
    nodo->siguiente = lista->cabeza;
    lista->cabeza = nodo;
    lista->longitud++;
}

void InsertarFinalLista(Lista *lista, Libro *libro)
{
    Nodo *nodo = CrearNodo(libro);
    if (lista->cabeza == NULL)
    {
        lista->cabeza = nodo;
    }
    else
    {
        Nodo *puntero = lista->cabeza;
        while (puntero->siguiente)
        {
            puntero = puntero->siguiente;
        }
        puntero->siguiente = nodo;
        lista->longitud++;
    }
}

void InsertarMedias(int n, Lista *lista, Libro *libro)
{
    Nodo *nodo = CrearNodo(libro);
    if (lista->cabeza == NULL)
    {
        lista->cabeza = nodo;
    }
    else
    {
        Nodo *punteroAnterior = lista->cabeza;
        int position = 0;
        while (position < n && punteroAnterior->siguiente)
        {
            punteroAnterior = punteroAnterior->siguiente;
            position++;
        }
        nodo->siguiente = punteroAnterior->siguiente;
        punteroAnterior->siguiente = nodo;
        lista->longitud++;
    }
}

Libro *Obtener(int n, Lista *lista)
{
    if (lista->cabeza == NULL)
    {
        return NULL;
    }
    Nodo *puntero = lista->cabeza;
    int position = 0;
    while (position < n && puntero->siguiente)
    {
        puntero = puntero->siguiente;
        position++;
    }
    if (position != n)
    {
        return NULL;
    }
    else
    {
        return &puntero->libro;
    }
}

int Contar(Lista *lista)
{
    return lista->longitud;
}

void EliminarPrincipio(Lista *lista)
{
    if (lista->cabeza)
    {
        Nodo *tmp = lista->cabeza;
        lista->cabeza = lista->cabeza->siguiente;
        DestruirNodo(tmp);
        lista->longitud--;
    }
}

void EliminarUltimo(Lista *lista)
{
    if (lista->cabeza)
    {
        if (lista->cabeza->siguiente)
        {
            Nodo *puntero = lista->cabeza;
            while (puntero->siguiente->siguiente)
            {
                puntero = puntero->siguiente;
            }
            Nodo *tmp = puntero->siguiente;
            puntero->siguiente = NULL;
            DestruirNodo(tmp);
            lista->longitud--;
        }
        else
        {
            Nodo *tmp = lista->cabeza;
            lista->cabeza = NULL;
            DestruirNodo(tmp);
            lista->longitud--;
        }
    }
}

void EliminarMedias(int n, Lista *lista, Libro *libro)
{
    if (lista->cabeza)
    {
        if (n == 0)
        {
            Nodo *tmp = lista->cabeza;
            lista->cabeza = lista->cabeza->siguiente;
            DestruirNodo(tmp);
            lista->longitud--;
        }
        else if (n < lista->longitud)
        {
            Nodo *puntero = lista->cabeza;
            int position = 0;
            while (position < (n - 1))
            {
                puntero = puntero->siguiente;
                position++;
            }
            Nodo *tmp = puntero->siguiente;
            puntero->siguiente = tmp->siguiente;
            DestruirNodo(tmp);
            lista->longitud--;
        }
    }
}