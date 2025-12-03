#include <bits/stdc++.h>

using namespace std;
const int N = 2e5+10;

int isDivisible[N];
int hsh[N];

int main() {

   int n;
   cin >> n;

   for(int i = 0; i<n; ++i)
   {
       int x;
       cin >> x;
       hsh[x]++;
   }

   for(int i = 1; i<N; ++i)
   {
       for(int j = i; j<N; j+=i)
       {
           isDivisible[i]+=hsh[j];
       }
   }
   
   
   int t;
   cin >> t;

   while(t--)
   {
       int p, q;
       cin >> p >> q;

       long long lcm = (p * 1LL * q) / __gcd(p, q);

       long long ct = isDivisible[p] + isDivisible[q];

       if(lcm < N)
       {
           ct-=isDivisible[lcm];
       }
       cout << ct << endl;
   }
   return 0;
}
