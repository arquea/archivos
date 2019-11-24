//
// Created by jfarfan on 24/11/2019.
//

#include "Archivos.h"
using namespace std;

void generar_archivo(string nombrefisico, int cantidad)
{
    std::random_device r;
    std::fstream archivo(nombrefisico, std::ios::out);
    // Generar los n numeros
    for (int i = 0; i < cantidad; ++i) {
        archivo << 1 + r() % cantidad << '\n';
    }
    archivo.close();
}

void generar_archivo_ordenado(string nombreArchivoOriginal, string nombreArchivoOrdenado)
{ std::fstream original(nombreArchivoOriginal, std::ios::in);
    // Verificando si se pudo abrir el archivo
    if (!original.is_open()) {
        std::cout << "Error abriendo archivo \"datos.txt\"\n";
        return;
    }
    // Crear un objeto archivo que crea un archivo "datos_ordenados.txt"
    std::fstream ordenada(nombreArchivoOrdenado, std::ios::out);
    // Verificando si se pudo abrir el archivo
    if (!ordenada.is_open()) {
        std::cout << "Error abriendo archivo \"datos_ordenados.txt\"\n";
        return;
    }
    // Lee las lineas desde el archivo fuente en el ejemplo "datos.txt"
    // hacia un mapa (se ordena automaticamente)
    std::map<int, int> data;
    std::string key;
    while(std::getline(original, key))
    {
        data[stoi(key)]++; // Convirtiendo string a entero (stoi)
    }
    // Grabar los elementos del mapa al archivo que tendra los datos ordenados
    // en el ejemplo : "datos_ordenados.txt"
    for (auto it = begin(data); it != end(data); ++it) {
        for (int i = 0; i < it->second; ++i)
            ordenada << it->first << '\n';
    }
    original.close();
    ordenada.close();
}

// 3. Escribir un programa que a partir del archivo ordenado ("datos_ordenados.txt") genere
//   directamente un archivo con 2 columnas ("datos_contados.txt").
void generar_datos_contados(string nombreArchivoOrdenado, string nombreArchivoContados)
{
    // Crear un objeto archivo que abra un archivo "datos_ordenados.txt"
    std::fstream ordenada(nombreArchivoOrdenado, std::ios::in);
    // Verificando si se pudo abrir el archivo
    if (!ordenada.is_open()) {
        std::cout << "Error abriendo archivo \"datos_ordenados.txt\"\n";
        return;
    }
    // Crear un objeto archivo que crea un archivo "datos_contados.txt"
    std::fstream contados(nombreArchivoContados, std::ios::out);
    // Verificando si se pudo abrir el archivo
    if (!contados.is_open()) {
        std::cout << "Error abriendo archivo \"datos_contados.txt\"\n";
        return;
    }
    // Contando y Grabando los valores en el nuevo archivo "datos_contados.txt"
    std::string line;
    std::getline(ordenada, line);
    int value = stoi(line);
    int contar = 1;
    while (std::getline(ordenada, line)) {
        if (value != stoi(line)) {
            contados << value << ", " << contar << '\n';
            value = stoi(line);
            contar = 0;
        }
        contar++;
    }
    // Grabando el ultimo valor
    contados << value << ", " << contar << '\n';
    ordenada.close();
    contados.close();
}

