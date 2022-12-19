思路很清晰，既然要求到达右下角的最小路径和，那么可依次求出每个点的最小路径和，用原来的数组保存。
先初始化第一行，下标从1开始，第一行的每个点只能从左边进入，所以每个点的最小路径 = 左一个点的最小路径 + 当前点的值；
在初始化第一列，下标从1开始，第一列的每个点只能从上边进入，所以每个点的最小路径 = 上一个点的最小路径 + 当前点的值；
最后从下标[1][1]开始，逐行赋值，每个点的最小路径 = 左上两点最小路径的更小值 + 当前点的值；
代码如下：
```
public static int minPathSum(int[][] grid) {
        
        int m = grid.length;
        int n = grid[0].length;
        for (int i = 1; i < n; i++) {
            grid[0][i] += grid[0][i - 1];
        }
        for (int i = 1; i < m; i++) {
            grid[i][0] += grid[i - 1][0];
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                grid[i][j] += Math.min(grid[i][j - 1],grid[i - 1][j]);
            }
        }
        return grid[m - 1][n - 1];
}
```

