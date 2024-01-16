#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define sze 200005

vector<int> depth(sze);
vector<int> adj[sze];
vector<vector<int>> bin(sze, vector<int>(21));
int n;

void dfs(int node, int par)
{

    bin[node][0] = par;

    for (int i = 1; i <= log2(n); i++)
    {
        bin[node][i] = bin[bin[node][i - 1]][i - 1];
    }

    for (auto ele : adj[node])
    {
        if (node != par)
        {
            dfs(ele, node);
        }
    }
}

int lca(int p, int q)
{
    int log = log2(n);
    if (depth[p] < depth[q])
    {
        swap(p, q);
    }

    for (int i = log; i >= 0; i--)
    {
        if (depth[p] - (1 << i) >= depth[q])
        {
            p = bin[p][i];
        }
    }

    if (p == q)
    {
        return p;
    }

    for (int i = log; i >= 0; i--)
    {

        if (bin[p][i] != bin[q][i])
        {
            p = bin[p][i];
            q = bin[q][i];
        }
    }

    return bin[p][0];
}

int main()
{
    int m;
    cin >> n >> m;

    for (int i = 2; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}
