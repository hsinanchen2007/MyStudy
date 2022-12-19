### 解题思路

![image.png](https://pic.leetcode-cn.com/dc8bc2ad0b1075290d9d87ab517b0ab6e0823c5176a0b0e7045138e2875e04d5-image.png)

### 代码

```java
class Solution {
    public void setZeroes(int[][] matrix) {
        int val = matrix[0][0];
        for (int i = 0; i < matrix.length; i++) {
            if (matrix[i][0] == 0) val = 0;
            for (int j = 1; j < matrix[i].length; j++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for (int i = 1; i < matrix.length; i++) {
            for (int j = 1; j < matrix[i].length; j++) {
                if (matrix[0][j] == 0 || matrix[i][0] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        if (matrix[0][0] == 0) {
            for (int i = 0; i < matrix[0].length; i++) {
                matrix[0][i] = 0;
            }
        }

        if (val == 0) {
            for (int i = 0; i < matrix.length; i++) {
                matrix[i][0] = 0;
            }
        }
    }
}
```