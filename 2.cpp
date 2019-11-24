#include<bits/stdc++.h>
using namespace std;
int i,j,n,m,p[10],w[10],v[10][10];
int max(int x,int y)
{
if(x>y)
return x;
else
return y;
}
void knapsack()
{
int l[10],k=0;
for(i=0;i<=n;i++)
{
for(j=0;j<=m;j++)
{
if(i==0||j==0)
v[i][j]=0;
else if(j-w[i]<0)
v[i][j]=v[i-1][j];
else
v[i][j]=max(v[i-1][j],v[i-1][j-w[i]]+p[i]);
}
}
cout<<"\n Output is:\n";
for(i=0;i<=n;i++)
{
for(j=0;j<=m;j++)
{
cout<<v[i][j]<<"\t";
}
cout<<"\n\n";
}
int j=m;
cout<<"the optimal solution is:"<<v[n][m]<<"\n";
for(int i=n;i>=1;i--)
{
    if(v[i][j]>v[i-1][j])
    {
        k=k+1;
        l[k]=i;
        j=j-w[i];
    }
}
for(int i=1;i<n;i++)
{
    cout<<l[i]<<" ";
}
}
int main()
{
cout<<"\nEnter the no. of items:\t";
cin>>n;
cout<<"\nEnter the weight of the each item:\n";
for(i=1;i<=n;i++)
  cin>>w[i];
cout<<"\nEnter the profit of each item:\n";
for(i=1;i<=n;i++)
 cin>>p[i];
cout<<"\nEnter the knapsack's capacity:\t";
cin>>m;
knapsack();
return 0;
}
