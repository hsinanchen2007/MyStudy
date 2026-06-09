### 解题思路

从第一行和第一列开始，检查每个对角线元素是否相等即可

### 代码

```java
class Solution {
    boolean isToeplitzMatrixLine(int[][] matrix, int i, int j) {
        int a = matrix[i][j];
        while (i < matrix.length && j < matrix[0].length) {
            if (matrix[i][j] != a) {
                return false;
            }
            i += 1;
            j += 1;
        }
        return true;
    }

    public boolean isToeplitzMatrix(int[][] matrix) {
        for (int i = 0; i < matrix[0].length; i++) {
            if (!isToeplitzMatrixLine(matrix, 0, i)) {
                return false;
            }
        }
        for (int i = 0; i < matrix.length; i++) {
            if (!isToeplitzMatrixLine(matrix, i, 0)) {
                return false;
            }
        }
        return true;
    }
}
```