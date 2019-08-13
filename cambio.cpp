#include "cambio.hpp"

Cambio::Cambio(void){
    //insertamos las monedas y los billetes como centimos
    monedas_.push_back(50000);
    monedas_.push_back(20000);
    monedas_.push_back(10000);
    monedas_.push_back(5000);
    monedas_.push_back(2000);
    monedas_.push_back(1000);
    monedas_.push_back(500);
    monedas_.push_back(200);
    monedas_.push_back(100);
    monedas_.push_back(50);
    monedas_.push_back(20);
    monedas_.push_back(10);
    monedas_.push_back(5);
    monedas_.push_back(2);
    monedas_.push_back(1);
}

Cambio::~Cambio(void){
    monedas_.clear();
}

list<int> Cambio::devolver_cambio(string entrada){
    list<int> final;
    set<int> c;
    
    //insertamos las monedas en el set c que son los candidatos
    for(list<int>::iterator it=monedas_.begin();it!=monedas_.end();it++)
        c.insert(*it);
        
    int n=convertir(entrada);
    int candidato;
    
    while((!c.empty())&&(solucion(final, n)==false)){
        candidato=seleccionar(c);
        c=renovar(c,candidato,final,n);
        if(factible(final,candidato,n)) //si es factible, 
            final.push_back(candidato);
    }
    
    if(solucion(final, n))
        return final;
    else{
        final.clear();   //si no es solucion, retorno una lista vacia ya que no obtuve una solucion
        return final;
    }
}

bool Cambio::solucion(list<int> final, int n){
    
    int suma=0;
    for(list<int>::iterator it=final.begin();it!=final.end();it++){
        suma+=(*it);
    }
    
    if(suma==n)
        return true;
    else
        return false;
}

int Cambio::convertir(string entrada){
    float numero;
    string final;
    for(int i=0;i<entrada.size();i++){
        if(entrada[i]==',')
            final+='.';
        else
            final+=entrada[i];
    }
    
    istringstream(final)>>numero;
    numero=numero*100;
    
    return numero;
}

set<int> Cambio::renovar(set<int> c, int candidato, list<int> final, int n){
    int suma=0;
    for(list<int>::iterator it=final.begin();it!=final.end();it++){
        suma+=(*it);
    }
    suma+=candidato;
    if(suma>n)
        c.erase(candidato);
    return c;
}

int Cambio::seleccionar(set<int> c){
    //Función de selección: escoge la moneda de valor más alto que quede en el conjunto de candidatos.
    int numero=0;
    set<int>::reverse_iterator rit=c.rbegin();
    
    return (*rit);
}

bool Cambio::factible(list<int> final, int candidato, int n){
    int suma=0;
    final.push_back(candidato);
    for(list<int>::iterator it=final.begin();it!=final.end();it++){
        suma+=(*it);
    }
    
    if(suma<=n)
        return true;
    else
        return false;
}

void Cambio::mostrar(list<int> final){
    int numero=0;
    int coma=0;
    set<int> conjunto;
    for(list<int>::iterator it=final.begin();it!=final.end();it++)
        conjunto.insert(*it);
    cout<<endl;
    cout<<"SOLUCION = { ";
    for(set<int>::reverse_iterator rit=conjunto.rbegin();rit!=conjunto.rend();rit++){
        for(list<int>::iterator it1=final.begin();it1!=final.end();it1++){
            if((*rit)==(*it1)){
                numero++;
            }
        }
        if((*rit)>=100)
            cout<<numero<<"x"<<(*rit)/100<<"€ ";
        else
            cout<<numero<<"x"<<(*rit)<<"¢ ";
        
        if(coma!=conjunto.size()-1)
            cout<<",";
            
        numero=0;
        coma++;
    }
    cout<<"}"<<endl<<endl;
}