右上角往下遍历
```
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        if(matrix == null || matrix.length == 0 ||matrix[0].length == 0){
            return false;
        }
        int m=0;
        int n=matrix[0].length;
        while(m<matrix.length && n>0){
            if(matrix[m][n-1]==target){
                return true;
            }
            if(matrix[m][n-1]>target){
                n--;
            }else{
                m++;
            }
        }
        return false;
    }
}
```
