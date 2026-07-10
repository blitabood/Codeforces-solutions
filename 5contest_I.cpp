#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        long long dx = x2 - x1;
        long long dy = y2 - y1;

        if (dx < 0) dx = -dx;
        if (dy < 0) dy = -dy;

        long long a = dx;
        long long b = dy;

        while (b != 0) {
            long long r = a % b;
            a = b;
            b = r;
        }

        cout << a + 1 << "\n";
    }

    return 0;
}
