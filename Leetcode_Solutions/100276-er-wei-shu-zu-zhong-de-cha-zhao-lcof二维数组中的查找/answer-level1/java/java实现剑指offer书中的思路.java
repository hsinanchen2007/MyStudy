### 解题思路
从右往左先剔除比target大的所在列，
确定列后再从上往下找target所在行

### 代码

```java
class Solution {
   public boolean findNumberIn2DArray(int[][] matrix, int target) {
         if (matrix.length == 0 || matrix[0].length == 0) {
            return false;
        }
        
        for (int i = matrix.length-1; i >= 0; i--) {
            if (matrix[i][0] <= target) {//剔除比目标值大的列
                //找到可能的所在列后，向下找,j代表行号
                for (int j = 0; j < matrix[i].length; j++) {
                    if (target == matrix[i][j]) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
}
```