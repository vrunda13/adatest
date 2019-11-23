#include <iostream>
#include<string>
#include<algorithm>
using namespace std;
char print(char b[][],char *x,int i,int j)
{
    
}


int main()
{
  string x,y;
  int m,n;
  cin>>x>>y;
  m=x.length();
  n=y.length();
  int a[m+ 1][n + 1];
  char b[m+ 1][n+ 1]={'e'};

  for(int i=0;i<=m;i++)
  {
      for(int j=0;j<=n;j++)
      {
          if(i==0 || j==0)
          {
              a[i][j]=0;
             
          }
          else if((x[i-1] == y[j-1] ) && i>0 && j>0)
          {
              a[i][j]=(a[i-1][j-1]) + 1;
              b[i][j]='$';
             
             
          }
          else if((x[i-1] != y[j-1] ) && i>0 && j>0)
          {
              a[i][j]=std::max(a[i-1][j],a[i][j-1]);
              if(a[i-1][j]>=a[i][j-1])
              {
                  b[i][j]='^';
              }
              else if(a[i-1][j]<a[i][j-1])
              {
                  b[i][j]='<';
              }
          }
      }
  }
  for(int i=0;i<=m;i++)
  {
      for(int j=0;j<=n;j++)
      {
          cout<<a[i][j];
          cout<<" ";
      }
      cout<<"\n";
  }
   for(int i=0;i<=m;i++)
  {
      for(int j=0;j<=n;j++)
      {
          cout<<b[i][j];
          cout<<" ";
      }
      cout<<"\n";
  }
  
    return 0;
}
