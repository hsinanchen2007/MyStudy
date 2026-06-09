### 解题思路
需要注意的一点是不要连成环了，相同root的边不能连接。

### 代码

```cpp
class DisjointSet {
private:
    vector<int> par;
    vector<int> rank;
public:
    DisjointSet(int n) {
        par.resize(n+1);
        rank.resize(n+1);
        for(int i=1; i<=n; i++) {
            par[i] = i;
        }
    }

    bool Union(int x, int y) {
        int ux = Find(x);
        int uy = Find(y);
        if(ux == uy)
            return false;
        // cout << ux << "," << uy << endl;
        if(rank[ux] < rank[uy]) {
            par[ux] = uy;
        } else {
            par[uy] = ux;
            if(rank[ux] == rank[uy])
                rank[uy]++;
        }
        return true;
    }

    int Find(int x) {
        return par[x] == x ? x : par[x] = Find(par[x]);
    }
};

struct Edge {
    int start;
    int end;
    int cost;
    Edge(int s, int e, int c): start(s), end(e), cost(c) {}
};

struct comp {
    bool operator()(const Edge& lhs, const Edge& rhs) {
        return lhs.cost > rhs.cost;
    }
};

class Solution {
public:
    int minimumCost(int N, vector<vector<int>>& connections) {
        DisjointSet ds(N);
        int e = N;
        long long sum = 0LL;
        priority_queue<Edge, vector<Edge>, comp> edges;
        for(auto c: connections) {
            edges.push(Edge(c[0], c[1], c[2]));
        }
        for(int i=0; i<connections.size(); i++) {
            Edge edge = edges.top();
            edges.pop();
            bool connect = ds.Union(edge.start, edge.end);
            if(connect) {
                sum += edge.cost;
                e--;
            }
            if(e == 1)
                break;
        }
        return e == 1 ? sum : -1;
    }
};
```