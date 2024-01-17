#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 2e5 + 5;

vector<int> tree[MAXN];
vector<long long> values(MAXN), BIT(MAXN), startIdx(MAXN), endIdx(MAXN);
int timer = 1;

void dfs(int node, int parent) {
    startIdx[node] = timer++;

    for (int child : tree[node]) {
        if (child != parent) {
            dfs(child, node);
        }
    }

    endIdx[node] = timer - 1;
}

void update(int idx, long long delta) {
    while (idx < MAXN) {
        BIT[idx] += delta;
        idx += (idx & -idx);
    }
}

long long query(int idx) {
    long long sum = 0;
    while (idx > 0) {
        sum += BIT[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

int main() {
    int n, q;
    cin >> n >> q;

    // Input values of each node
    for (int i = 1; i <= n; ++i) {
        cin >> values[i];
    }

    // Input edges of the tree
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    // Perform DFS to get start and end indices for each node
    dfs(1, 0);

    // Initialize BIT with the values array
    for (int i = 1; i <= n; ++i) {
        update(startIdx[i], values[i]);
    }

    // Process queries
    while (q--) {
        int type, s;
        cin >> type >> s;

        if (type == 1) {
            // Change the value of node s to x
            long long x;
            cin >> x;
            update(startIdx[s], x - values[s]);
            values[s] = x;
        } else {
            // Calculate the sum of values in the subtree of node s
            cout << query(endIdx[s]) - query(startIdx[s] - 1) << endl;
        }
    }

    return 0;
}
