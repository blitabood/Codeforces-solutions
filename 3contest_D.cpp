#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n, m, k;
    cin >> n >> m >> k;
    
    vector<vector< long long>> dp(n + 1, vector<long long>(m + 1,0));
    vector<vector< bool>> dangerous(n + 1, vector<bool>(m + 1,false));
    for(int i = 0; i < k; ++i){
        long long a,b;
        cin >> a >> b;
        dangerous[a][b] = true;
    }
    dp[0][0] = 1;
    for (int i = 0; i <= n; ++i){
        for (int j = 0; j <= m; ++j){
            if (dangerous[i][j] == false){
                if (i > 0) dp[i][j] += dp[i - 1][j];
                if (j > 0) dp[i][j] += dp[i][j - 1];
                dp[i][j] %= 1000000007;
            }
        }
    }
    cout << dp[n][m] % 1000000007;
    
    return 0;
}
