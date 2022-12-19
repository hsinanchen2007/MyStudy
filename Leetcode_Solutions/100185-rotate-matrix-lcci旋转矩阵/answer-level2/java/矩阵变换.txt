### 解题思路
先转置再替换列。

### 代码

```java
class Solution {
    public void rotate(int[][] matrix) {
        if (matrix == null) {
            return;
        }
        int high = matrix.length;
        if (high == 0) {
            return;
        }
        for (int row = 0; row < high; row++) {
            for(int col = row; col < high; col++) {
                matrix[row][col] = matrix[row][col] ^ matrix[col][row] ^ ( matrix[col][row] = matrix[row][col]);
            }
        }

        for (int row = 0; row < high; row++) {
            for(int col = 0; col < high - col - 1; col++) {
                matrix[row][col] = matrix[row][col] ^ matrix[row][high - col -1] ^ ( matrix[row][high - col -1] = matrix[row][col]);
            }
        }
    }
}
```