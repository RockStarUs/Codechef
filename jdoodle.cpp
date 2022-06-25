#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd (ll a, ll b) {
    if (b == 0) {
        return a;
    }
    return gcd (b, a % b);
}

ll lcm (ll a, ll b) {
    return (a * b)/gcd(a, b);
}

ll getActualAnswer(ll n) {
    ll cnt = 0;
    for (ll i = 1; i * i <= n ; i += 1) {
        for (ll j = 1; j * j <= n; j += 1) {
            if ((i * i + j * j + gcd(i, j) * gcd(i, j) + lcm (i, j) * lcm (i, j)) == n) {
                cnt += 1;
                //cout << "(" << i << ", " << j << ")\n";
            }
        }
    }
    return cnt;
}


bool isSquare(ll n) {
    ll h = sqrt(n);
    return (h * h == n);
}

set<ll> getFactorsSet(ll n) {
    set<ll> factorsList;
    for (ll i = 1; i * i <= n; i += 1) {
        if (n % i == 0) {
            if (isSquare(i)) {
                factorsList.insert(i);
            }
            if (isSquare(n / i)) {
                factorsList.insert(n / i);
            }
        }
    }
    return factorsList;
}

ll getExpectedAnswer(ll n) {
    ll cnt = 0;
    set<ll> factorsSet = getFactorsSet(n);
    bool flag = 0;
    for (auto g: factorsSet) {
        //cout << g << "\n";
        ll k = n / g;
        for (ll a = 1; a * a <= n; a += 1) {
            if ((a * a) % g == 0 && k % ((a * a) / (g) + 1) == 0) {
                ll h = (k / ((a * a) / g + 1) - 1);
                
                if (isSquare(h)) {
                    
                    ll b = sqrt(h) * sqrt(g);
                    
                    //cout << a << " " << b << " " << g << " " << k << "\n";
                    
                    if (gcd (a * a, b * b) == g) {
                        if(a == b) {
                            flag = 1;
                        }
                        cnt += 1;
                    }
                }
            }
            
        }
    }
    
    
    return cnt;
}


int main() {
    
    int t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        
        
        //ll a = getActualAnswer(n);
        ll e = getExpectedAnswer(n);
        
        cout << ", " << e << "\n";
        
    }
    
    return 0;
}