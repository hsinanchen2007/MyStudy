
### 代码

```java
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        if(matrix.length == 0) return false;
        int row = 0,column = matrix[0].length - 1;
        while(row <= matrix.length-1 && column >= 0){
            if(matrix[row][column] == target) return true;
            if(matrix[row][column] > target){
                column--;
            }else{
                row++;
            }
        }
        return false;
    }
}
```