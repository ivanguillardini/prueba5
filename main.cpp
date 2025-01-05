#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <sstream>

using namespace std;

//la estrucutra del nodo

struct Nodo {
    int valor;
    unordered_set<int> siguiente;
    Nodo(int v) : valor(v) {}
};

//grafo para almacenar los nodos
unordered_map<int, Nodo*> grafo;

//función para establecer la relación de precedencia entre nodos
void Relacion(int a, int b) {
    if (grafo.find(a) == grafo.end()) {
        grafo[a] = new Nodo(a);
    }
    if (grafo.find(b) == grafo.end()) {
        grafo[b] = new Nodo(b);
    }
    grafo[a]->siguiente.insert(b);
}

//funcion  para verificar si la secuencia está en el orden correcto
bool validar(const vector<int>& secuencia) {
    for (size_t i = 0; i < secuencia.size() - 1; ++i) {
        int a = secuencia[i];
        int b = secuencia[i + 1];

        //verificamos si a precede a b

        if (grafo.find(a) != grafo.end() && grafo[a]->siguiente.find(b) == grafo[a]->siguiente.end()) {
            return false;
        }
    }
    return true;
}

int main() {
    string linea;
    
    //leemos las reglas de precedencia hasta encontrar "fin"

    cout << "Introduce las relaciones de precedencia con formato A|B y termina con 'fin':\n";
    while (true) {
        getline(cin, linea);
        if (linea == "fin") {
            break;
        }
        

        size_t pos = linea.find('|');
        if (pos != string::npos) {

            int a = stoi(linea.substr(0, pos));
            int b = stoi(linea.substr(pos + 1));
            Relacion(a, b);

        }
    }

    //leemos las secuencias hasta encontrar "fin"
    vector<vector<int>> secuencias;
    cout << "Introduce las secuencias de números con formato A,B,C... y terminar con 'fin':\n";
    while (true) {
        getline(cin, linea);
        if (linea == "fin") {
            break;
        }

        stringstream ss(linea);
        vector<int> secuencia;
        string num;
        while (getline(ss, num, ',')) {
            secuencia.push_back(stoi(num));
        }
        secuencias.push_back(secuencia);

    }

    //variable global para almacenar la suma de los números del medio de las secuencias válidas
    int suma = 0;

    //comprobamos que cada secuencia es válida y si lo es sumamos a suma el valor de en medio
    for (const auto& secuencia : secuencias) {
        if (validar(secuencia)) {

            int medio = secuencia[secuencia.size() / 2];
            suma += medio;
        }
    }

    //mostramos por pantalla el resultado final
    cout << "La suma de los números del medio de las secuencias válidas es: " << suma << endl;

    //Liberamos la memoria utilizada
    for (auto& par : grafo) {
        delete par.second;
    }

    return 0;
}

