/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Thomas Edward Bradley
 * @date 17.dic.2020
 * @brief Aqui se declara la constante "kHelpText" y las funciones usadas 
 *        en funciones_cripto.cc
 */

#include <iostream>
using namespace std;

const string kHelpText =  "Este programa puede resolver y encriptar en dos formatos distintos: \
Cifrado xor (usamos el comando xor junto a una clave secreta    para facilmente \
encriptar el mensaje, hiendo caracter por caracter) \
 / Cifrado de Cesar (se rota la posicion de cada caracter segun un valor k \
decidido por el usuario) \
                                                                      \
                          \
El orden de los parametros que debe introducir es: \
./cripto fichero_entrada fichero_salida método(xor / cesar) password operación";

void Usage (int argc, char *argv[]);
string CifradoXor (string texto, string password);
string CifradoCesar (string texto, int knumero);
int NumeroDeA (string texto);