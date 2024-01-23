#include <bits/stdc++.h>
using namespace std;

#define SZ 2501
#define INF INT_MAX

vector<vector<pair<int, int>>> adj(SZ);
vector<int> dis(SZ, INF);
int n;

bool cycle = false;
int ans = 0;

void ford()
{

    for (int i = 0; i < n; i++)
    {
        for (int v = 1; v <= n; v++)
        {

            for (auto ele : adj[v])
            {
                int u = ele.first;
                int w = ele.second;
                if (dis[v] != INF && dis[u] > dis[v] + w)
                {
                    dis[u] = dis[v] + w;
                    ans = max(dis[u], ans);
                }
            }
        }
    }

    for (int v = 1; v <= n; v++)
    {

        for (auto ele : adj[v])
        {
            int u = ele.first;
            int w = ele.second;
            if (dis[v] != INF && dis[u] > dis[v] + w)
            {
                cycle = true;
                break;
            }
        }
    }
}

int main()
{

    ios::sync_with_stdio(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b, x;
        cin >> a >> b >> x;

        adj[a].push_back({b, x});
    }

    dis[1] = 0;

    ford();

    if (cycle)
    {
        cout << -1 << endl;
    }

    else
    {
        cout << ans << endl;
    }

    return 0;
}
