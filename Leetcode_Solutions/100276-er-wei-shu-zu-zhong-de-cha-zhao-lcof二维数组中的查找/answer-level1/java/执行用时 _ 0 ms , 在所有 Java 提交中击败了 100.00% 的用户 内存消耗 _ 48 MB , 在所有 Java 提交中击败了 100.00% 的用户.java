### 解题思路
以左下角为标志元素，和target作比较，比target小的 列右移，比target大的，行上移

### 代码

```java
class Solution {
    public boolean findNumberIn2DArray(int[][] matrix, int target) {
        if(matrix == null || matrix.length ==0){
            return false;
        }
        int m = matrix.length, n = matrix[0].length;
        int row = m-1;
        int col = 0;
        while (row >= 0 && col < n){
            if(matrix[row][col] == target){
                return true;
            }else if(matrix[row][col] > target) {
                row--;
            }else{
                col++;
            }
        }
        return false;
    }
}
```