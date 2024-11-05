#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <class T> 
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define MOD1 998244353
#define INF 1e18
#define endl "\n"
#define pb push_back
#define ppb pop_back
#define PI 3.141592653589793238462
#define all(a) a.begin(), a.end()
#define read(v,n) for(int i=0;i<n;i++)cin>>v[i]
#define TIN ll t=0;cin>>t;for(int i=0;i<t;i++)
#define no() cout << "NO" << endl
#define yes() cout << "YES" << endl
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
 
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

int main(){
    fastio();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt","w",stdout);
    #endif
    //TIN{
        //cout<<"Case #"<<i+1<<":";
        ll n;
        cin>>n;
        vector<ll> v(n);
        read(v,n);
        Tree<ll>ltree;
        vector<ll> lcnt(n,0);
        for(int j=0;j<n;j++){
            lcnt[j]=ltree.size()-ltree.order_of_key(v[j]);
            ltree.insert(v[j]);
        }
        Tree<ll>rtree;
        vector<ll> rcnt(n,0);
        for(int j=n-1;j>=0;j--){
            rcnt[j]=rtree.order_of_key(v[j]);
            rtree.insert(v[j]);
        }
        ll res=0;
        for(ll j=0;j<n;j++){
            res+=(lcnt[j]*rcnt[j]);
        }
        cout<<res<<endl;
    //}
    #ifndef ONLINE_JUDGE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
}
