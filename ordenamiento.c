#include <stdio.h>
#include <assert.h>
#include "ordenamiento.h"

int number_of_nodes;
int asignaciones,comparaciones;

void cambio(node *pos1, node *pos2){//Cambia los datos de posicion mediante punteros
  node temp = *pos1;
  *pos1 = *pos2;
  *pos2 = temp;
}

int particion(int bajo, int alto){//Ingresa los datos y posiciones, y busca el punto medio
  int p = nodes[alto].links;
  int i = (bajo - 1);
  for (int j = bajo; j <= alto- 1; j++){
    comparaciones++;
    if (nodes[j].links > p){
      i++;
      cambio(&nodes[i], &nodes[j]);
      asignaciones++;
    }
  }
  cambio(&nodes[i + 1], &nodes[alto]);
  return (i + 1);
}

void bubblesort(){ //asignaciones arreglar(done)
  comparaciones = 0;
  int n = number_of_nodes;
  int i,j;
  node prueba;
  for(i=0;i<n-1;i++){
    for(j=0;j<n-i-1;j++){
      comparaciones++;
      if(nodes[j+1].links > nodes[j].links){
        asignaciones++;
        prueba = nodes[j];
        nodes[j] = nodes[j+1];
        nodes[j+1] = prueba;
      }
    }
  }
}

void junta(node *ar,int l, int m,int r){
  int msize = r - l + 1;
  node *temp = (node *)malloc(msize*sizeof(node));
  int mpos = 0;
  int lpos = l;
  int rpos = m + 1;
  while(lpos <= m && rpos <= r){
    comparaciones++;
    if(ar[lpos].links > ar[rpos].links){
      temp[mpos++] = ar[lpos++];
      asignaciones++;
    }
    else{
      temp[mpos++] = ar[rpos++];
      asignaciones++;
    }
  }
  while(lpos <= m){
    asignaciones++;
    temp[mpos++] = ar[lpos++];
  }
  while(rpos <= r){
    asignaciones++;
    temp[mpos++] = ar[rpos++];
  }
  for(mpos = 0; mpos < msize;++mpos){
    ar[l+mpos] = temp[mpos];
  }
  free(temp);
}

void Merge(node *ar,int l, int r){
  if(l<r){
    int m = (l+r)/2;
    Merge(ar, l, m);
    Merge(ar, m+1, r);

    junta(ar,l,m,r);
  }
  
}

void mergesort(){
  asignaciones = 0;
  comparaciones = 0;
  Merge(nodes,0,number_of_nodes-1);
}

void qs(int bajo, int alto){
  if(bajo<alto){
    int pi = particion(bajo,  alto);

    qs(bajo,pi-1);
    qs(pi+1,alto);
  }
}

void quicksort(){
  asignaciones = 0;
  comparaciones = 0;
  qs(0,number_of_nodes);
}

void selectionsort(){ //done
  asignaciones = 0;
  comparaciones = 0;
  int n = number_of_nodes;
  int i,j,min_id;
  node temp;
  for(i = 0;i < n-1;i++){
    min_id = i;
    for(j = i+1;j < n;j++){
      comparaciones++;
      if(nodes[j].links > nodes[min_id].links){
        min_id = j;
        
      }
    }
    temp = nodes[i];
    nodes[i] = nodes[min_id];
    nodes[min_id] = temp;
    asignaciones++;
  }
}

void insertionsort(){ //done
  asignaciones = 0;
  comparaciones = 0;
  int n = number_of_nodes;
  int i,j,llave;
  node prueba;
  for(i = 1;i < n;i++){
    llave = nodes[i].links;
    prueba = nodes[i];
    comparaciones++;
    for(j=i-1;j>=0;j--){
      if(nodes[j].links <= llave){
        asignaciones++;
        nodes[j+1] = nodes[j];
      }
      else break;
    }
    nodes[j+1].links = llave;
    nodes[j+1] = prueba;
  }
}


void guardar_nodos_ordenados(char* filename){
  if(strcmp(filename, "out_bs.txt")==0){
    FILE* fa = fopen("out_bs.txt","w");
    bubblesort();
    for(int i = 0 ;i<number_of_nodes;i++){
      fprintf(fa,"%d ",nodes[i].id);
      if(i==number_of_nodes-1){
        fprintf(fa,"\n");
      } 
    }
    fprintf(fa,"----------\n");
    fprintf(fa,"Algoritmo: BubbleSort\n");
    fprintf(fa,"Asignaciones: %d\n",asignaciones);
    fprintf(fa,"Comparaciones: %d\n",comparaciones);
    fclose(fa);
  }
  else if(strcmp(filename, "out_ms.txt")==0){
    FILE *fb = fopen("out_ms.txt","w");
    mergesort();
    for(int i = 0 ;i<number_of_nodes;i++){
      fprintf(fb,"%d ",nodes[i].id);
      if(i==number_of_nodes-1){
        fprintf(fb,"\n");
      } 
    }
    fprintf(fb,"----------\n");
    fprintf(fb,"Algoritmo: MergeSort\n");
    fprintf(fb,"Asignaciones: %d\n",asignaciones);
    fprintf(fb,"Comparaciones: %d\n",comparaciones);
    fclose(fb);
  }
  else if(strcmp(filename, "out_qs.txt")==0){
    FILE* fa = fopen("out_qs.txt","w");
    quicksort();
    for(int i = 0 ;i<number_of_nodes;i++){
      fprintf(fa,"%d ",nodes[i].id);
      if(i==number_of_nodes-1){
        fprintf(fa,"\n");
      } 
    }
    fprintf(fa,"----------\n");
    fprintf(fa,"Algoritmo: QuickSort\n");
    fprintf(fa,"Asignaciones: %d\n",asignaciones);
    fprintf(fa,"Comparaciones: %d\n",comparaciones);
    fclose(fa);
  }
  else if(strcmp(filename, "out_ss.txt")==0){
    FILE* fa = fopen("out_ss.txt","w");
    selectionsort();
    for(int i = 0 ;i<number_of_nodes;i++){
      fprintf(fa,"%d ",nodes[i].id);
      if(i==number_of_nodes-1){
        fprintf(fa,"\n");
      } 
    }
    fprintf(fa,"----------\n");
    fprintf(fa,"Algoritmo: SelectionSort\n");
    fprintf(fa,"Asignaciones: %d\n",asignaciones);
    fprintf(fa,"Comparaciones: %d\n",comparaciones);
    fclose(fa);
  }
  else if(strcmp(filename, "out_is.txt")==0){
    FILE* fa = fopen("out_is.txt","w");
    insertionsort();
    for(int i = 0 ;i<number_of_nodes;i++){
      fprintf(fa,"%d ",nodes[i].id);
      if(i==number_of_nodes-1){
        fprintf(fa,"\n");
      } 
    }
    fprintf(fa,"----------\n");
    fprintf(fa,"Algoritmo: InsertionSort\n");
    fprintf(fa,"Asignaciones: %d\n",asignaciones);
    fprintf(fa,"Comparaciones: %d\n",comparaciones);
    fclose(fa);
  }
}
