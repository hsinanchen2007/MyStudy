我觉得这题实际上不止 med 难度了，一个是要懂图的最短路算法，另一个是如何解决两种不同颜色的边的问题, 做起来感觉还挺难的。我个人比较喜欢 SPFA，它是最接近朴素 BFS 的，我看也没人写 SPFA 的题解，我写一个吧。

直接用朴素 BFS 的模板，用 queue 维护，若经过松弛操作则把下一个点入队，直到队空。dis数组要同时保存两种颜色的距离，最后合并即可。


```c++
class Solution {
private:
    unordered_map<int, vector<int>> redGraph, blueGraph;
    queue<pair<int, int>> q;

public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        int inf = 0x3f3f3f3f >> 1;
        int dis[100][2];
        memset(dis, 0x3f, sizeof dis);
        for (auto e : red_edges) redGraph[e[0]].push_back(e[1]);
        for (auto e : blue_edges) blueGraph[e[0]].push_back(e[1]);

        q.push({0, 0});
        q.push({0, 1});
        int dep = 0;
        dis[0][0] = dis[0][1] = 0;
        while (!q.empty())
        {
            int size = q.size();
            dep ++;
            for (int s = 0; s < size; s ++)
            {
                auto t = q.front(); q.pop();
                int color = t.second, e = t.first;
                if (color)
                {
                    for (auto k : blueGraph[e])
                        if (dis[k][1] >= dep)
                        {
                            dis[k][1] = dep;
                            q.push({k, 0});
                        }
                }
                else
                {
                    for (auto k : redGraph[e])
                        if (dis[k][0] >= dep)
                        {
                            dis[k][0] = dep;
                            q.push({k, 1});
                        }
                }
            }
        }

        vector<int> res(n);
        for (int i = 0; i < n; i ++) {
            int t = min(dis[i][0], dis[i][1]);
            if (t >= inf) res[i] = -1;
            else res[i] = t;
        }
        return res;
    }
};
```