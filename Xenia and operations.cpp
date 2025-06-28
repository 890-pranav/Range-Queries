#include<bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC optimization ("unroll-loops")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define MOD1 998244353
#define INF 1e18
#define endl "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define read(v,n) for(int i=0;i<n;i++)cin>>v[i]
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define FORV(i,a) for(auto i=a.begin();i!=a.end();i++)
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define FORE(i,a,b) for(ll i=a;i<=b;i++)
#define FORSQ(i,a,b) for(ll i=a;i*i<=b;i++)
#define TIN ll t=0;cin>>t;FOR(i,0,t)
#define int long long int

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;


int __gcd(int a, int b) {
    while(a > 0 && b > 0) {
        if(a > b) {
            a = a % b;
        }
        else {
            b = b % a;
        }
    }
    if(a == 0) {
        return b;
    }
    return a;
}

ll expo(ll a, ll b, ll m) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % m; a = (a * a) % m; b = b >> 1;} return res;}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll max(ll a,ll b){ if(a>b) return a; else return b;}
ll min(ll a,ll b){if(a<b) return a; else return b;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
ll mul(ll a , ll b , ll m){ ll res = (a%m*b%m)%m; if(res<0) {res+=m;} return res;}
ll mod_power(ll a , ll b , ll m){ ll res = 1; while (b > 0) { if (b & 1) {res = mul(res,a,m);} a = mul(a , a , m); b >>= 1;} return res%m; }
ll ceil(ll a,ll b){ if(a%b==0) {return a/b;} else {return a/b +1;} }
ll power(ll a,ll b) { ll res=1; while(b>0) { if(b&1) { res=mod_mul(res,a,mod); b--; } else { a=mod_mul(a,a,mod); b/=2; } } return res; }
ll isprime(ll n) { ll flag=1; for ( ll i = 2; i <= sqrt(n); i++) { if (n % i == 0) { flag = 0; break; } } if (n <= 1) { flag = 0; } return flag; }
ll sumofdigits(ll a) { ll S=0; while(a>0) { ll t=a%10; S+=t; a/=10; } return S; }
ll gcd(ll a,ll b) { return __gcd(a,b); }
ll lcm(ll a,ll b){ return (a*b)/(__gcd(a,b));}
ll highestpower(ll n) { ll temp=1; for(ll i=1;1;i++) { temp=1<<i; if(temp>n) { return temp>>1; } } } // highest power of 2 <=n
ll isperfectsquare(ll x) { ll y=sqrt(x); return y*y==x; }
ll fact(ll n) { ll res = 1; for (ll i = 2; i <= n; i++) { res = ((res%mod) * (i%mod))%mod; } return res%mod; }
ll nCr(ll n, ll r) { return (fact(n)%mod) / (((fact(r)%mod) * (fact(n - r)%mod))%mod); }
ll countDigit(ll n) { ll count = 0; while (n != 0) { n = n / 10; ++count; } return count; }
ll ispalindrom(string s) { ll t=0; ll l=sz(s); FOR(i,0,l) { if(s[i]!=s[l-i-1]) t=1; } if(t) { return 0; } return 1; }
ll reversdigits(ll num) { ll rev_num = 0; while (num > 0) { rev_num = rev_num * 10 + num % 10; num = num / 10; } return rev_num; }


struct segtree {
    int n;
    int height;
    vector<ll> st;
    void init(ll _n,ll _height) {
        n = _n;
        height = _height;
        st.resize(4*n);
    }

    void build(int start,int end,int node,const vector<int>& v,int level) {
        if (start==end) {
            st[node] = v[start];
            return;
        }
        int mid = (start+end)/2;
        build(start,mid,node*2+1,v,level+1);
        build(mid+1,end,node*2+2,v,level+1);
        if ((height-level)%2==1) {
            st[node]=st[2*node+1]|st[2*node+2];
        }
        else {
            st[node]=st[2*node+1]^st[2*node+2];
        }
    }

    void update(int index,int value,int start,int end,int node,int level) {
        if (start==end) {
            st[node] = value;
            return;
        }
        int mid = (start+end)/2;
        if (index>mid) {
            update(index,value,mid+1,end,node*2+2,level+1);
        }
        else {
            update(index,value,start,mid,node*2+1,level+1);
        }
        if ((height-level)%2==1) {
            st[node] = st[2*node+1]|st[2*node+2];
        }
        else {
            st[node] = st[2*node+1]^st[2*node+2];
        }
    }

    void build(const vector<ll>& v) {
        return build(0,n-1,0,v,0);
    }

    void update(int p,int b) {
        return update(p-1,b,0,n-1,0,0);
    }

    int getTop() {
        return st[0];
    }

};


void solve()
{
    ll n,m;
    cin>>n>>m;
    ll temp=(1LL<<n);
    vector<ll> v(temp);
    for (int i=0;i<temp;i++) {
        cin>>v[i];
    }
    segtree st;
    st.init(temp,n);
    st.build(v);
    for (int i=0;i<m;i++) {
        ll a,b;
        cin>>a>>b;
        st.update(a,b);
        cout<<st.getTop()<<endl;
    }
}


#undef int
int main() {
    fastio();
    #ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
    #endif
    ll t=1;
    //cin>>t;
    for (int i=1;i<=t;i++) {
        //cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}
