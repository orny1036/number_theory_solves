#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+10;

int etf[N];
int depth[N];
int pf[20][N];

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    etf[1] = 1;

    for(int i = 2; i<N; ++i)
    {
        etf[i] = i;
    }

    for(int i = 2; i<N; ++i)
    {
        if(etf[i] == i)
        {
            for(int j = i; j<N; j+=i)
            {
                etf[j]-=etf[j] / i;
            }
        }
    }

    depth[1] = 0;

    for(int i = 2; i<N; ++i)
    {
        depth[i] = depth[etf[i]] + 1;
    }

    for(int i = 1 ; i<N; ++i)
    {
        int d = depth[i];

        if(d < 20)
        {
            pf[d][i]++;
        }

        for(int k = 0; k<20; ++k)
        {
            pf[k][i]+=pf[k][i-1];
        }
    }

    int t;
    cin >> t;
    while(t--){
        int m, n, k;
        cin >> m >> n >> k;

        cout << pf[k][n] - pf[k][m-1] << endl;
    }
    return 0;
}
