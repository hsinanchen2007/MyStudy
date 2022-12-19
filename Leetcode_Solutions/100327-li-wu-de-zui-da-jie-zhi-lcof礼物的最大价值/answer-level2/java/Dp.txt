### 解题思路
由于第一行和第一列的最大值是固定的，首先对第一行第一列最大值进行求取。
在原数组上进行修改既可。
### 代码

```java
class Solution {
    public int maxValue(int[][] grid) {
        int rowLen = grid.length;
        int colLen = grid[0].length;
        if(rowLen == 0 && colLen == 0) return 0;
        //动态规划
        //先对第一行第一列进行最大价值赋予
        for(int i = 1;i < colLen;i++){
            grid[0][i] += grid[0][i-1];
        }
        for(int i = 1;i < rowLen;i++){
            grid[i][0] += grid[i-1][0];
        }
        for(int i = 1;i < rowLen;i++){
            for(int j = 1;j < colLen;j++)
                grid[i][j] += Math.max(grid[i-1][j],grid[i][j-1]);
        }
        return grid[rowLen-1][colLen-1];
    }
}
```