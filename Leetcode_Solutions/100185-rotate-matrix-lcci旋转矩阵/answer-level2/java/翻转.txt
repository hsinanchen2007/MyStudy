### 解题思路
关键点：最后的结果中matrix[row][col] = matrix[col][n-row-1];
那么(1)先水平翻转：matrix[row][col] = matrix[n-row-1][col];
然后(2)主对角线翻转：matrix[n-row-1][col] = matrix[col][n-row-1]
一二两步合起来就等价于原来的旋转90度.并且是在原来矩阵上做的

### 代码

```java
class Solution {
    public void rotate(int[][] matrix) {
        int row = matrix.length, col = matrix[0].length;
        // 以row的一半，上下水平翻转
        for (int i=0; i<row/2; i++) {
            for (int j=0; j<col; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[row-i-1][j];
                matrix[row-i-1][j] = temp;
            }
        }
        // 以主对角线对称翻转
        for (int i=0; i<row; i++) {
            for (int j=0; j<i; j++) {
                int temp =matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
    }
}
```