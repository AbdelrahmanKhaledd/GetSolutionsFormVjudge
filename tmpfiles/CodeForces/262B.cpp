#include <bits/stdc++.h>
using namespace std ;

int main() {
    int n,k;
    cin>>n>>k;
    vector <int>x (n);
    for (int i =0 ;i <n ;i++)
        cin>>x[i];
    sort(x.begin(),x.end());
    int cnt =0;
    long long  sum=0;
    while (k&& cnt < n )
    {
        if (x[cnt]<0 )
        {
            x[cnt] =-1*x[cnt];
            cnt++;
            k--;

        }
        else
            break;
    }

        if (k!=0 && k%2 !=0)
        {
            x[--cnt] *=-1;
        }


    for (int j =0 ;j <n ;j++)
        sum=sum+x[j];

    cout<<sum;

    return 0;
}
