### 状态转移方程
```cpp
f(0, 0) = grid[0][0]
f(0, n) = f(0, n-1) + grid[0][n]
f(m, 0) = f(m-1, 0) + grid[m][0]
f(m, n) = min(f(m-1, n), f(m, n-1)) + grid[m][n]
```

### 代码

```cpp []
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
    	int m = grid.size();
    	int n = grid.front().size();

    	vector<vector<int>> f(grid);
    	
        for (int i = 1; i < m; i++) {
            f[i][0] += f[i-1][0];
        }
        
        for (int j = 1; j < n; j++) {
            f[0][j] += f[0][j-1];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                f[i][j] += min(f[i-1][j], f[i][j-1]);
            }
        }

    	return f.back().back();
    }
};
```