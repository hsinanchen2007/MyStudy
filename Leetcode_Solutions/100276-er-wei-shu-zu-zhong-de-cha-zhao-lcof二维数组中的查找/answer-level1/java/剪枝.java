### 解题思路
  从四个角触发, 看边界不断缩小筛选范围。
   这里存在优化空间，四个角的值存在重复比较了


### 代码

```java
class Solution {
    public boolean findNumberIn2DArray(int[][] matrix, int target) {
        if (matrix == null || matrix.length < 1) {
            return false;
        }
        int row = matrix.length - 1;
        int col = matrix[row].length - 1;
        int i = 0;
        int j = 0;
        while (i <= row && j <= col) {
            if (matrix[i][j] == target || matrix[i][col] == target || matrix[row][j] == target || matrix[row][col] == target) {
                return true;
            }
            if (matrix[i][j] > target || target > matrix[row][col]) {
                return false;
            }

            // 最后一列不需要考虑
            if (target < matrix[i][col]) {
                col--;
            } else {
                i++;
            }

            if (target < matrix[row][j]) {
                row--;
            } else {
                j++;
            }
        }

        return false;
    }
}
```