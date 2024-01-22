#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+3;
const int inf = 1e18;
vector<vector<pair<int,int>>> adj(N, vector<pair<int,int>>());
vector<int> dist(N, inf);
 
void dijkstra() {
	dist[1] = 0;
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	pq.push({0, 1});
	while(!pq.empty()) {
		int d = pq.top().first; 
		int u = pq.top().second; 
		pq.pop();
		if(dist[u] < d)
			continue;
		for(auto e : adj[u]) {
			int v = e.second; 
			int c = e.first; 
			if(dist[v] <= c+d) 
				continue;
			else {
				dist[v] = c+d;
				pq.push({dist[v], v});
			}
		}
	}
}
 
int32_t main() {
	int n, m;
	cin >> n >> m;
 
	for(int i = 1; i <= m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		adj[a].push_back({w, b});
	}
	dijkstra();
	for(int i = 1; i <= n; i++) {
		cout << dist[i] << " ";
	}
        return 0;
}
