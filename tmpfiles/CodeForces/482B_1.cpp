#include <bits/stdc++.h>
using namespace std;
#define pb(i) push_back(i)
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second
#define debug(x) cout<<(#x)<<": \""<<x<<"\""<<endl
#define debugVec(vec) cout<<(#vec)<<": "; for (auto& i: vec) cout<<i<<" "; cout<<endl
 
template<class A, class B> ostream& operator <<(ostream& out, const pair<A, B> &p) {
    return out << "(" << p.ff << ", " << p.ss << ")";
}
template<class A> ostream& operator <<(ostream& out, const vector<A> &v) {
    out << "[";
    for(int i =0; i< sz(v) ; i++) {
        if(i) out << ", ";
        out << v[i];
    }
    return out << "]";
}
typedef long long ll;
typedef unsigned long long ull;

class segmantree {
private:
    int N ;
    vector<int> arr,sTree , lazy ;
public :
    segmantree(vector<int>&in)
    {
        arr =in ; 
        N = in.size()-1 ;
        sTree.assign(N<<1, 1 );
        lazy.assign(N<<1, 1 );
        build(1 ,1, N );

    }
    int left(int node ){return node <<1;}
    int right(int node ){return (node <<1) +1 ;}

    void build (int node  , int l , int r )
    {
        if(l== r )
            sTree[node]=(arr[l]>1 ) ? 1 : (arr[l]==0) ? 0 : -1;
        else 
        {
            int mid = l +r >> 1 ;
            build(left(node) , l , mid );
            build(right(node) , mid+1  , r );
            sTree[node]= sTree[left(node)]*sTree[right(node)];

        }
    }

    void update_point(int ind , int val )
    {
        ind +=N-1 ;
        sTree[ind]=val;
        while(ind >1 )
        {
            ind>>=1 ;
            sTree[ind] = sTree[ind <<1]*sTree[(ind <<1) +1];
        }
    }
    void update_range(int i, int j ,int val){update_range(1 , 1 , N , i ,j , val);}
    void update_range(int node ,int l ,int r , int i ,int j , int val)
    {
        if(i > r || j < l)return;
        if(l >= i && r <=j)
            sTree[node]+=(r -l +1)*val , lazy[node]+=val;
        else
        {
            int mid = l + r >> 1 ;
            progragate(node , l , mid , r );
            update_range(left(node) , l ,mid , i ,j , val);
            update_range(right(node) , mid+1  ,r , i ,j , val);
            sTree[node]=sTree[left(node)]+sTree[right(node)];


        } 
    }
    void progragate(int  node , int l , int mid ,int r )
    {
        lazy[left(node)]*=lazy[node];
        lazy[right(node)]*=lazy[node];
        sTree[left(node)]*=(mid-l+1 )*lazy[node];
        sTree[right(node)]*=(r-mid )*lazy[node];
        lazy[node]= 0 ;

    }
    int query(int i ,int j ){return query(1 , 1  ,N ,  i , j );}

    int query(int node ,int l ,int r , int i ,int j)
    {
        if( i > r || j < l )return 1;
        if(l >= i && r <= j )return sTree[node];
        int mid = l + r >>1 ; 
        //progragate(node , l, mid , r );
        int q1 = query(left(node ) , l , mid , i ,j );
        int q2 = query(right(node ) , mid+1 ,r , i ,j );
        return q1 * q2 ; 
    }

};



int n , q; 
void solve()
{
    int N = 1<< (int)ceil(log2(n));
    vector<int >arr(N+1, 1  );
    for(int i =1;i  <=n ;i++)cin>> arr[i];
    segmantree sg (arr );
    while(q--)
    {
        char c; int l ,r ; 
        cin>>c >> l >>r ; 
        if(c== 'C')sg.update_point(l ,r );
        else
        {
            int res = sg.query(l ,r );
            if(res == 0 )cout<<0;
            else if(res > 0 )cout<<'+';
            else cout<<'-';
        }

    }
    cout<<endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    
    while(cin >>n>>q )
    {
        solve();
    }
    return 0 ; 
}