## 思路一：暴力递归（超时）
**递归存在问题**
***自顶向下***，要返回[0, 0]的最小值，需要计算[1, 0]和[0, 1]位置最小值，以此类推，可以看出会出现重复计算[1, 1]，不断向下递归过程中，会有大量类似的 **重复计算**。
**解决方法**
在递归过程中保存已经计算过的值，如[1, 1]，这样每次递归先查询是否已经计算过，如果已经计算过，则直接返回。
![image.png](https://pic.leetcode-cn.com/a0f5c6e2bc0b825b1d0281d6c41a1d2f2bbefd400a5d64aec97ce9dd9a2c88dd-image.png)

### 代码
一共遍历 n + m 步，每步有 2 种选择，所以时间复杂度为 2^(n+m)
```c++
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) {
            return 0;
        }
        int row = grid.size(), col = grid[0].size();
        return helper(grid, 0, 0);
    }
    
    int helper(vector<vector<int>>& grid, int row, int col) {
        //到达最右下角
        if (row == grid.size() - 1 && col == grid[0].size() - 1) {
            return grid[row][col];
        }
        //到达最后一行，只能向右走
        if (row == grid.size() - 1) {
            return grid[row][col] + helper(grid, row, col + 1);
        }
        //到达最右一列，只能向下走
        if (col == grid[0].size() - 1) {
            return grid[row][col] + helper(grid, row + 1, col);
        }
        //其它位置
        int n1 = helper(grid, row + 1, col);
        int n2 = helper(grid, row, col + 1);
        return grid[row][col] + min(n1, n2);
    }
};
```

## 思路二：记忆化搜索
设置同原矩阵相同大小的二维map，用于记录每个位置的最小值。
### 代码
因为矩阵中每个位置走一次，所以时间复杂度：O(n*m).
```c++
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) {
            return 0;
        }
        int row = grid.size(), col = grid[0].size();
        //设置map
        vector<vector<int>> map(row, vector<int>(col, -1));
        return helper(grid, 0, 0, map);
    }
    
    int helper(vector<vector<int>>& grid, int row, int col, vector<vector<int>>& map) {
        if (map[row][col] != -1) {
            return map[row][col];
        }
        int ans;
        //到达最右下角
        if (row == grid.size() - 1 && col == grid[0].size() - 1) {
            ans = grid[row][col];
            map[row][col] = ans;
            return ans;
        }
        //到达最后一行，只能向右走
        if (row == grid.size() - 1) {
            ans = grid[row][col] + helper(grid, row, col + 1, map);
            map[row][col] = ans;
            return ans;
        }
        //到达最右一列，只能向下走
        if (col == grid[0].size() - 1) {
            ans = grid[row][col] + helper(grid, row + 1, col, map);
            map[row][col] = ans;
            return ans;
        }
        //其它位置
        int n1 = helper(grid, row + 1, col, map);
        int n2 = helper(grid, row, col + 1, map);
        ans = grid[row][col] + min(n1, n2);
        map[row][col] = ans;            
        return ans;
    }
};
```

## 思路三：动态规划
***自底向上***，根据暴力递归修改为动态规划。
### 代码
```c++
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) {
            return 0;
        }
        int row = grid.size(), col = grid[0].size();
        //设置dp表
        vector<vector<int>> dp(row, vector<int>(col, -1));
        //初始状态
        dp[row-1][col-1] = grid[row-1][col-1];
        //最后一行
        for (int j = col - 2; j >= 0; --j) {
            dp[row-1][j] = grid[row-1][j] + dp[row-1][j+1];
        }
        //最后一列
        for (int i = row - 2; i >= 0; --i) {
            dp[i][col-1] = grid[i][col-1] + dp[i+1][col-1];
        }
        //其它
        for (int i = row - 2; i >= 0; --i) {
            for (int j = col - 2; j >= 0; --j) {
                dp[i][j] = grid[i][j] + min(dp[i+1][j], dp[i][j+1]);
            }
        }        
        return dp[0][0];
    }
};
```

#### 优化空间
从上到下，从左到右。
因为当前dp值只与左边和上面的dp值有关，设置一维dp代替二维dp，初始值为0，当j == 0，即为第一列时，直接加上当前值。
左边dp值表示为dp[i-1]，上面dp值为dp[i]，遍历过程不断更新dp值。
```c++
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) {
            return 0;
        }
        int row = grid.size(), col = grid[0].size();
        //设置dp表
        vector<int> dp(col, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (j == 0) {
                    dp[j] += grid[i][j];
                } else {
                    dp[j] = grid[i][j] + min(dp[j-1], dp[j]);
                }
            }
        }
        return dp[col-1];
            
    }
};
```

#### 进一步优化空间
直接在原数组上加。
```c++
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) {
            return 0;
        }
        int row = grid.size(), col = grid[0].size();        
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (i == 0 && j == 0) {
                    continue;
                }
                //第一行，只能由左边数而来
                if (i == 0) {
                    grid[0][j] += grid[0][j-1];
                }         
                //第一列
                else if (j == 0) {
                    grid[i][0] += grid[i-1][0];
                } else {
                    grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
                }
            }
        }
        return grid[row-1][col-1];            
    }
};
```




