### 状态转换方程
```cpp
f(m, n) = grid[0][0], m == 0 && n == 0
f(m, n) = grid[m][n] + f(m-1, n), m > 0 && n == 0
f(m, n) = grid[m][n] + f(m, n-1), m == 0 && n > 0
f(m, n) = grid[m][n] + max(f(m-1, n), f(m, n-1)), m > 0 && n > 0
```

### 递归（递归深度太大的话可能不满足要求）
```cpp
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        return maxValue_helper(grid, grid.size()-1, grid.front().size()-1);        
    }

    int maxValue_helper(vector<vector<int>> &grid, int m, int n) {
        if (m == 0 && n == 0) return grid[0][0];
        if (m == 0) return grid[m][n] + maxValue_helper(grid, m, n-1);
        if (n == 0) return grid[m][n] + maxValue_helper(grid, m-1, n);
        int left = maxValue_helper(grid, m, n-1);
        int up = maxValue_helper(grid, m-1, n);
        return grid[m][n] + max(left, up);
    }
};
```

### 迭代
```
class Solution {
public:
    int maxValue(vector<vector<int>>& grid)
    {
        int row = grid.size();
        int column = grid.front().size();
        vector<int> v(grid.front());
        for (int i = 1; i < column; i++) {
            v[i] += v[i-1];
        }
        for (int i = 1; i < row; i++) {
            v[0] += grid[i][0];
            for (int j = 1; j < column; j++) {
                v[j] = grid[i][j] + max(v[j-1], v[j]); 
            }
        }
        return v.back();
    }
};
```