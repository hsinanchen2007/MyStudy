![无标题.png](https://pic.leetcode-cn.com/69f32271ac31febfe7b3f375e2f67c5f38b7bf3eb9f2a740c664743506145962-%E6%97%A0%E6%A0%87%E9%A2%98.png)

    为了方便计算，前缀和的矩阵dp的行列均比mat多1，那么dp[i][j]就是（0 <= 行 <= i， 0 <= 列 <= j)范围内的和，可通过动态规划求出；
    如下图所示: 黄色点坐标为(x0, y0), 蓝色点坐标为(x1, y1)，中间的红色矩阵就是我们的某个矩形区域。
![无标题.png](https://pic.leetcode-cn.com/467dfb564ea36746040790ed4807a5be1937ca5323e2dc330dcc2d2306344603-%E6%97%A0%E6%A0%87%E9%A2%98.png)


```
class Solution {
    public int[][] matrixBlockSum(int[][] mat, int K) {
        int row = mat.length;
        int col = mat[0].length;
        int[][] res = new int[row][col];
        int[][] dp = new int[row + 1][col + 1];
        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= col; j++)
                dp[i][j] = mat[i - 1][j - 1] + dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1];
        }
        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= col; j++) {
                int x0 = Math.max(i - K - 1, 0);
                int x1 = Math.min(i + K, row);
                int y0 = Math.max(j - K - 1, 0);
                int y1 = Math.min(j + K, col);
                res[i - 1][j - 1] = dp[x1][y1] - dp[x1][y0] - dp[x0][y1] + dp[x0][y0];
            }
        }
        return res;
    }
}
```
