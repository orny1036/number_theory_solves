#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+10;

vector<int> is_prime(N, 1);
vector<int>pfs[N];
int spf[N];

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    is_prime[0] = is_prime[1] = 0;

    for (int i = 2; i < N; i++)
    {
        if (is_prime[i])
        {
            spf[i] = i;
            for (long long j = i*1LL*1; j < N; j += i)
            {
                is_prime[j] = 0;
               if(spf[j] == 0)
                spf[j] = i;
            }
        }
    }

    for(int i = 2; i<N; ++i)
    {
        if(!is_prime[i])
        {
            int temp = i;
            while(temp > 1)
            {
                int pf = spf[temp];
                pfs[i].push_back(pf);
                while(temp % pf == 0)
                {
                    temp/=pf;
                }

            }
        }
    }
    int ETF[N] = {0};
    ETF[1] = 1;
    for(int i = 2; i<N; ++i)
    {
        if(is_prime[i])
        {
            ETF[i] = i-1;
        }
        else
        {
            int etf = i;
            for(int pf : pfs[i])
            {
                etf-= etf/pf;
            }
            ETF[i] = (int)etf;
        }
    }
    int T;
    cin >> T;
    while(T--)
    {
        int x;
        cin >> x;
        cout << ETF[x] << endl;
    }
    return 0;
}
