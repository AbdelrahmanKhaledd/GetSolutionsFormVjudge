#include <bits/stdc++.h>
using namespace std;
#define pb(i) push_back(i)
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second
#define debug(x) cout<<(#x)<<": \""<<x<<"\""<<endl
#define debugVec(vec) cout<<(#vec)<<": "; for (auto& i: vec) cout<<i<<" "; cout<<endl
 
typedef long long ll;
typedef unsigned long long ull;

int main()
{
    
    ll  n ,k ; 
    while(scanf("%lld %lld" , &n ,&k ) , (n||k) )
    {
        if(k > n/2 )
            k -= n/2 ;
        ull res =1 ; 
        for(int i =0 ;i <  k ;i++)
            res *=n-i , res /=(i+1)  ;
       
        printf("%lld\n",res) ;
    }
    
    return 0 ; 
}