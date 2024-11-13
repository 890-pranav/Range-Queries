#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
//template <class T> 
//using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

struct SegmentTree {
    vector<int> tree;  
    ll n;
 
    SegmentTree(ll size) {
        n = size;
        tree.resize(4 * n);
    }
 
    
    void build(const string &s, ll node, ll start, ll end) {
        if (start == end) {
            tree[node] = 1 << (s[start] - 'a');  
        } else {
            ll mid = (start + end) / 2;
            build(s, 2 * node + 1, start, mid); 
            build(s, 2 * node + 2, mid + 1, end);  
            tree[node] = tree[2 * node + 1] | tree[2 * node + 2];  
        }
    }
 
    void update(ll pos, char t, ll node, ll start, ll end) {
        if (start == end) {
            tree[node] = 1 << (t - 'a');  
        } else {
            ll mid = (start + end) / 2;
            if (pos <= mid) {
                update(pos, t, 2 * node + 1, start, mid);  
            } else {
                update(pos, t, 2 * node + 2, mid + 1, end);  
            }
            tree[node] = tree[2 * node + 1] | tree[2 * node + 2];  
        }
    }
 
   
    int query(ll node, ll left, ll right, ll start, ll end) {
        if (left > end || right < start) {
            return 0; 
        }
        if (left <= start && end <= right) {
            return tree[node]; 
        }
        ll mid = (start + end) / 2;
        int leftResult = query(2 * node + 1, left, right, start, mid);
        int rightResult = query(2 * node + 2, left, right, mid + 1, end);
        return leftResult | rightResult; 
    }
 
    void build(const string &s) {
        build(s, 0, 0, n - 1);
    }
 
    void update(ll pos, char t) {
        update(pos, t, 0, 0, n - 1);
    }
 
    int query(ll left, ll right) {
        return query(0, left, right, 0, n - 1);
    }
};

void solve(){
    string s;
    cin>>s;
    ll n=s.size();
    ll q;
    cin>>q;
    SegmentTree segtree(n);
    segtree.build(s);
    while(q--){
        ll a;
        cin>>a;
        if(a==1){
            ll b;
            char t;
            cin>>b>>t;
            b--;
            s[b]=t;
            segtree.update(b,t);
        }
        else{
            ll b,c;
            cin>>b>>c;
            b--;
            c--;
            ll bitmask = segtree.query(b, c); 
            cout << __builtin_popcount(bitmask) << endl;
        }
    }
}

int main(){
    fastio();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt","w",stdout);
    #endif
    //TIN{
    solve();
    //}
    #ifndef ONLINE_JUDGE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
}
