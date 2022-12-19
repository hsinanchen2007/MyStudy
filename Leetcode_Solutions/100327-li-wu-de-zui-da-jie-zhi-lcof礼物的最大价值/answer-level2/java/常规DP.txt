### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
public int maxValue(int[][] grid) {
        if (Objects.isNull(grid) || 0 == grid.length)
            return 0;
        
        int rowLen = grid.length;
        int colLen = grid[0].length;
        
        int[][] dp = new int[rowLen][colLen];
        
        for (int i=0; i<rowLen; ++i) {
            for (int j=0; j<colLen; ++j) {
                if (i == 0 && j == 0) {
                    dp[i][j] = grid[i][j];
                }else if (i == 0) {
                    dp[i][j] = dp[i][j-1] + grid[i][j];
                }else if (j == 0) {
                    dp[i][j] = dp[i-1][j] + grid[i][j];
                }else {
                    dp[i][j] = Math.max(dp[i-1][j], dp[i][j-1]) + grid[i][j];
                }
            }
        }
        return dp[rowLen-1][colLen-1];
    }
}
```