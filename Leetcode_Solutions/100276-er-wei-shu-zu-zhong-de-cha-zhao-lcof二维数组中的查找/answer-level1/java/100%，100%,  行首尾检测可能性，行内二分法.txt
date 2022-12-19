### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean findNumberIn2DArray(int[][] matrix, int target) {
        
        if(matrix == null || matrix.length == 0 ||matrix[0].length == 0) {
            return false;
        }
        int endN = matrix.length - 1 , endM = matrix[0].length -1;

        // 上下边界
        if(matrix[0][0]>target || matrix[endN][endM]<target){
            return false;
        }

        // 遍历每行的首位，在范围内则二分法检查这行是否存在
        for(int i = 0; i <= endN ;i++){
            if(target >= matrix[i][0] && target <= matrix[i][endM]){
               if(checkLine(matrix,target,i)){
                   return true;
               }
            }
            
        }
        return false;
    }

    // 二分法检查某行
    private boolean checkLine(int[][] matrix ,int target , int n){
        int end = matrix[0].length -1,mid = (end+1)/2,start = 0;
        if(target <  matrix[n][start] || target > matrix[n][end]){
            return false;
        }

        while(true){
            if(target == matrix[n][mid]){
                return true;
            } else if(target > matrix[n][mid]){
                if((mid+1) > end){
                    return false;
                }
                start = mid + 1;
                mid = (start + end) / 2;
            } else if(target < matrix[n][mid]){
                if((mid-1) < start){
                    return false;    
                }
                end = mid - 1;
                mid = (start + end) / 2;
            }
        }

    }     
}
```