```
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        //从数组左下角开始往上逐行寻找，如果左下角第一个元素小于目标值，说明目标只能在该元素所在的行,遍历该行寻找目标
         if(matrix == null || matrix.length == 0)
            return false;
        int len = matrix.length;
        int i = len-1;
        while (i >= 0){
            if(matrix[i] == null || matrix[i].length == 0)
                return false;
            if(matrix[i][0] > target){
                i--;
            }else{
                for(int k = 0; k < matrix[i].length ;k++){
                    if(matrix[i][k] == target){
                        return true;
                    }
                }
                return false;
            }
        }
        return false;
    }
}
```




