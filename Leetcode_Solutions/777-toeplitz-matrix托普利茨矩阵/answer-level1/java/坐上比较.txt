### 解题思路
判断每一个元素和自身左上的是否一样（合理范围内）

### 代码

```java
class Solution {
    public boolean isToeplitzMatrix(int[][] matrix) {
        int cols = matrix[0].length;
        int rows = matrix.length;
        for(int i = 0; i < cols; i++) {
            for(int j = 0; j < rows; j++) {
                if (i - 1 < 0 || j - 1 < 0) continue;
                if (matrix[j-1][i-1] != matrix[j][i]) {
                    return false;
                }
            }
        }
        return true;
    }
}
```