### 解题思路
假设我们开始将指针指向矩阵的左下角，那么当前元素比target大的时候,row-1,比target小的时候column+1,如此反复直到指针失效。

### 代码

```java
class Solution {
   public boolean searchMatrix(int[][] matrix, int target) {
        if(matrix==null){
            return false;
        }
        int maxRow = matrix.length-1;
        if(maxRow<0){
            return false;
        }
        int maxColumn = matrix[0].length-1;
        //初始化左下角的指针
        int startRow = maxRow;
        int startColumn = 0;
        while(startRow>=0&&startColumn<=maxColumn){
            if(matrix[startRow][startColumn]>target){
                startRow--;
            }else if(matrix[startRow][startColumn]<target){
                startColumn++;
            }else{
                return true;
            }
        }
       return false;
    }
}
```