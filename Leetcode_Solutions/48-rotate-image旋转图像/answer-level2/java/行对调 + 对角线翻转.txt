### 解题思路
1. 先将行按中心位置对调，比如，3x3 的矩阵，先对调第一和第三行
2. 按对角线翻转

### 代码

```java
class Solution {

    public void rotate(int[][] matrix) {
        if (matrix == null || matrix.length <= 1) return;
        int n = matrix.length;
        // int[] line = new int[matrix.length];
        int[] line;
        int i = 0, j = n - 1;
        while (i < j) {
            line = matrix[j];
            matrix[j] = matrix[i];
            matrix[i] = line;
            i++;
            j--;
        }

        for (i = 0; i < n; i++) {
            for (j = i + 1; j < n; j++) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
    }
    
}
```