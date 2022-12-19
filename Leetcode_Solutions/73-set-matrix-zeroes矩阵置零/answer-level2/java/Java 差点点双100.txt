![image.png](https://pic.leetcode-cn.com/a5d92edb12f63e946e676d24d09fb9ef87fa513e412c1da093699d4712ed327c-image.png)

是的我就是投机取巧了用奇怪的数来当第二标签了略略略

```
    public void setZeroes(int[][] matrix) {
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                if (matrix[i][j] == 0) {
                    for (int m = 0; m < matrix.length; m++) {
                        if (matrix[m][j] != 0) {
                            matrix[m][j] = -Integer.MAX_VALUE;
                        }
                    }
                    for (int n = 0; n < matrix[0].length; n++) {
                        if (matrix[i][n] != 0) {
                            matrix[i][n] = -Integer.MAX_VALUE;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                if(matrix[i][j] == -Integer.MAX_VALUE){
                    matrix[i][j] = 0;
                }
            }
        }
    }
```
