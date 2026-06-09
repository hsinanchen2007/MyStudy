### 解题思路
开始用常规思想做，一直超出时间限制，查了好久也米查到具体错误在哪，还以为死循环了。因为也没提供第12个测试用例。
然后看了答案才知道不能用暴力算法就这道题，看到是动态规划才意识到正确解法了。
**************************************************************

### 代码

```java
class NumMatrix {
    private int[][] dp;

    public NumMatrix(int[][] matrix) {
        if (matrix.length == 0 || matrix[0].length == 0) 
            return;
        
        dp = new int[matrix.length][matrix[0].length + 1];
        
        for (int r = 0; r < matrix.length; r++) {
            for (int c = 0; c < matrix[0].length; c++) {
                dp[r][c + 1] = dp[r][c] + matrix[r][c];
            }
        }
    }

    public int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (int row = row1; row <= row2; row++) {
            sum += dp[row][col2 + 1] - dp[row][col1];
        }
        return sum;
    }
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
```