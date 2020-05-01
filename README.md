#### Autor: Raimundo Moraga
#### Rut: 20.072.048-2
#### Sección: 3

### Instrucciones
Para poder ejecutar el programa, se debe escribir el siguiente comando en terminal:

```console
~gcc main.c ordenamiento.c red.c -o main
~./main NSFNet.txt
```
o con el compilador preferido.
NOTA: se debe dar el nombre del archivo al ejecutar el archivo compilado, ya que si no se hace, no se puede leer el archivo.

### Observaciones:
1. En linea 37 de main.c se debe comentar el liberado de memoria, ya que de lo contrario arroja Segmentation fault.
Sin este liberado, se tiene el siguiente memory report(Conseguido usando Valgrind-3.13.0):

```console

//////////////////////////////////
LEAK SUMMARY:
   definitely lost: 336 bytes in 1 blocks
   indirectly lost: 784 bytes in 14 blocks
   possibly lost: 0 bytes in 0 blocks
   still reachable: 0 bytes in 0 blocks
   suppressed: 0 bytes in 0 blocks
//////////////////////////////////
```
2. Algunas veces al ejecutar la funcion " guardar_nodos_ordenados(char *filename)" no se crean los archivos por razones desconocidas, por lo cual se deberian crear los archivos previamente, pero generalmente funciona de manera correcta.

3. Por otro lado, si se libera memoria en linea 37(obs. 1) y se ocupa Valgrind para ejecutar el programa, funciona de manera correcta(por razones desconocidas) y se tiene el siguiente memory report:

```console
///////////////////////////////////
HEAP SUMMARY:
   in use at exit: 0 bytes in 0 blocks
   total heap usage: 152 allocs, 152 frees, 125,416 bytes allocated
//////////////////////////////////
```
4. Pruebas hechas usando gcc version 7.5.0 y Valgrind-3.13.0
