```
/**
*   从右上角开始，如果target比当前数字小，则左移一格，
*                如果target比当前数字大，则下移一格
*/
class Solution {
    public boolean findNumberIn2DArray(int[][] matrix, int target) {
        if(matrix.length == 0) return false;
        
        int i = 0;
        int j = matrix[0].length - 1;
        while(i >= 0 && i < matrix.length && j >= 0 && j < matrix[0].length){
            if(matrix[i][j] == target)
                return true;
            else if(target < matrix[i][j]){
                -- j;
            }else{
                ++ i;
            }
        }
        return false;
    }
}
```
