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
void imprimirR(int arr[],int tam,int index=0){
    if(index<tam){
        cout<<arr[index]<<' ';
        imprimirR(arr,tam,++index);


    }
}
void invertirR(int arr[],int tam,int index=0){
    tam--;
    if(tam>=1 && tam>index){

        cambio(arr[index],arr[tam]);
        invertirR(arr,tam,++index);
    }
}

void burbuja(int arr[],int n){
    int i,j;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1])
                cambio(arr[j],arr[j+1]);
        }
    }
}

void insercion(int arr[],int n){
    int i, actual,j;
    for (i = 1; i < n; i++){
        actual=arr[i];
        j=i-1;
        while (j >= 0 && arr[j] > actual){
            arr[j+1]=arr[j];
            j--;

        }
        arr[j+1]=actual;
    }


}



int partir(int a[],int inicio,int fin){
    int ss=a[fin];


    int indice=inicio;
    int i;

    for(i=inicio;i<fin;i++)
    {
    	if(a[i]<=ss)
        {
            cambio(a[i],a[indice]);
            indice++;
        }
     }
     cambio(a[fin],a[indice]);
     return indice;
 }
 void Quicksort(int a[],int inicio,int fin)
 {
    if(inicio<fin){
         int indice=partir(a,inicio,fin);
             Quicksort(a,inicio,indice-1);
             Quicksort(a,indice+1,fin);
    }
}


int main()
{
    int n=12;
    int x[n]={1,2,3,4,5,6,7,8,9,83,1,0};
    invertirR(x,n);
    imprimirR(x,n);
    cout<<endl;


    Quicksort(x,0,n-1);


    imprimirR(x,n);
    cout<<" quicksort"<<endl;




    return 0;
}
