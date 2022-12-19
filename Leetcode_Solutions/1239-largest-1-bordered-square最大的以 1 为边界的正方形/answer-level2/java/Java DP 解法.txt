### 解题思路

先用预计算来计算row sum和column sum，然后三层for循环，先循环正方形长度，再循环row，再循环column，来找到长度是否合适。

### 代码

```java
class Solution {
    public int largest1BorderedSquare(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        int[][] rowSum = new int[n + 1][m + 1];
        int[][] colSum = new int[m + 1][n + 1];
        for (int i = 1; i <= grid.length; i ++) {
            for (int j = 1; j <= m; j ++) {
                rowSum[i][j] = grid[i - 1][j - 1] + rowSum[i][j - 1];
                colSum[j][i] = grid[i - 1][j - 1] + colSum[j][i - 1];
            }
        }
        for (int len = Math.min(m, n); len > 0; len --) {
            for (int i = 0; i <= n - len; i ++) {
                for (int j = 0; j <= m - len; j ++) {
                    int x = i + len - 1;
                    int y = j + len - 1;
                    if (rowSum[i + 1][y + 1] - rowSum[i + 1][j] == len &&
                        rowSum[x + 1][y + 1] - rowSum[x + 1][j] == len &&
                        colSum[j + 1][x + 1] - colSum[j + 1][i] == len &&
                        colSum[y + 1][x + 1] - colSum[y + 1][i] == len)
                        return len * len;
                }
            }
        }   
        return 0;    
    }
}
```