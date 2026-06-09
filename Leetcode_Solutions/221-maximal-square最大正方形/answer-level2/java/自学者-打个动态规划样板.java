### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int maximalSquare(char[][] matrix) {
         int rows = matrix.length;
        int cols = rows > 0 ? matrix[0].length : 0;
        int[][] dp = new int[rows + 1][cols + 1];
        int maxSquarelen = 0;
        for (int row = 1; row <= rows; row++) {
            for (int col = 1; col <= cols; col++) {
                if (matrix[row-1][col-1] == '1'){
                    dp[row][col] = Math.min(Math.min(dp[row][col - 1], dp[row - 1][col]), dp[row - 1][col - 1]) + 1;
                    maxSquarelen = Math.max(maxSquarelen, dp[row][col]);
                }
            }
        }
        return maxSquarelen * maxSquarelen; 
    }
}
```