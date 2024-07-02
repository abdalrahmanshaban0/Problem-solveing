/*
Problem Name : Shortest Routes I 
Author: Abdalrahman Shaban
Date: 24/06/2024 16:33:36
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<long long> vi;
typedef pair<ll, ll> pi;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
/*
   order_of_key (k) : Number of items strictly smaller than k .
   find_by_order(k) : K-th element in a set (counting from zero).
*/
#define endl '\n'
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
void vin(vector<ll>& v) {for(auto& i : v) cin >> i;}

const ll MOD = 1000000007;
const ll inf = LONG_LONG_MAX;

ll gcd(ll a, ll b) { return a ? gcd(b % a, a) : b; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll nCr(ll n, ll r) { if (r == 0 || n == r) return 1; return nCr(n - 1, r - 1) * n / r;}

vector<ll> factorization(ll num){
    vector<ll> ret;
    for(ll i = 2; i*i <= num; i++){
        if(num%i == 0) ret.push_back(i);
        while(num % i == 0) num/=i;
    }
    if(num > 1) ret.push_back(num);
    return ret;
}

ll fpower(ll x, ll y, ll M){
    if(y == 0) return 1;
    ll val = fpower(x, y/2, M) % M;
    val = (val*val)%M;
    return (val*(y&1 ? x : 1))%M;
}

ll modInverse(ll A, ll M){
    ll g = gcd(A, M);
    if (g != 1) return -1;
    return fpower(A, M - 2, M);
}

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(NULL), right(NULL) { }
    TreeNode(int v) : val(v), left(NULL), right(NULL) { }
    TreeNode(int v, TreeNode* l, TreeNode* r) : val(v), left(l), right(r) { }
};

void file() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
}

void Fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

//int dx[] = {0, 0, 1,-1, -1,-1, 1, 1};
//int dy[] = {1,-1, 0, 0,  1,-1,-1,-1};

struct edge{
    ll w, to;
    edge(ll nd, ll d) : to(nd), w(d) { }
    bool operator < (const edge& obj) const{
        return(w > obj.w);
    }
};

void solve(){
    int n, m; cin >> n >> m;
    vector<edge> adj[n];
    for(int i = 0; i < m; i++){
        ll a, b, w;
        cin >> a >> b >> w;
        --a, --b;
        adj[a].push_back({b,w});
    }
    priority_queue<edge> pr; 
    vector<ll> dis(n,inf);
    pr.push({0,0});
    dis[0] = 0;
    vector<bool> vis(n);
    while(!pr.empty()){
        edge cur = pr.top(); pr.pop();
        if(vis[cur.to]) continue;
        vis[cur.to] = 1;
        for(int i = 0; i < adj[cur.to].size(); i++){
            edge ne = adj[cur.to][i];
            if(dis[ne.to] > dis[cur.to]+ne.w){
                dis[ne.to] = ne.w = dis[cur.to]+ne.w;
                pr.push(ne);
            }
        }
    }
    for(int i = 0; i < n; i++){
        cout << dis[i] << ' ';
    }
}

int main() {
    Fast();
    file();
    solve(); 
    return 0;
}
