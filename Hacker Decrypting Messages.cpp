#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int hp[N];
long long doesExists[N];
vector<bool>is_prime(N, true);

void mark_prime()
{
    is_prime[0] = is_prime[1] = false;

    for(int i = 2; i<N; ++i)
    {
        if(is_prime[i])
        {
            hp[i] = i;
            for(int j = i*2; j<N; j+=i)
            {
               hp[j] = i;
               is_prime[j] = false;
            }
        }
    }
}
vector<int> prime_factors(int x)
{
      vector<int>pfs;
       while(x>1)
       {
           int pf = hp[x];
           pfs.push_back(pf);
           while(x % pf == 0){
               x/=pf;
           }
       }
       return pfs;
}
int main()
{
    int n, q;
    cin >> n >> q;
    mark_prime();
    for(int i = 0; i<n; ++i)
    {
        int val;
        cin >> val;
        doesExists[val] = 1;
    }
    doesExists[1] = 1;
    for(int i = 2; i<N; ++i)
    {
        if(doesExists[i])
        {
            for(long long j = i; j<N; j*=i)
        {
            doesExists[j] = 1;
        }
        }
    }
    while(q--)
    {
        int x;
        cin >> x;
        vector<int>pfs = prime_factors(x);

        bool isPossible = false;

        for(int i = 0; i<pfs.size(); ++i)
        {
            for(int j = i; j<pfs.size(); ++j)
            {
                int product = pfs[i]*pfs[j];

                if(i == j && x % product != 0)
                    continue;
                int rem = x / product;
                if(doesExists[rem] == 1)
                {
                isPossible = true;
                break;
                }

            }
            if(isPossible)
                break;
        }
        if(isPossible)cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
