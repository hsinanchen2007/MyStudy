### 解题思路
DFS,记忆化的缓存

### 代码

```cpp
class Solution {
public:
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int m, n;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) return 0;
        m = matrix.size(); n = matrix[0].size();
        vector<vector<int>> cache(m,vector<int>(n,0));
        int ans = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                ans = max(ans, dfs(matrix, i, j, cache));
        return ans;
    }

    int dfs(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& cache) {
        if (cache[i][j] != 0) return cache[i][j];
        for (int k=0;k<4;k++) {
            int x = i + dirs[k][0], y = j + dirs[k][1];
            if (0 <= x && x < m && 0 <= y && y < n && matrix[x][y] > matrix[i][j])
                cache[i][j] = max(cache[i][j], dfs(matrix, x, y, cache));
        }
        return ++cache[i][j];
    }
};
```