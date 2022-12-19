### 解题思路
如题，O(mn)

### 代码

```cpp
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        //第一行和第一列只有一种路径，分别为他左边与上边。
        for (int i = 1; i < m; i++)
        {
            grid[i][0] += grid[i-1][0];
        }
        for (int i = 1; i < n; i++)
        {
            grid[0][i] += grid[0][i-1];
        }
        //最短路径为他左边与上边种最小值加上本身值
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                grid[i][j] += grid[i-1][j] < grid[i][j-1] ? grid[i-1][j]:grid[i][j-1];
            }
        }
        return grid[m-1][n-1];
    }
};
```