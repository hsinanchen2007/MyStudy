### 解题思路
学到的东西：直接在原数据上改可以缩减空间复杂度

### 代码

```cpp
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.at(0).size();

        //初始化第一行和第一列
        for (int i = 1; i < m; i++) {
            grid.at(i).at(0) = grid[i-1][0] + grid.at(i).at(0);
        }
        for (int j = 1; j < n; j++) {
            grid.at(0).at(j) = grid[0][j-1] + grid.at(0).at(j);
        }
        //挨个操作元素
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                grid[i][j] = min(grid[i-1][j], grid[i][j-1]) + grid.at(i).at(j);
            }
        }
        return grid[m-1][n-1];
    }
};
```