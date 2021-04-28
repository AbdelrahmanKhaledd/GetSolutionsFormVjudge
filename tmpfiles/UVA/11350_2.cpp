#include <bits/stdc++.h>
using namespace std;
#define pb(i) push_back(i)
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

class stat{
public :
    int up ,down ;
public :
    stat():up(0),down(0){}
    stat(int up ,int down ):up(up) , down(down){}
    stat operator+ (const stat &other){
        return stat (other.up + this->up , other.down + this->down);
    }
};
string s ;
void solve()
{
    getline(cin , s ) ;
    stat  left(0 , 1 ) , right (1 ,0) , cur(1,1);
    for(char i : s ){
        stat tmp; 
        switch (i){
        case 'L':
            tmp = cur ;
            cur = cur + left ;
            right = tmp ; 
            break;
        
        case 'R':
            tmp = cur ;
            cur = cur + right ; 
            left = tmp  ;
            break;
        }
       
    }
    cout << cur.up<<"/"<<cur.down<<endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t ; cin>>t ;
    getline(cin , s );
    while(t--){
        solve();
    }
    return 0 ; 
}