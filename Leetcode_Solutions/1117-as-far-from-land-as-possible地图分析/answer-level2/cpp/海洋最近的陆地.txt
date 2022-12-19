### 解题思路
多源最短路径解法太难看了= = 有时间再研究吧
最简单的是动态规划，即令dp[i][j]表示第i,j个格子处如果是海洋的话，最近的陆地的距离
而i,j格的最近陆地受四个方向的影响，所以需要动态规划遍历两次，分别是左右上下，但是具体组合不限
这里是先左上，再右下 

### 代码

```cpp
class Solution {
public:
    static constexpr int MAX_N = 100 + 1;
    static constexpr int INF = int(1E3);

    int f[MAX_N][MAX_N];

    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>& a = grid;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                f[i][j] = (a[i][j] ? 0 : INF);
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (a[i][j]) continue;
                if (i - 1 >= 0) f[i][j] = min(f[i][j], f[i - 1][j] + 1);
                if (j - 1 >= 0) f[i][j] = min(f[i][j], f[i][j - 1] + 1);
            }
        }

        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (a[i][j]) continue;
                if (i + 1 < n) f[i][j] = min(f[i][j], f[i + 1][j] + 1);
                if (j + 1 < n) f[i][j] = min(f[i][j], f[i][j + 1] + 1);
            }
        }

        int ans = -1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!a[i][j]) {
                    ans = max(ans, f[i][j]);
                }
            }
        }

        if (ans == INF) return -1;
        else return ans;
    }
};
```