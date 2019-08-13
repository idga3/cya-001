#include "cambio.hpp"

int main (void){
    string entrada;
    Cambio devolver;
    list<int> monedas;
    string opcion;
    
    do{
        cout<<"CAMBIO CON BILLETES Y MONEDAS"<<endl<<endl;
        cout<<"Introduzca la cantidad que quiere cambiar:";
        cin>>entrada;
        
        monedas=devolver.devolver_cambio(entrada);
        
        if(!monedas.empty())
            devolver.mostrar(monedas);
        else
            cout<<"NO SE PUEDE DEVOLVER ESA CIFRA"<<endl<<endl;
            
        cout<<"¿Quieres seguir cambiando monedas y billetes? [SI/NO] : ";
        cin>>opcion;
        cout<<endl;
    }while(opcion=="SI");
    return 0;
}