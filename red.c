#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "red.h"


int numero_nodos(char* filename){/*funcion para sacar numero de nodos*/
  FILE *fa = fopen(filename,"r");
  int Nnodos;
  char str1[20], str2[10], str3[10];
  fscanf(fa,"%s %s %s %d",str1,str2,str3,&Nnodos);
  fclose(fa);
  return Nnodos;
}

int numero_links(char* filename){/*retorna numero de links*/
  FILE *fb = fopen(filename,"r");
  int nlinks, i, linea = 1;
  char str1[20], str2[10], str3[10], curr[100];
  while (fgets(curr,255,fb) != NULL){
    if(linea==1){
      fscanf(fb,"%s %s %s %d",str1,str2,str3,&nlinks);
    }
    linea++;
  }
  fclose(fb);
  return nlinks;
}

void removeChar(char *str, char garbage) {

    char *src, *dst;
    for (src = dst = str; *src != '\0'; src++) {
        *dst = *src;
        if (*dst != garbage) dst++;
    }
    *dst = '\0';
}

int number_of_nodes;
node* nodes;

void leer_archivo(char* filename){/**/
  FILE *fn = fopen(filename,"r");
  int links_hechos = 0;
  int linea = 1, i = 0,anterior =0,j=0,k=0;
  int nod,links,destino,id;
  int *link_id;
  char curr[100];
  char *prueba;
  char *bas;
  char *cada[100];

  if (fn == NULL){
    printf("El archivo no se pudo leer\n"); /*Imprimir error si no se logra leer el archivo*/
  }
  fseek(fn,0,SEEK_SET);
  number_of_nodes = numero_nodos(filename);
  int nLinks = numero_links(filename);

  nodes = (node*)malloc(sizeof(node)*(number_of_nodes));/*Arreglo donde se guardaran los nodos*/

  for(int p = 0;p<number_of_nodes;p++){
    nodes[p].links = 0;
  }
  while(fgets(curr,255,fn) != NULL){

    if(linea < 6){//Salta primeras 6 lineas, para poder hacer analisis de lo que quiero
      linea++;
      continue;
    }
    cada[0] = strtok(curr,"	");/*Almacena numero del nodo*/
    cada[1] = strtok(NULL,"	");//Almacena destino
    cada[2] = strtok(NULL,"	");//Almacena enlaces
    cada[3] = strtok(NULL,"	");//Almacena camino
    if(strcmp(cada[2],"1")==0){
      removeChar(cada[0],'['); //Remueve caracteres del id
      removeChar(cada[0],']');
      nod = strtol(cada[0],&bas,10); //Convierte el string id a entero
      links = strtol(cada[2],&bas,10);
      removeChar(cada[1],'['); //Remueve caracteres del id
      removeChar(cada[1],']');
      destino = strtol(cada[1],&bas,10);
      id = strtol(cada[3],&bas,10);
      nodes[nod].id = nod;
      nodes[nod].links++;
      nodes[destino].id = destino;
      nodes[destino].links++;
    }
    linea++;
  }

  fclose(fn);
  ///////////////////////////////////////////////////
  //Crear arreglos dinamicos para los link_id
  for(int k = 0;k<number_of_nodes;k++){
    nodes[k].link_ids = (int*)malloc(sizeof(int)*number_of_nodes);
    for(int p = 0;p<nodes[k].links;p++){
      nodes[k].link_ids[p] = 0;
    }
  }
  //////////////////////////////////////////////////
  FILE* fm = fopen(filename,"r");
  char aux[1000];
  char* id_n;
  char* destino_n;
  char* enlace;
  int enlace_n;
  int l_id;
  int id_n_2;
  int destino_2;
  int line=1;
  while(fgets(aux,999,fm)){
    if(line<6){
      line++;
      continue;
    }
    id_n = strtok(aux,"\t");
    destino_n = strtok(NULL,"\t");
    enlace = (strtok(NULL,"\t"));
    l_id = atoi(strtok(NULL,"\t"));
    if (strcmp(enlace,"1")==0){
      removeChar(id_n, '[');
      removeChar(id_n, ']');
      id_n_2 = atoi(id_n);
      removeChar(destino_n,'[');
      removeChar(destino_n, ']');
      destino_2 = atoi(destino_n);
      /*//////
      TODO: Ordenar link_id's en un ciclo (21/4)
      (1/5) Hardcoding it is
      //////*/
      for(int li =0;li<number_of_nodes;li++){//Recorrer cada nodo
        if(id_n_2 == li){//Revisar si estamos en un nodo de salida
          if(nodes[li].link_ids[0] == '\0'){
            nodes[li].link_ids[0] = l_id;
          }
          else if(nodes[li].link_ids[1] == '\0'){
            nodes[li].link_ids[1] = l_id;
          }
          else if(nodes[li].link_ids[2] == '\0'){
            nodes[li].link_ids[2] = l_id;
          }
          else if(nodes[li].link_ids[3] == '\0'){
            nodes[li].link_ids[3] = l_id;
          }
          else if(nodes[li].link_ids[4] == '\0'){
            nodes[li].link_ids[4] = l_id; 
          }
          else if(nodes[li].link_ids[5] == '\0'){
            nodes[li].link_ids[5] = l_id;
          }
          else if(nodes[li].link_ids[6] == '\0'){
            nodes[li].link_ids[6] = l_id;
          }
          else if(nodes[li].link_ids[7] == '\0'){
            nodes[li].link_ids[7] = l_id;
          }
        }
        if(destino_2 == li){//Revisar si estamos en un nodo de entrada
          if(nodes[li].link_ids[0] == '\0'){
            nodes[li].link_ids[0] = l_id;
          }
          else if(nodes[li].link_ids[1] == '\0'){
            nodes[li].link_ids[1] = l_id;
          }
          else if(nodes[li].link_ids[2] == '\0'){
            nodes[li].link_ids[2] = l_id;
          }
          else if(nodes[li].link_ids[3] == '\0'){
            nodes[li].link_ids[3] = l_id;
          }
          else if(nodes[li].link_ids[4] == '\0'){
            nodes[li].link_ids[4] = l_id; 
          }
          else if(nodes[li].link_ids[5] == '\0'){
            nodes[li].link_ids[5] = l_id;
          }
          else if(nodes[li].link_ids[6] == '\0'){
            nodes[li].link_ids[6] = l_id;
          }
          else if(nodes[li].link_ids[7] == '\0'){
            nodes[li].link_ids[7] = l_id;
          }
        }
      }    
    }
    line++;
  }
  fclose(fm);
}

