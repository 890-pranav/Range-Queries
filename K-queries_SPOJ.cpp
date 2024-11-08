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

struct SegmentTree {
    vector<vector<ll>> tree;
    ll n;

    SegmentTree(ll size) {
        n = size;
        tree.resize(4 * n); 
    }

    void build(vector<ll>& v, ll node, ll start, ll end) {
        if (start == end) {
            tree[node].push_back(v[start]);
            return;
        }
        ll mid = (start + end) / 2;
        build(v, 2 * node + 1, start, mid);
        build(v, 2 * node + 2, mid + 1, end);
        merge(tree[2 * node + 1].begin(), tree[2 * node + 1].end(),
              tree[2 * node + 2].begin(), tree[2 * node + 2].end(),
              back_inserter(tree[node]));
    }

    ll query(ll node, ll start, ll end, ll left, ll right, ll x) {
        if (right < start || left > end) {
            return 0; 
        }
        if (left <= start && end <= right) {
            return tree[node].end() - upper_bound(tree[node].begin(), tree[node].end(), x);
        }
        
        ll mid = (start + end) / 2;
        return query(2 * node + 1, start, mid, left, right, x) +
               query(2 * node + 2, mid + 1, end, left, right, x);
    }

    void build(vector<ll>& v) {
        build(v, 0, 0, n - 1);
    }

    ll query(ll i, ll j, ll k) {
        return query(0, 0, n - 1, i, j, k);
    }
};

int main(){
    fastio();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt","w",stdout);
    #endif
    //TIN{
        //cout<<"Case #"<<i+1<<":";
        ll n;
        cin >> n;
        vector<ll> v(n);
        read(v,n);
        SegmentTree segTree(n);
        segTree.build(v);
        ll q;
        cin >> q;
        while (q--) {
            ll i, j, k;
            cin >> i >> j >> k;
            i--; j--; 
            cout << segTree.query(i, j, k) << endl;
        }
    //}
    #ifndef ONLINE_JUDGE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
}
