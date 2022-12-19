这题和63题思路相近，都是先处理好第一列和第一行的数据之后，然后逐行进行处理。
逐行处理的时候，该格子的值等于它上面和左边格子的最小值加上自己。

```
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        long R = grid.size();
        long C = grid[0].size();
        
        if (R == 1 && C == 1) {
            return grid[0][0];
        }
        
        for (long i = 1; i<C; i++) {
            grid[0][i] = grid[0][i-1] + grid[0][i];
        }
        for (long i = 1; i<R; i++) {
            grid[i][0] = grid[i-1][0] + grid[i][0];
        }
        
        for (int i=1; i<R; i++) {
            for (int j=1; j<C; j++) {
                grid[i][j] = grid[i][j] + min(grid[i-1][j], grid[i][j-1]);
            }
        }
        
        return grid[R-1][C-1];
    }
};
```
