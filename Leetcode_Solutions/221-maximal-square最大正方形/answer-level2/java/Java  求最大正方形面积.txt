### 解题思路
解题思路：动态规划。
选择一个例子找规律：
1. 首先需要创建一个rows+1，cols+1的二维数组，存储最终的结果。
2. 之所以rows和cols要加1，是因为为了方便计算第一行和第一列元素的情况的时候不需要特殊考虑！！！
3. 当处理的数组元素为1时，才需要考虑周围三个点的最大正方形边长，否则忽略。
4. 注意数组元素和dp数组下标之间的差异（行列均差1）。

### 代码

```java
class Solution {
    public int maximalSquare(char[][] matrix) {
        if (matrix == null || matrix.length == 0) {
            return 0;
        }
        
        int maxLength = 0;
        int rows = matrix.length, cols = matrix[0].length;
        int[][] dp = new int[rows + 1][cols + 1];
        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= cols; j++) {
                if (matrix[i - 1][j - 1] != '1') {
                    continue;
                } // 当前元素不是1，则不需要考虑最大正方形边长
                
                // 当前元素为1，才需要考虑周围三个点的当前最大正方形边长
                // 它们中的最小值加1即当前点的最大正方形边长
                int val = Math.min(dp[i - 1][j], dp[i - 1][j - 1]);
                dp[i][j] = Math.min(val, dp[i][j - 1]) + 1;
                maxLength = Math.max(maxLength, dp[i][j]);
            }
        }
        
        return maxLength * maxLength;
    }
}
```