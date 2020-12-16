# Universidad de La Laguna
# Escuela Superior de Ingeniería y Tecnología
# Grado en Ingeniería Informática
# Informática Básica
#
# @author Thomas Edward Bradley
# @date 17 dic 2020
# @brief A makefile used to compile the files in "IB-P10-Files-Doxygen"
# 

CXX = g++
CXXFLAGS = -std=c++14 -g -Wall
LDFLAGS =

all: cripto

cripto: funciones_cripto.o cripto.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

.PHONY: all clean

clean :
	rm -rf *.o cripto ../doc
	rm -rf *~ basura b i
	rm -rf a.out
	find . -name '*~' -exec rm {} \;
	find . -name basura -exec rm {} \;