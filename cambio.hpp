#include <vector>
#include <list>
#include <iostream>
#include <cstdio>
#include <set>
#include <iomanip>
#include <sstream>

using namespace std;

class Cambio{
    private:
        list<int> monedas_;
    public:
        Cambio(void);
        ~Cambio(void);
        list<int> devolver_cambio(string entrada);
        bool solucion(list<int> final, int n);
        int seleccionar(set<int> c);
        set<int> renovar(set<int> c, int candidato, list<int> final, int n);
        bool factible(list<int> final, int candidato, int n);
        int convertir(string entrada);
        void mostrar(list<int> final);
};