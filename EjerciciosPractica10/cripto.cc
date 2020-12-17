/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Thomas Edward Bradley
 * @date 17.dic.2020
 * @brief Este programa puede resolver y encriptar en dos formatos distintos: 
 *        Cifrado xor (usamos el comando "xor" junto a una clave secreta para facilmente
 *        encriptar el mensaje, hiendo carácter por carácter)
 *        Cifrado de César (se rota la posición de cada carácter según un valor "k" 
 *        decidido por el usuario)
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "funciones_cripto.h"
using namespace std;

int main (int argc, char* argv []) {
  Usage (argc, argv);
  string fichero_entrada = argv[1];
  string fichero_salida = argv[2];
  string metodo = argv[3];
  string operacion = argv[5];
  string password = argv[4];
  ofstream FicheroSalida;
  ifstream FicheroEntrada (fichero_entrada);
  string texto_entrada;
  if (FicheroEntrada.is_open())
         while (FicheroEntrada.good())
             getline(FicheroEntrada, texto_entrada);
    FicheroEntrada.close();
  
  cout << NumeroDeA (texto_entrada) << endl;
  
  if (operacion == "+") {
    if (metodo == "cesar") {
      const int knumero = stoi (password);
      FicheroSalida.open (fichero_salida);
      FicheroSalida << CifradoCesar (texto_entrada, knumero);
      FicheroSalida.close ();
    } else if (metodo == "xor") {
      FicheroSalida.open (fichero_salida);
      FicheroSalida << CifradoXor (texto_entrada, password);
      FicheroSalida.close ();
    } else {
      cout << "Inserte un metodo valido: xor o cesar";
    return 0;
    }
  } else if (operacion == "-") {
    if (metodo == "cesar") {
      const int knumero = stoi (password);
      FicheroSalida.open (fichero_salida);
      FicheroSalida << CifradoCesar (texto_entrada, -knumero);
      FicheroSalida.close (); 
    } else if (metodo == "xor") {
      FicheroSalida.open (fichero_salida);
      FicheroSalida << CifradoXor (CifradoXor (texto_entrada, password), password);
      FicheroSalida.close ();
    } else {
      cout << "Inserte un metodo valido: xor o cesar";
    return 0;
    } 
  } else {
      cout << "Inserte un operador valido: + o -";
      return 0; 
  }
}