### 解题思路
遍历以第一行和第一列的点开始的对角线是否满足条件

### 代码

```java
class Solution {
 public boolean isToeplitzMatrix(int[][] matrix) {
        for (int i = 0; i < matrix.length; i++) {
            if (!valid(matrix, i, 0)) {
                return false;
            }
        }
        for (int i = 0; i < matrix[0].length; i++) {
            if (!valid(matrix, 0, i)) {
                return false;
            }
        }
        return true;
    }

    public boolean valid(int[][] matrix, int r, int c) {
        int start = matrix[r][c];
        while (r < matrix.length && c < matrix[0].length) {
            if (matrix[r][c] != start) {
                return false;
            }
            r ++;
            c ++;
        }
        return true;
    }
}
```