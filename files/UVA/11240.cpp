#include <bits/stdc++.h>
using namespace std ;

int main()
{
    int t ; cin>>t ; 
    while(t--)
    {
        int n ;cin>>n;
        int arr[n];
        for (int i =0; i<n ;i++)
            cin>>arr[i];
        int cnt =0 ; 
        int cur = INT_MAX ; 
        for (int i =0 ;i <n-1 ;i++)
        {
            if (((float)cur /(arr[i+1]-arr[i])) <0  )
                cnt++;
            cur = arr[i+1]-arr[i];
        }
        cout<<cnt+1<<endl;
    }
    return 0 ;
}