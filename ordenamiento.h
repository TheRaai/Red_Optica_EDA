
#include <stdio.h>
#include "red.h"

void cambio(node *pos1, node *pos2);
void junta(node *ar,int l, int m,int r);
int particion(int bajo, int alto);

extern int asignaciones, comparaciones;
extern int number_of_nodes;
void bubblesort();
void Merge(node *ar,int l, int r);
void mergesort();
void qs(int bajo, int alto);
void quicksort();
void selectionsort();
void insertionsort();
void guardar_nodos_ordenados(char* filename);
