## 思路：记忆化搜索
### 代码
时间复杂度：O(row * col)
```c++
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }
        int row = matrix.size(), col = matrix[0].size();
        vector<vector<int>> memo(row, vector<int>(col));
        int res = 1;
        for (int i = 0; i < row;  ++i) {
            for (int j = 0; j < col; ++j) {
                res = max(res, dfs(matrix, i, j, row, col, memo));
            }
        }
        return res;
    }

    int dfs(vector<vector<int>>& matrix, int i, int j, int row, int col, vector<vector<int>>& memo) {
        if (memo[i][j] != 0) {
            return memo[i][j];
        }
        int res = 1;
        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (auto d : dirs) {
            int x = i + d[0], y = j + d[1];
            if (x >= 0 && x < row && y >= 0 && y < col && matrix[x][y] > matrix[i][j]) {
                res = max(res, 1 + dfs(matrix, x, y, row, col, memo));
            }
        }        
        return memo[i][j] = res;
    }  
};
```

