#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> in, out;
vector<bool> vis;
vector<int> path;

void HierholzersAlgorithm(int u)
{
    while (!adj[u].empty())
    {
        int v = adj[u].back();
        adj[u].pop_back();
        HierholzersAlgorithm(v);
    }
    path.push_back(u);
}

bool checkEulerianPath(int n)
{
    int startNodes = 0, endNodes = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (in[i] != out[i])
        {
            if (in[i] - out[i] == 1)
                startNodes++;
            else if (out[i] - in[i] == 1)
                endNodes++;
            else
                return false;
        }
    }
    return (startNodes == endNodes && (startNodes == 0 || startNodes == 1));
}

int main()
{

    ios::sync_with_stdio(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    in.resize(n + 1);
    out.resize(n + 1);
    vis.resize(n + 1, false);

    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        out[a]++;
        in[b]++;
    }

    if (!checkEulerianPath(n))
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    // Find the starting node for the Eulerian path
    int startNode = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (out[i] - in[i] == 1)
        {
            startNode = i;
            break;
        }
    }

    HierholzersAlgorithm(startNode);

    // Print the Eulerian path
    reverse(path.begin(), path.end());
    for (int node : path)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
