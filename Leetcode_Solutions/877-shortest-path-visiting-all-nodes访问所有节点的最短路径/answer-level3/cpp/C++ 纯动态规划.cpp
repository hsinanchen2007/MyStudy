**思路：**
1，先求出任意图子集中的两两点之间的最短距离，用`p`为二进制表示的图子集，`dist[p][i][j]`来表示图子集`p`中`i`到`j`的最短距离
2，后求出任意图子集中遍历所有点的最短路径，`dp[p][i]`表示图子集p中以点i为路径终点的最短路径
以上两部分都可以用动态规划来解决
代码如下：
```
class Solution {
public:
    const int INF = 1e8;
    int shortestPathLength(vector<vector<int>>& graph) {
        int N = graph.size();
        int S = 1 << N;
        vector<vector<vector<int> > > dist(S, vector<vector<int> >(N, vector<int>(N, INF)));
        for (int i = 0; i < N; ++i) {
            dist[1 << i][i][i] = 0;
            for (auto j : graph[i]) {
                dist[(1 << i) | (1 << j)][i][j] = 1;
                dist[(1 << i) | (1 << j)][j][i] = 1;
            }
        }
        for (int p = 1; p < S; ++p) {
            for (int i = 0; i < N; ++i) {
                dist[p][i][i] = 0;
                if ((p & (1 << i)) == 0) continue;
                for (int j = 0; j < N; ++j) {
                    if (j == i || (p & (1 << j)) == 0) continue;
                    if (dist[(1 << i) | (1 << j)][i][j] == 1) {
                        dist[p][i][j] = dist[p][j][i] = 1;
                    } else {
                        for (int k = 0; k < N; ++k) {
                            if (k == i || k == j || (p & (1 << k)) == 0) continue;
                            dist[p][i][j] = min(dist[p][i][j], 
                                    dist[p - (1 << i)][k][j] + dist[p - (1 << j)][k][i]);
                        }
                    }
                }
            }
        }
        vector<vector<int> > dp(S, vector<int>(N, INF));
        for (int i = 0; i < N; ++i) {
            dp[1 << i][i] = 0;
        }
        for (int p = 1; p < S; ++p) {
            for (int i = 0; i < N; ++i) {
                if ((p & (1 << i)) == 0) continue;
                for (int j = 0; j < N; ++j) {
                    if (j == i || (p & (1 << j)) == 0) continue;
                    dp[p][i] = min(dp[p][i], dp[p - (1 << i)][j] + dist[p][j][i]);
                }
            }
            for (int i = 0; i < N; ++i) {
                if (p & (1 << i) == 0) continue;
                for (int j = 0; j < N; ++j) {
                    if (j == i || (p & (1 << j)) == 0) continue;
                    dp[p][i] = min(dp[p][i], dp[p][j] + dist[p][j][i]);
                }
            }
        }
        int res = INF;
        for (int i = 0; i < N; ++i) {
            res = min(res, dp[S - 1][i]);
        }
        return (res == INF) ? -1 : res;
    }
};
```
不过运行的真慢啊
![image.png](https://pic.leetcode-cn.com/00d2c300618ad025797ad8335d198d54f0e7d5dbd1dbde2c722be741dadd8a00-image.png)
