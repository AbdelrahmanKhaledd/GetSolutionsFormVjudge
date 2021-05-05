#include <bits/stdc++.h>
using namespace std;
char arr[50][50];
int m,n;
int xx[]={0,0,1,-1};
int yy[]={1,-1,0,0};
int go(int i, int j )
{
    int sum=0;
    if(arr[i][j]=='.'||arr[i][j]=='G' )
    {
        sum+=(arr[i][j]=='G') ? 1:0;
        arr[i][j]='*';
        for(int k =0 ;k < 4 ;k++)
            if(arr[i+xx[k]][j+yy[k]]=='T')
                return sum;
        for(int k =0 ;k <4 ;k++)
            sum+=go(i+xx[k],j+yy[k]);
    }
    return sum;
}
int main()
{
    memset(arr,'*',sizeof(arr));
    while(cin>>m>>n)
    {
        int pi,pj;
        for(int i =0 ;i <n ;i++)
        {
            for(int j =0 ;j < m;j++)
            {
                cin>>arr[i][j];
                if(arr[i][j]=='P')
                    pi=i,pj=j;
            }
        }
        arr[pi][pj]='.';
        cout<<go(pi,pj)<<endl;
    }
    return 0;
}