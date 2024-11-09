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

struct SegmentTree{
    vector<ll> tree;
    ll n;

    SegmentTree(ll size){
        n=size;
        tree.resize(4*n);
    }

    void build(vector<ll> v,ll node,ll start,ll end){
        if(start==end){
            tree[node]=v[start];
        }
        else{
            ll mid=(start+end)/2;
            build(v,2*node,start,mid);
            build(v,2*node+1,mid+1,end);
            tree[node]=tree[2*node]+tree[2*node+1];
        }
    }

    ll query(ll node,ll left,ll right,ll start,ll end){
        if(left>end || right<start){
            return 0;
        }
        if(left>=start && right<=end){
            return tree[node];
        }
        else{
            ll mid=(start+end)/2;
            ll left=query(2*node,left,right,start,mid);
            ll right=query(2*node+1,left,right,mid+1,end);
            return left+right;
        }
    }

    void update(ll node,ll start,ll end,ll pos,ll val){
        if(start==end){
            tree[node]=val;
        }
        else{
            ll mid=(start+end)/2;
            if(pos<=mid){
                update(2*node,start,mid,pos,val);
            }
            else{
                update(2*node+1,mid+1,end,pos,val);
            }
            tree[node]=tree[2*node]+tree[2*node+1];
        }
    }

    void build(vector<ll> v){
        build(v,1,0,n-1);
    }

    void update(ll pos,ll val){
        update(1,0,n-1,pos,val);
    }

    ll query(ll i,ll j){
        return query(1,i,j,0,n-1);
    }
};



int main(){
    fastio();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt","w",stdout);
    #endif
    TIN{
        cout<<"Case "<<i+1<<":"<<endl;
        ll n,q;
        cin>>n>>q;
        vector<ll> v(n);
        read(v,n);
        SegmentTree segTree(n);
        segTree.build(v);
        for(int i=0;i<q;i++){
            ll a;
            cin>>a;
            if(a==1){
                ll b;
                cin>>b;
                cout<<v[b]<<endl;
                v[b]=0;
                segTree.update(b,0);
            }
            else if(a==2){
                ll b,c;
                cin>>b>>c;
                v[b]+=c;
                segTree.update(b,v[b]);
            }
            else{
                ll b,c;
                cin>>b>>c;
                cout<<segTree.query(b,c)<<endl;
            }
        }
    }
    #ifndef ONLINE_JUDGE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
}
