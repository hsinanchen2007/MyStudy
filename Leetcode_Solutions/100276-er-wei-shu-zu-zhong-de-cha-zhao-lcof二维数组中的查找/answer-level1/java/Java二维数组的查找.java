**思路**
可以选择从右上角开始查找对应的数字，也可以从左下方开始；
```
class Solution {
    public boolean findNumberIn2DArray(int[][] matrix, int target) {
        if(matrix==null||matrix.length==0){
            return false;
        }
        int row = matrix.length,col = matrix[0].length;
        int i = col - 1,j = 0;
        while(i>=0&&j<row){
            if(matrix[j][i]>target){
                i--;
            }else if(matrix[j][i]<target){
                j++;
            }else{
                return true;
            }
        }
        return false;
    }
}
```
