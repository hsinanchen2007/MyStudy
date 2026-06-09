### 解题思路
此处撰写解题思路
使用二维(i,j)坐标搜索会超时，这里需要使用三维(i,j,k)来进行剪枝，也就是在坐标(i,j)剩余障碍物为0-k的状态，每一个状态走一次即可
其他剪枝点：
1.判断障碍物数量k的值是否小于0
2.最终答案ans与当前走的步数cnt的大小

### 代码

```cpp
class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<bool>>> mp;
        for (int i = 0; i < n; ++i) {
            vector<vector<bool>> v;
            for (int j = 0; j < m; ++j) {
                vector<bool> vv;
                for (int z = 0; z <= k; ++z) vv.push_back(false);
                v.push_back(vv);
            }
            mp.push_back(v);
        }
        int ans = 88888;
        dfs(grid, n, m, ans, 0, 0, 0, k, mp);
        return ans == 88888 ? -1 : ans;
    }

    void dfs(vector<vector<int>>& g, int& n, int& m, int& ans, int i, int j, int cnt, int k, vector<vector<vector<bool>>>& mp) {
        if (k < 0) return;
        if (cnt >= ans) return;
        if (i == n - 1 && j == m - 1) {
            ans = cnt;
            return;
        }
        mp[i][j][k] = true;
        // right
        if (j + 1 < m && !mp[i][j + 1][k]) dfs(g, n, m, ans, i, j + 1, cnt + 1, k - g[i][j + 1], mp);
        // down
        if (i + 1 < n && !mp[i + 1][j][k]) dfs(g, n, m, ans, i + 1, j, cnt + 1, k - g[i + 1][j], mp);
        // left
        if (j - 1 >= 0 && !mp[i][j - 1][k]) dfs(g, n, m, ans, i, j - 1, cnt + 1, k - g[i][j - 1], mp);
        // up
        if (i - 1 >= 0 && !mp[i - 1][j][k]) dfs(g, n, m, ans, i - 1, j, cnt + 1, k - g[i - 1][j], mp);
    }
};
```