floyd 逻辑最简单：   

    使用邻接矩阵g保持最短距离，g[f][t] 表示 从 f -> t 的最短时延，一开始只有初始化数据，需要不断迭代更新。
    更新过程：遍历所有节点K， 看 从任意节点f到t的直达时延是否超过 f -> K -> t时延之和，如果是，则更近时延数据。
    最终从邻接矩阵g的K列中获取各最短时延的最大值即为结果（如果有结果为MAX_W，则表明某节点不可达， 返回 -1)


Dijkstra逻辑相对复杂：

    使用dis数组表示从K到各节点的时延，一开始只有初始化的信息。需要后面依次更新最短时延。
    使用mark数组将节点标记为两个集合（mark[i] 表示从K到i节点是否已经确认为最短时延。
    每次从未确认的集合（mark[i]=0)选取最小的节点，此节点i为可以确认的最小时延。
    遍历从i出发到各target，判断 K -> i -> target的时延是否要比 K -> target的时延短，是则更新。

    最终从dis数组中获取各最短时延的最大值即为结果（如果有结果为MAX_W，则表明某节点不可达， 返回 -1)

floyd 代码：
```cpp

#define MAX_N   100
#define MAX_W   (MAX_N * 100 + 1)

class Solution {
public:
    int networkDelayTime(vector<vector<int>> &times, int N, int K)
    {
        return Floyd_GetTime(times, N, K);
    }
    
    int Floyd_GetTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<int>> g(N+1, vector<int>(N+1, MAX_W));
        // 初始化 图 NxN，直接用矩阵表示，所有值都为最大值， 自身到自身为 0
        Floyd_Init(g, times, N);
        return Floyd_Result(g, N, K);
    }

    void Floyd_Init(vector<vector<int>> &g, vector<vector<int>>& times, int N) {
        for (auto i = 0; i < g.size(); i++) { g[i][i] = 0; }
        for (auto e: times) { g[e[0]][e[1]] = e[2]; } // [u -> v] = weight
        for (int k = 1; k <= N; k++) {  // all middle node K
            for (int f = 1; f <= N; f++) {
                for (int t = 1; t <= N; t++) {
                    if (g[f][t] > g[f][k] + g[k][t]) {
                        g[f][t] = g[f][k] + g[k][t]; // check [f ->t] > [f -> k -> t] 
                    }
                }
            }
        }
    }

    int Floyd_Result(vector<vector<int>> &g, int N, int K) {
        int maxTime = 0;
        for (int i = 1; i <= N; i++) {
            if (g[K][i] >= MAX_W) { return -1; }
            if (maxTime < g[K][i]) { maxTime = g[K][i]; }
        }
        return maxTime;
    }
};
```
Dijkstra相对麻烦一些：

```cpp
#define MAX_N   100
#define MAX_W   (MAX_N * 100 + 1)

static inline
int GetUnmarkMin(vector<int> &dis, vector<int> &mark, int N)
{
    int min = MAX_W, index = -1;
    for (int i = 1; i <= N; i++) {
        if (mark[i] != 0) { continue; }
        if (min > dis[i]) {
            min = dis[i];
            index = i;
        }
    }
    return index;
}

class Solution {
public:
    int networkDelayTime(vector<vector<int>> &times, int N, int K)
    {
        return Dijkstra_GetTime(times, N, K);
    }

    int Dijkstra_GetTime(vector<vector<int>> &times, int N, int K)
    {
        vector<vector<int>> g(N + 1, vector<int>(N + 1, MAX_W));
        Dijkstra_Init(g, times);
        return Dijkstra_GetResult(g, N, K);
    }

    void Dijkstra_Init(vector<vector<int>> &g, vector<vector<int>> &times)
    {
        for (auto i = 0; i < g.size(); i++) { g[i][i] = 0; } // [i -> i] = 0
        for (auto e: times) { g[e[0]][e[1]] = e[2]; } // [u->v] = w;
    }

    int Dijkstra_GetResult(vector<vector<int>> &g, int N, int K)
    {
        vector<int> dis(g[K]);
        vector<int> mark(N + 1, 0);
        mark[K] = 1;
        for (int loop = 0; loop < N - 1; loop++) {
            int index = GetUnmarkMin(dis, mark, N);
            if (index < 0) { return -1; }
            mark[index] = 1; // it is sure min from K to index
            // check K -> index -> index's outer node.
            for (int t = 1; t <= N; t++) {
                if (mark[index] == 0) { continue; }
                if (g[index][t] >= MAX_W) { continue; }
                if (dis[t] > dis[index] + g[index][t]) {
                    dis[t] = dis[index] + g[index][t];
                }
            }
        }
        return Dijkstra_Result(dis, N);
    }

    int Dijkstra_Result(vector<int> &dis, int N)
    {
        int max = -1;
        for (int i = 1; i<= N; i++) {
            if (dis[i] >= MAX_W) { return -1; }
            if (max < dis[i]) { max = dis[i]; }
        }
        return max;
    }
};
```

附上两个算法的通俗易懂的解释：

算法1： floyd，逻辑最简 参考 http://wiki.jikexueyuan.com/project/easy-learn-algorithm/floyd.html
算法2： Dijkstra，参考 http://wiki.jikexueyuan.com/project/easy-learn-algorithm/dijkstra.html