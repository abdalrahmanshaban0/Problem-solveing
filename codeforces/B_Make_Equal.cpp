/*
Problem Name : B. Make Equal 
Author: Abdalrahman Shaban
Date: 13/02/2024 16:38:23
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<long long> vi;
typedef pair<ll, ll> pi;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

#define endl '\n'
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

const ll MOD = 1000000007;
const ll inf = LONG_LONG_MAX;

ll gcd(ll a, ll b) { return a ? gcd(b % a, a) : b; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll nCr(ll n, ll r) { if (r == 0 || n == r) return 1; return nCr(n - 1, r - 1) * n / r;}

void file() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
}

void Fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve(){
    int n; cin >> n;
    ll arr[n];
    ll sm = 0;
    for(int i = 0 ;i< n; i++){
        cin >> arr[i];
        sm += arr[i];
    }
    ll uu = sm / n;
    ll ac = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] > uu){
            ac += arr[i]-uu;
        }
        else if(arr[i] < uu){
            if(arr[i]+ac < uu){
                cout << "NO\n";
                return;
            }
            else{
                ac -= abs(arr[i]-uu);
            }
        }
    }
    YES;
}

int main() {
    Fast();
    file();
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
