执行用时 :1 ms, 在所有 Java 提交中击败了 100.00% 的用户
内存消耗 :42.9 MB, 在所有 Java 提交中击败了 20.96% 的用户

### 解题思路
用两个两层循环，分别判断行和列

### 代码

```java
class Solution {
    public boolean isToeplitzMatrix(int[][] matrix) {
        int width = matrix[0].length;
        int height = matrix.length;
        if (width == 1 || width == 1) return true;
        for (int i = 0; i < width - 1; i++) {
            for (int j = 1, k = i + 1; k < width && j < height; j++, k++) {
                if (matrix[0][i] != matrix[j][k]) return false;
            }
        }
        for (int i = 1; i < height - 1; i++) {
            for (int j = i + 1, k = 1; k < width && j < height; j++, k++) {
                if (matrix[i][0] != matrix[j][k]) return false;
            }
        }
        return true;
    }
}
```