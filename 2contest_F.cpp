#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n, a;
    long long maxx = 0;
    long long max2 = 0;
    long long M = 1000000007;

    if (cin >> n >> a) {
        for (int i = 1; i <= n; ++i) {
            a = a * 5;
            
            if (a >= 2 * M) a -= 2 * M;
            if (a >= 2 * M) a -= 2 * M;
            if (a >= M)     a -= M;
            
            if (a > maxx) {
                max2 = maxx;
                maxx = a;
            } 
            else if (a > max2) {
                max2 = a;
            }
        }
        cout << max2 << " " << maxx << "\n";
    }
    return 0;
}