### 解题思路
左下角出发

### 代码

```java
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0)
            return false ;
        int row  = matrix.length ;
        int col = matrix[0].length ;
        int i = row -1 ;
        int j = 0;
        for (int k = 0 ; k < row + col + 1 ; k++ ) {
            if(matrix[i][j] == target)
                return true ;
            if (matrix[i][j] > target) {
                i -- ;
            }else{
                j ++ ;
            }
            if (i < 0 || j >= col)
                return false ;
        }
        return false ;
    }
}
```