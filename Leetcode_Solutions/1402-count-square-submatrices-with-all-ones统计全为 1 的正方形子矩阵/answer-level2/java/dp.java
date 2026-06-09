利用原矩阵记录计算结果. 
当martix[i][j] == 1时, 计算以(i, j)作为正方形的右下角顶点的正方形的个数, 将该个数赋值到martix[i][j].
dp[m][n] = min(dp[m-1][n], dp[m][n-1], dp[m-1][n-1]) + 1

```java
public int countSquares(int[][] matrix) {
    int sum = 0;
    for (int i = 0; i < matrix.length; i++) {
        for (int j = 0; j < matrix[0].length; j++) {
            if (matrix[i][j] == 0) {
                continue;
            }

            if (i == 0 || j == 0) {
                sum += 1;
            } else {
                matrix[i][j] = Math.min(matrix[i - 1][j - 1], Math.min(matrix[i - 1][j], matrix[i][j - 1])) + 1;
                sum += matrix[i][j];
            }
        }
    }
    return sum;
}
```