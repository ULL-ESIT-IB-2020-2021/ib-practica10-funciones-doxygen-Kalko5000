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
#include <string>
#include <cstdlib>
#include "funciones_cripto.h"
using namespace std;

/** Muestra el modo de uso correcto del programa
 *  En caso de que el uso no sea el correcto, muestra el mensaje y finaliza
 *  la ejecución del programa.
 *  El programa requiere un minimo de 6 parámetros para su ejecución;
 *
 *  @param[in] argc Number de parametros en la línea de codigo
 *  @param[in] argv Vector (char*) que contiene los parámetros
 */

void Usage(int argc, char *argv[]) {
  if (argc != 6) {
    cout << argv[0] << " -- Cifrado de ficheros" << endl;
    cout << "Modo de uso: " << argv[0] << " fichero_entrada fichero_salida";
    cout << " método password operación" << endl;
    cout << "Pruebe: " << argv[0] << " --help para más información" << endl;
  }
  string parametro {argv[1]};
  if (parametro == "--help") {
      cout << kHelpText << endl;
      exit(EXIT_SUCCESS);
  }
}

/** Encripta el texto del metodo "xor"
 * Para descifrar solo hace falta pasar el texto retornado por la funcion de nuevo
 *
 *  @param[in] texto texto proveniente del fichero que introdujo el usuario
 *  @param[in] password contraseña que introdujo el usuario
 *  @return El texto encriptado
 */

string CifradoXor (string texto, string password) {
  int i, n = 0;
  for (n = 0; n < password.length(); n++) {
    password[n] = 128 xor password [n];
  }
  for (i = 0; i < texto.length(); i++) {
    if (n = password.length()) {
      n = 0;
      texto[i] = texto[i] xor password[n];
      n++;
    } else {
      texto[i] = texto[i] xor password[n];
      n++;
    }
  }
  return texto;
}

/** Encripta el texto del metodo "cesar"
 * Para descifrar, solo hace falta introducir knumero de manera negativa
 * 
 * Ciertos valores como "|" no pueden ser descifrados
 *
 *  @param[in] texto texto proveniente del fichero que introdujo el usuario
 *  @param[in] knumero numero constante que usaremos para encriptar el texto
 *  @return el texto encriptado
 */

string CifradoCesar (string texto, int knumero) {
  int i;
  for (i = 0; i < texto.length(); i++) {
    texto[i] = char(int(texto[i]) + knumero);
  }
  return texto;
}

int NumeroDeA (string texto) {
  int i, contador = 0;
  for (i = 0; i < texto.length(); i++) {
    if (texto[i] == 'a') {
      contador++;
    }
  }
  return contador;
}