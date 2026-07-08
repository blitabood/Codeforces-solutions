#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n;
    cin >> n;
    long long zxc[n+1] = {0};
    for (int i = 1; i<=n; ++i){
        cin >> zxc[i];
        zxc[i] += zxc[i - 1];
    }
    
    long long temp = 0;
    long long ans1 = -2;
    long long ans2 = -2;
    
    long long min_val = zxc[0]; 
    long long best_idx = 0;

    for(int r = 1; r <= n; ++r){
        if (zxc[r] - min_val > temp) {
            temp = zxc[r] - min_val;
            ans1 = best_idx;
            ans2 = r;
        }
        if (zxc[r] < min_val) {
            min_val = zxc[r];
            best_idx = r;
        }
    }
    cout << ans1 + 1 << ' ' << ans2 + 1;
    return 0;
}