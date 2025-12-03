#include <bits/stdc++.h>
using namespace std;

const int N = 90000000;    // Enough to reach 5 million primes
vector<char> is_prime(N, true);
vector<int> primes;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * 1LL * i < N; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j < N; j += i)
                is_prime[j] = false;
        }
    }

    primes.reserve(5000000);
    for (int i = 2; i < N && primes.size() < 5000000; i++) {
        if (is_prime[i])
            primes.push_back(i);
    }

    int q;
    cin >> q;
    while (q--) {
        int k;
        cin >> k;
        cout << primes[k - 1] << "\n";  // zero indexed
    }
}
