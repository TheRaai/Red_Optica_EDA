#include "ordenamiento.h"

void print_nodes_info(int n){
  printf("ID\tnum\tlinks\n");
  for(int i = 0; i < n; i++){
    printf("%i\t%i\t%i",nodes[i].id,nodes[i].links,nodes[i].link_ids[0]);
    for(int j = 1; j < nodes[i].links;j++){
      printf("-%i",nodes[i].link_ids[j]);
    }
    printf("\n");
  }
}

void liberar_memoria(){
  for(int i = 0; i < number_of_nodes;i++){
    free(nodes[i].link_ids);
  }

  free(nodes);
}

int main(int argc, char** argv){
  leer_archivo(argv[1]);
  print_nodes_info(number_of_nodes);
  bubblesort();
  print_nodes_info(number_of_nodes);
  printf("Asignaciones: %d \nComparaciones: %d\n\n",asignaciones, comparaciones);
  guardar_nodos_ordenados("out_bs.txt");
  liberar_memoria();

  leer_archivo(argv[1]);
  print_nodes_info(number_of_nodes);
  mergesort();
  print_nodes_info(number_of_nodes);
  printf("Asignaciones: %d \nComparaciones: %d\n\n",asignaciones, comparaciones);
  guardar_nodos_ordenados("out_ms.txt");
  liberar_memoria();

  leer_archivo(argv[1]);
  print_nodes_info(number_of_nodes);
  quicksort();
  print_nodes_info(number_of_nodes);
  printf("Asignaciones: %d \nComparaciones: %d\n\n",asignaciones, comparaciones);
  guardar_nodos_ordenados("out_qs.txt");
  liberar_memoria();

  leer_archivo(argv[1]);
  print_nodes_info(number_of_nodes);
  selectionsort();
  print_nodes_info(number_of_nodes);
  printf("Asignaciones: %d \nComparaciones: %d\n\n",asignaciones, comparaciones);
  guardar_nodos_ordenados("out_ss.txt");
  liberar_memoria();

  leer_archivo(argv[1]);
  print_nodes_info(number_of_nodes);
  insertionsort();
  print_nodes_info(number_of_nodes);
  printf("Asignaciones: %d \nComparaciones: %d\n\n",asignaciones, comparaciones);
  guardar_nodos_ordenados("out_is.txt");
  liberar_memoria();
  return 0;
}