//
// Created by jfarfan on 24/11/2019.
//

#ifndef ARCHIVOS_GENERAR_ARCHIVOS_H
#define ARCHIVOS_GENERAR_ARCHIVOS_H
#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <map>
using namespace std;

void generar_archivo(string nombrefisico, int cantidad);
void generar_archivo_ordenado(string nombreArchivoOriginal, string nombreArchivoOrdenado);
void generar_datos_contados(string nombreArchivoOrdenado, string nombreArchivoContados);

#endif //ARCHIVOS_GENERAR_ARCHIVOS_H
