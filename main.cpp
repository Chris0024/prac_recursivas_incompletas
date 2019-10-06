#include <iostream>

using namespace std;

void cambio(int &a , int &b){
	int c;
	c=a;
	a=b;
	b=c;
}

void burbuja(int *arr,int n){
	int i,j;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1-i;j++){
			if(*(arr+j)>*(arr+j+1))
				cambio(*(arr+j),*(arr+j+1));
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




void imprimirI(int *arr,int tam){
	for(int i=0;i<tam;i++){
		cout<<*arr++<<'\t';
	}
}
void imprimirR(int *arr,int tam){

	if (tam==1){
		cout<<*(arr+--tam)<<'\t';
	}

	else{
		cout<<*arr++<<'\t';

		imprimirR(arr,--tam);
	}
}
int sumaR(int *arr, int tam){
	if(tam==1){
		return *arr;
	}
	else{
		return *arr + sumaR(++arr,--tam);
	}
}
int sumaI(int *arr,int tam){
	int c=0;
	for(int i=0 ; i< tam; i++){
		c+=*arr++;

	}
	return c;
}
void inverI(int *arr,int tam){

	for(int i=0;i<tam;i++){
		cambio(*(arr+i),*(arr+--tam));

	}
}
void inverR(int *arr,int tam){
	tam--;
	cambio(*arr++,*(arr+tam));
	if(tam>1)
		inverR(arr,--tam);


}
int main()
{

	int x[5]={1,2,3,4,5};
	int y[8]={1,5,3,6,9,8,4,6};

    imprimirI(y,8);
    cout<<'\n'<<" burbuja"<<endl;


    Quicksort(y,0,8-1);
    imprimirI(y,8);

	return 0;
}

