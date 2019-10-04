#include <iostream>

using namespace std;
void cambio(int &a , int &b){
    int c;
    c=a;
    a=b;
    b=c;
}
void imprimirI(int arr[],int tam){
    for(int i=0;i<tam;i++){
        cout<<arr[i]<<endl;
    }
}
void imprimirR(int arr[],int tam, int index=0){

    if (tam==index+1){
        cout<<arr[index]<<endl;
    }

    else{
        cout<<arr[index]<<endl;
        index++;
        imprimirR(arr,tam,index);
    }
}
int sumaR(int arr[], int tam,int index=0){
    if(tam==index+1){
        return (arr[index]);
    }
    else{
        index++;
        return (arr[index-1]+sumaR(arr,tam,index));
    }
}
int sumaI(int arr[],int tam){
    int c=0;
    for(int i=0 ; i< tam; i++){
        c+=arr[i];

    }
    return c;
}
void ordenarI(int arr[],int tam){

    for(int i=0;i<tam;i++){
        cambio(arr[i],arr[--tam]);

    }
}
void ordenarR(int *arr,int tam){
    tam--;
    cambio(*(arr++),*(arr+tam));


    if(tam>1)
        ordenarR(arr,tam);


}
int main()
{

    int x[5]={1,2,3,4,5};
    //imprimirR(x,5);
    //cout<<sumaR(x,5);
    ordenarR(x,5);
    imprimirI(x,5);
    return 0;
}
