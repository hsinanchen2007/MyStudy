### 解题思路
比较标准的动态规划模板之一，取左边和上面更大的那个作为前一步的落脚点

### 代码

```cpp
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        std::ios::sync_with_stdio(false);

        if (grid.size() == 0) {
            return 0;
        }

        for (int i = 1; i < grid.size(); ++i) {
            grid[i][0] += grid[i - 1][0];
        }

        for (int j = 1; j < grid[0].size(); ++j) {
            grid[0][j] += grid[0][j - 1];
        }

        for (int i = 1; i < grid.size(); ++i) {
            for (int j = 1; j < grid[i].size(); ++j) {
                grid[i][j] += max(grid[i- 1][j], grid[i][j -1]);
            }
        }

        return grid[grid.size() - 1][grid[0].size() - 1];
    }
};
```