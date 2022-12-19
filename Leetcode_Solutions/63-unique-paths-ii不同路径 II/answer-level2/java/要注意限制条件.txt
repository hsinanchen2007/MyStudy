### 解题思路
要注意限制条件

### 代码

```java
class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int rows = obstacleGrid.length;
        int cols = obstacleGrid[0].length;
        // 障碍物在头在尾
        if (obstacleGrid[0][0] == 1 || obstacleGrid[rows - 1][cols - 1] == 1)
            return 0;
        int[][] memo = new int[rows][cols];
        memo[0][0] = 1;
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (obstacleGrid[row][col] == 1)
                    memo[row][col] = 0;
                else if (row == 0 &&col!=0)
                    memo[row][col] = memo[row][col-1];
                else if(col==0&&row!=0)
                    memo[row][col] = memo[row-1][col];
                else if (row != 0 && col != 0)
                    memo[row][col] = memo[row - 1][col] + memo[row][col - 1];
            }
        }

        return memo[rows - 1][cols - 1];
    }
}
```