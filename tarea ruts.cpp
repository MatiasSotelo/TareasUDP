#include<iostream>
#include<string>

using namespace std;

int main() {

    int cantidad_de_ruts;
    cout<<"Ingrese la cantidad de ruts"<<endl;
    cin>>cantidad_de_ruts;
	cout<<"================================================"<<endl;
    int numeros[6] = {2,3,4,5,6,7};

    int correctos = 0;
    int incorrectos = 0;

    for(int i = 0; i < cantidad_de_ruts; i++){
        string rut;
        cout<<"Ingrese el rut"<<endl;
        cin>>rut;

        int guion = rut.find("-");

        string numeros_rut = rut.substr(0, guion);
        string digito_verificador = rut.substr(guion+1, guion+1);

        int suma = 0;

        for(int i = numeros_rut.size()-1, j = 0; i >= 0; i--, j++){
            if(j > 5){
                j = 0;
            }
            int numero = (int)numeros_rut[i]-'0';
            int temp = (numero * numeros[j]);
            suma += temp;

        }

        int d = 11-(suma%11);
        int digitoverificador = (int)digito_verificador[i]-'0';
    
        if(d == 11 && '0' == digito_verificador[0]){
            cout<<"El rut "<<rut<<" es valido"<<endl;
            correctos++;
        } else if(d == 10 && ('k' == digito_verificador[0] || 'K' == digito_verificador[0])){
            cout<<"El rut "<<rut<<" es valido"<<endl;
            correctos++;
        } else if(d == digitoverificador){
            cout<<"El rut "<<rut<<" es valido"<<endl;
            correctos++;
        } else {
            cout<<"El rut "<<rut<<" no es valido"<<endl;
            incorrectos++;
        }
    }

    cout<<"Ingresaste: "<<correctos<<" ruts validos y "<<incorrectos<<" ruts invalidos";
}
