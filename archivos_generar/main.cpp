#include <iostream>
#include "Archivos.h"

int main() {
    generar_archivo("datos.txt",20);
    generar_archivo_ordenado("datos.txt","datos_ordenados.txt");
    generar_datos_contados("datos_ordenados.txt", "datos_contados.txt");

    return 0;
}