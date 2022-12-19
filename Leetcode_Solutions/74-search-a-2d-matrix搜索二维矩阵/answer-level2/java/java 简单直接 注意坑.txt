```
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        if(matrix==null||matrix.length<1||matrix[0].length<1){
            return false;
        }
        
        int row = 0;
        int col = matrix[0].length-1;
        boolean exist = false;
        while(row<matrix.length&&matrix[row][col]<target){
            row++;
        }
        if(row>=matrix.length){
            return false;
        }
        int start = 0;
        int end = col;
        while(start<=end){
            int mid = (start+end)/2;
            if(matrix[row][mid]==target){
                exist = true;
                break;
            }
            if(matrix[row][mid]>target){
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        return exist;
    }
}
```
