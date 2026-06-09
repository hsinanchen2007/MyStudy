### 解题思路
每次选右上角元素进行比较

### 代码

```java
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        if(matrix == null || matrix.length==0 || matrix[0].length == 0){
            return false;
        }
        return search(matrix, 0, matrix[0].length-1, target);
    }
    // 从右上角
    private boolean search(int[][] matrix,  int from_row, int to_col, int target  ){
        if(from_row >= matrix.length  || to_col <0){
            return false;
        }
        if(matrix[from_row][to_col] == target){
            return true;
        }
        
        if(matrix[from_row][to_col] > target){
            return search(matrix, from_row, to_col-1, target);
        }else{
            // (matrix[from_row][to_col] < target)
            return search(matrix, from_row+1, to_col, target);
        }
    }
}
```