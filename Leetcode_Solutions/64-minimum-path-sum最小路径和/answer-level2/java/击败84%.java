### 解题思路
在原来的二维数组上直接修改，不需重新建一个二维数组

### 代码

```java
class Solution {
    public int minPathSum(int[][] grid) {
        if(grid == null || grid.length == 0)
            return 0;
        int rows = grid.length;
        int cols = grid[0].length;
        if(rows == 1){
            int res = 0;
            for(int i = 0; i < cols; i ++){
                res += grid[0][i];
            }
            return res;
        }
        if(cols == 1){
            int res = 0;
            for(int i = 0; i < rows; i ++){
                res += grid[i][0];
            }
            return res;
        }
        //先处理最后一行和最后一列
        for(int i = rows - 1; i >= 1; i--){
            grid[i - 1][cols - 1] += grid[i][cols - 1];
        }
        for(int j = cols - 1; j >= 1; j--){
            grid[rows - 1][j - 1] += grid[rows - 1][j];
        }
        rows --;
        cols --;
        while(rows > 1 && cols > 1){
            grid[rows - 1][cols - 1] += Math.min(grid[rows][cols - 1],grid[rows - 1][cols]);
            for(int i = rows - 1; i >= 1; i--){
                grid[i - 1][cols - 1] += Math.min(grid[i][cols - 1], grid[i - 1][cols]);
            }
            for(int j = cols - 1; j >= 1; j--){
                grid[rows - 1][j - 1] += Math.min(grid[rows - 1][j], grid[rows][j - 1]);
            }
            rows --;
            cols --;
        }
        if(rows > 1){
            for(int i = rows - 1; i >= 1; i--){
                grid[i][0] += Math.min(grid[i][1], grid[i + 1][0]);
            }
        }
        if(cols > 1){
            for(int i = cols - 1; i >= 1; i--){
                grid[0][i] += Math.min(grid[0][i + 1], grid[1][i]);
            }
        }
        grid[0][0] += Math.min(grid[0][1], grid[1][0]);
        return grid[0][0];
    }
}
```