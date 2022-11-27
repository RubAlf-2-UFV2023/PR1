#include <stdio.h>
#include <stdlib.h>
/*Definicion del tipo de elementos de la cola*/
typedef struct
{
    double longitud;
    double latitud;
}GeoLocalizacion;

typedef GeoLocalizacion ElementoCola;

#define MAX_ELEMENTOS 100
#define ELEMENTO_NULO {.longitud = 0, .latitud = 0}

/*Definicion del tipo Cola*/
typedef struct _cola
{
    int ultimo;
    ElementoCola datos[MAX_ELEMENTOS];
}_Cola;

typedef _Cola* Cola;/*Ocultamos al usuario el uso de punteros definiendo el tipo Cola como un puntero a la estructura _Cola*/
typedef enum {FALSE = 0, TRUE = 1} Bool;/*Enumeracion para simular booleanos (realizado por claridad del TAD))*/

Cola crearCola();
void mostrarCola(Cola cola);
Bool esColaVacia(Cola cola);
Bool esColaLlena(Cola cola);
Bool encolar(ElementoCola dato, Cola cola);
ElementoCola decolar(Cola cola);
void eliminarCola(Cola cola);

Cola crearCola()/*Crea una cola*/
{
    Cola cola = (Cola) malloc(sizeof (_Cola));
    cola -> ultimo = -1;
    printf("Cola creada con exito.\n");
    return cola;
}

void mostrarCola(Cola cola)/*Muestra la cola*/
{
    int i;
    if (esColaVacia(cola))
    {
        printf("No hay elementos en cola.\n");
    }
    else
    {
        for (i = 0; i < cola -> ultimo + 1; i++)
        {
            printf("geo[%d]: longitud=%lf, latitud=%lf\n", i, cola->datos[i].longitud, cola->datos[i].latitud);
        }
    }
    return;
}

Bool esColaVacia(Cola cola)/*Comprueba si la cola esta vacia*/
{
    if (cola -> ultimo == -1)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

Bool esColaLlena(Cola cola)/*Comprueba si la pila esta llena*/
{
    if (cola -> ultimo == MAX_ELEMENTOS-1)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

Bool encolar(ElementoCola dato, Cola cola)/*Apila un elemento y devuelve 1 si fue posible y 0 si no fue posible*/
{
    if (cola -> ultimo < MAX_ELEMENTOS - 1)
    {
        cola -> ultimo++;
        cola -> datos[cola -> ultimo] = dato;
        return TRUE;
    }
    else
    {
        printf("No se pudo encolar el elemento, la cola estaba llena.\n");
        return FALSE;
    }
}

ElementoCola desencolar(Cola cola)/*Saca al primer elemento que entro y lo devuelve*/
{
    int i;
    ElementoCola dato = ELEMENTO_NULO, aux;
    if (esColaVacia(cola))
    {
        printf("No habia elementos en la cola, devolviendo elemento nulo . . .\n");
    }
    else
    {
        dato = cola -> datos[0];
        for (i = 0; i < cola -> ultimo; i++)
        {
            cola -> datos[i] = cola -> datos[i+1];
        }
        cola -> ultimo--;
    }
    return dato;
}

void eliminarCola(Cola cola)/*Elimina la cola y libera la memoria*/
{
    free(cola);
    cola = NULL;
    printf("Cola eliminada de memoria.\n");
    return;
}