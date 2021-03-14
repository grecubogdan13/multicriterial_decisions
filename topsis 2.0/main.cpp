///topsis method
#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;
int n,m,i,j,sum,t[100];
float aux,a[100][100],nn[100],w[100],b[100],s[100],db[100],dw[100];
char c[100];
void citire()
{
 cout<<"introduceti numarul de alternative: "; cin>>n;
 cout<<"introduceti numarul de criterii: "; cin>>m;
 for(i=1;i<=m;i++)
 {
     cout<<"introduceti tipul criteriului "<<i<<" (M/m)";
     cin>>c[i];
 }
 for(i=1;i<=n;i++)
 {
    for(j=1;j<=m;j++)
    {
        cout<<"introduceti raspunsul variantei "<<i<<" la criteriul "<<j<<" ";
        cin>>a[i][j];
    }
 }
 cout<<"introduceti note pentru criteriul care sa reflecte importanta lor(1-cel mai putin important;10-cel mai important):"<<'\n';
 for(i=1;i<=m;i++)
 {
    cout<<"criteriul "<<i<<":";
    cin>>nn[i];
    sum=sum+nn[i];
 }
 for(i=1;i<=m;i++)
 {
     nn[i]=nn[i]/sum;
 }
}
void normalizare()
{
    for(j=1;j<=m;j++)
    {
        sum=0;
        for(i=1;i<=n;i++)
        {
            sum=sum+a[i][j]*a[i][j];
        }
        sum=sqrt(sum);
        for(i=1;i<=n;i++)
        {
            a[i][j]=a[i][j]/sum;
        }
    }
}
void topsis()
{
	for(j=1;j<=n;j++)
    {
        w[j]=a[1][j];
        b[j]=a[1][j];
        for(i=1;i<=n;i++)
        {
            if(c[j]=='M')
            {
               if(w[j]>a[i][j]) w[j]=a[i][j];
               if(b[j]<a[i][j]) b[j]=a[i][j];
            }
            else
            {
               if(w[j]<a[i][j]) w[j]=a[i][j];
               if(b[j]>a[i][j]) b[j]=a[i][j];
            }
        }
    }
     for(i=1;i<=n;i++)
     {
         for(j=1;j<=m;j++)
         db[i]=db[i]+(nn[j]*b[j]-a[i][j]*nn[j])*(nn[j]*b[j]-a[i][j]*nn[j]);
         db[i]=sqrt(db[i]);
         for(j=1;j<=m;j++)
         dw[i]=dw[i]+(w[j]-a[i][j])*nn[j]*(w[j]-a[i][j])*nn[j];
         dw[i]=sqrt(dw[i]);
     }
     for(i=1;i<=n;i++)
     {
         s[i]=dw[i]/(dw[i]+db[i]);
     }
}
void ordonare()
{
    for(i=1;i<=n;i++)
        t[i]=i;
    for(i=1;i<n;i++)
        for(j=i+1;j<=n;j++)
        {
            if(s[i]<s[j])
            {
                aux=s[i];
                s[i]=s[j];
                s[j]=aux;
                aux=t[i];
                t[i]=t[j];
                t[j]=aux;
            }
        }
}
void afisare()
{
    for(i=1;i<=n;i++)
        cout<<s[i]<<" "<<t[i]<<'\n';
}
int main()
{
 citire();
 normalizare();
 topsis();
 ordonare();
 afisare();
 getch();
 return 0;
}
