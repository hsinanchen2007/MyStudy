### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int minPathSum(int[][] grid) {
        int m = grid.length;
        if(m == 0){
            return 0;
        }
        int n = grid[0].length;
        if(n == 0){
            return 0;
        }
        // 记录到网格中每个点的最短路径
        int[][] path = new int[m][n];
        
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                // 左上角的格子
                if(i == 0 && j == 0){
                    path[i][j] = grid[0][0];
                    continue;
                }
                // 第一行的格子只能从左边的格子过来
                if(i == 0){
                    path[i][j] = path[i][j-1] + grid[i][j];
                    continue;
                }
                // 第一列的格子只能从上面的格子过来
                if(j == 0){
                    path[i][j] = path[i-1][j] + grid[i][j];
                    continue;
                }
                // 其他的格子都可以从左面和上面两个方向过来
                else{
                    // 从上面过来
                    int upPath = path[i-1][j] + grid[i][j];
                    // 从左面来
                    int leftPath = path[i][j-1] + grid[i][j];
                    // 选数值更小的
                    path[i][j] = Math.min(upPath, leftPath);
                }
            }           
        }
        return path[m-1][n-1];
    }
}
```