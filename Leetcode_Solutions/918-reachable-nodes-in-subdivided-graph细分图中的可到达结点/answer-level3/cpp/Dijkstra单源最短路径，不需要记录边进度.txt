官方题解中提到需要在Dijkstra过程中记录边的覆盖进度，但这其实是不必要的。我们完全可以把这两件事情分成两步来做。

1. 由边集表示处理得到邻接表表示（注意初始化边权重的时候要在`n`的基础上再加1，因为距离等于增加的节点数目加1）
2. 使用Dijkstra算法计算从`0`到所有节点的最短距离。
    - 使用C++ STL的`priority_queue`记录需要拓展的节点，注意`priority_queue`默认是大根堆，这里需要将比较函数设置为`greater<>`，从而将其变成小根堆。
    - 使用`vis[N]`数组记录每一节点是否已经被拓展过。一个节点最多只能拓展一次。
3. 利用计算得到的最短距离`dist[N]`，遍历边集`edges`中的边。对其中的任意一条边，我们可以从其左端点`u`覆盖，也可以从其右端点`v`覆盖，最后总的覆盖数目
$$cover=\min(n,\max(0,\min(dist[u]-M, n))+\max(0,\min(dist[v]-M,n)))$$
4. 上一步累加的是新增点的覆盖情况，我们还需要进行一次对`N`个顶点的遍历，来确定原始的`N`个顶点的覆盖情况。

参考代码：
```cpp
class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int M, int N) {
        vector<vector<pair<int, int>>> adj(N);
        for (auto e : edges) {
            adj[e[0]].emplace_back(e[1], e[2] + 1);
            adj[e[1]].emplace_back(e[0], e[2] + 1);
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<int> dist(N, 1e9);
        vector<bool> vis(N);
        dist[0] = 0;
        pq.push(make_pair(0, 0));
        while (!pq.empty()) {
            pair<int, int> top = pq.top();
            pq.pop();
            int u = top.second, d = top.first;
            if (vis[u]) continue;
            vis[u] = true;
            for (auto neighbor : adj[u]) {
                int v = neighbor.first;
                int cost = neighbor.second;
                if (d + cost < dist[v]) {
                    dist[v] = d + cost;
                    pq.push(make_pair(d + cost, v));
                } 
            }
        }
        int ans = 0;
        for (auto e : edges) {
            int left = max(0, min(M - dist[e[0]], e[2]));
            int right = max(0, min(M - dist[e[1]], e[2]));
            ans += min(left + right, e[2]);
        }
        for (int i = 0; i < N; ++i)
            if (dist[i] <= M)
                ans++;
        return ans;
    }
};
```