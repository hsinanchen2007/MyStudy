SPFA 和普通的 BFS 差不多，用队列保存待遍历结点。要注意的是，vis数组并非让每个点只遍历一次，每个点可能遍历的次数是不确定的，vis只是避免有重边反复把相同结点入队。这里我们删掉 vis[110] 数组也是可以 AC 的。
```c++
class Solution {
private:
    unordered_map<int, vector<pair<int, int>>> graph;
    int vis[110];
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        int dis[N + 1];
        int inf = 0x3f3f3f3f >> 1;
        memset(dis, 0x3f, sizeof dis);
        dis[K] = 0;
        for (auto t : times) graph[t[0]].push_back({t[1], t[2]});
        queue<int> q;
        q.push(K);
        vis[0] = 1;
        while (!q.empty())
        {
            auto t = q.front(); q.pop();
            vis[t] = 0;
            for (auto p : graph[t])
            {
                int e = p.first, w = p.second;
                if (dis[e] > dis[t] + w)
                {
                    dis[e] = dis[t] + w;
                    if (!vis[e])
                    {
                        vis[e] = 1;
                        q.push(e);
                    }
                }
            }
        }
        int res = INT_MIN;
        for (int i = 1; i <= N; i ++)
        {
            if (dis[i] >= inf) return -1;
            res = max(res, dis[i]);
        }
        return res;
    }
};
```