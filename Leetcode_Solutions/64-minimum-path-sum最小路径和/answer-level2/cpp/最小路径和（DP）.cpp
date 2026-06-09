### 解题思路
- 动态规划题，思路不难
- 关键在于边界的设定，第一行和第一列的每个格子都要累加权值
- 没有另开dp数组，直接在原grid数组上做的，但内存消耗还是有10.6MB.....

### 代码

```cpp
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j > 0){
                    grid[i][j] += grid[i][j - 1];
                }else if(j == 0 && i > 0){
                    grid[i][j] += grid[i - 1][j];
                }else if(i > 0 && j > 0){
                    grid[i][j] = min(grid[i - 1][j], grid[i][j - 1]) + grid[i][j];
                }
            }
        }
        return grid[m - 1][n - 1];
    }
};
```