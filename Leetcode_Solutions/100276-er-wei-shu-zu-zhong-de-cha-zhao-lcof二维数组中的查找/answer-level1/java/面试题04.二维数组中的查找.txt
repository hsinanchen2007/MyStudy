### 解题思路
因为每行每列都是按照递增排序，所以可选取矩阵右上角元素与目标元素进行比较，
如果相等，返回true；
如果大于目标元素，则不需要再比较这一列；
如果小于目标与元素，则不需要比较该行。
### 代码

```java
class Solution {
    public boolean findNumberIn2DArray(int[][] matrix, int target) {
        boolean flag = false;
        if(matrix != null && matrix.length > 0 && matrix[0].length > 0) {
            int row = 0;
            int colnum = matrix[0].length - 1;
            while(row < matrix.length && colnum >= 0) {
                if(matrix[row][colnum] == target) {
                    flag = true;
                    break;
                }else if(matrix[row][colnum] > target) {
                    --colnum;
                }else {
                    ++row;
                }
            }
        }
        return flag;
    }
}
```