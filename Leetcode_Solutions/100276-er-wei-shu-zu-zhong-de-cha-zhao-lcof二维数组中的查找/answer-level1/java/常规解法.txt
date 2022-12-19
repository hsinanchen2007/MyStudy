### 解题思路
右上角开始寻找
### 代码

```java
class Solution {
 public static boolean findNumberIn2DArray(int[][] matrix, int target) {
        if (matrix.length == 0) {
            return false;
        }
        int col = matrix[0].length - 1;
        int row = 0;
        while (col >= 0 && row < matrix.length) {
            if (target > matrix[row][col]) {
                //如果目标大于右上角说明 范围在当前列以下 所以不在当前行
                row++;
            } else if (target < matrix[row][col]) {
                //目标值小于右上角说明 所以当前列不存在
                col--;
            } else {
                return true;
            }
        }
        return false;
    }
}
```