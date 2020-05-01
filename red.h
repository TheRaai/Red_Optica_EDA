#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct{ /*Struct del nodo*/
  int id; /*numero del nodo*/
  int *link_ids; /*todos los nodos a los cuales esta conectado*/
  int links; /*numero de caminos*/
} node;

int numero_nodos(char *filename);
int numero_links(char* filename);
void removeChar(char *str, char garbage);

extern int number_of_nodes;
extern node* nodes;
void leer_archivo(char* filename);
