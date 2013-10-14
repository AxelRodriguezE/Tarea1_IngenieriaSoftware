// Integral de una función polinómica

#include <iostream>
#include <cstdio>
#incluse <math.h>

using namespace std;

int main()
{
int n, i, max;
float integral=0;

cout<<"Grado del polinomio: ";
cin>>n;
int v[n];
for(i=0; i<=n; i++)
{
 cout<<"introduce el coeficiente de grado "<<i<<": ";
 cin>>v[i];
}
cout<<"La integral del polinomio es: \n";
for(i=0; i<=n; i++)
{
 cout<<1.0*v[i]/(i+1)<<"x^"<<i+1<<" ";
}
cout<<endl<<endl;
cout << "Limite superior de la integral: ";
cin>>max;
cout<<" y la integral de dicho polinomio entre 0 y "<<max<<" es: ";
for(i=0; i<=n; i++)
{
 integral=integral + (1.0*v[i]/(i+1))* pow(max,i+1);
}
cout<<integral<<endl;
return 0;
}
