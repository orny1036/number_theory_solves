#include <bits/stdc++.h>
using namespace std;
 
const int N = 100000000;
 
vector<char> is_prime(N, true);
 
int main() {
 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    is_prime[0] = is_prime[1] = false;
 
    for (int i = 2; i * 1LL * i < N; i++) {
        if (is_prime[i]) {
            for (long long j = 1LL * i * i; j < N; j += i) {
                is_prime[j] = false;
            }
        }
    }
 
    int count = 0;
 
    for (int i = 2; i < N; i++) {
        if (is_prime[i]) {
            count++;
            if (count % 100 == 1)   
                cout << i << "\n";
        }
    }
 
    return 0;
}
 
