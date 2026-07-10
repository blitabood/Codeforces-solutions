#include <bits/stdc++.h>

using namespace std;

vector<int> graph[100001];
bool used[100001];
vector<int> path;

int v;

bool dfs(int u) {
    used[u] = true;
    path.push_back(u);

    if (u == v) {
        return true;
    }

    for (int i = 0; i < graph[u].size(); i++) {
        int to = graph[u][i];

        if (!used[to]) {
            if (dfs(to)) {
                return true;
            }
        }
    }

    path.pop_back();
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, u;
    cin >> n >> m >> u >> v;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    if (dfs(u)) {
        for (int i = 0; i < path.size(); i++) {
            cout << path[i] << " ";
        }
    } else {
        cout << -1;
    }

    return 0;
}
