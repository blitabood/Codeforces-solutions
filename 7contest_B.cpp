#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, long long>>> adj(n + 1);

    for(int i = 0; i < m; i++){
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
    }

    long long INF = 1000000000000;

    vector<long long> dist(n + 1, INF);
    vector<int> parent(n + 1, -1);
    dist[1] = 0;

    priority_queue<pair<long long, int>> pq;
    pq.push(make_pair(0, 1));

    while(!pq.empty()){
        long long d = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if(d > dist[cur]){
            continue;
        }

        for(int i = 0; i < adj[cur].size(); i++){
            int next = adj[cur][i].first;
            long long weight = adj[cur][i].second;
            if(dist[cur] + weight < dist[next]){
                dist[next] = dist[cur] + weight;
                parent[next] = cur;
                pq.push(make_pair(-dist[next], next));
            }
        }
    }

    if(dist[n] == INF){
        cout << -1;
    } else {
        vector<int> path;
        int cur = n;
        while(cur != -1){
            path.push_back(cur);
            cur = parent[cur];
        }

        for(int i = path.size() - 1; i >= 0; i--){
            cout << path[i] << " ";
        }
    }

    
    return 0;
}
