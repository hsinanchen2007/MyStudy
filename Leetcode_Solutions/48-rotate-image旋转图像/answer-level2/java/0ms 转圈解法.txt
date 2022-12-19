### 解题思路
next = f(x,y) = (y, n-1-x);
(0,1) -> (1, n-1) -> (n-1, n-2) -> (n-2, 1) -> (0,1)
每次旋转一圈,一圈4个元素
每一层有 n-1 圈
(n是每个n阶矩阵的外层元素个数，比如5x5矩阵，n=5,4,3,2,1，其中n=1不用旋转)

### 代码

```java
class Solution {
    public void rotate(int[][] matrix) {
        int n = matrix.length;
        if (n <= 1) {
            return;
        }
        int tmp;
        for(int i=0; i<n/2; i++) {
            for (int j = i; j < n-i-1; j++ ) {
                tmp = matrix[i][j];
                matrix[i][j] = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                matrix[j][n-1-i] = tmp;
                // 逆时针90度
                // matrix[i][j] = matrix[j][n-1-i];
                // matrix[j][n-1-i] = matrix[n-1-i][n-1-j];
                // matrix[n-1-i][n-1-j] = matrix[n-1-j][i];
                // matrix[n-1-j][i] = tmp;
            }
        }
    }
}
```