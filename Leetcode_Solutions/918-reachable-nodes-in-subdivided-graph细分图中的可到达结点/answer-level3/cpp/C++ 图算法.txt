核心为求最短路径，详见代码注释：
```
class Solution {
public:
    const int INF = 1e8;
    int reachableNodes(vector<vector<int>>& edges, int M, int N) {
        vector<vector<pair<int, int> > > g(N);
        for (auto& e : edges) {
            g[e[0]].push_back({e[1], e[2] + 1});
            g[e[1]].push_back({e[0], e[2] + 1});
        }
        // 记录最短距离
        vector<int> dist(N, INF);
        dist[0] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
        q.push({0, 0});
        // 基于优先队列优化的 dijkstra 最短路径算法
        while (!q.empty()) {
            auto p = q.top();
            q.pop();
            int d = p.first;
            int i = p.second;
            if (d != dist[i]) continue;
            for (auto& t : g[i]) {
                int j = t.first;
                int e = t.second;
                if (dist[j] > dist[i] + e) {
                    dist[j] = dist[i] + e;
                    q.push({dist[j], j});
                }
            }
        }
        int res = 0;
        vector<int> visited(N, 0);
        visited[0] = 1;
        // 记录每个边除去端点之外的点的访问量
        for (auto& e : edges) {
            int i = e[0];
            int j = e[1];
            int d = e[2];
            if (dist[i] <= M) visited[i] = 1;
            if (dist[j] <= M) visited[j] = 1;
            res += min(max(M - dist[i], 0) + max(M - dist[j], 0), d);
        }
        // 加上端点的访问量
        res += accumulate(visited.begin(), visited.end(), 0);
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/ee917d3b22f2309fbd6496c18dff812c463e1c3ee759009826f69b02ca309759-image.png)
