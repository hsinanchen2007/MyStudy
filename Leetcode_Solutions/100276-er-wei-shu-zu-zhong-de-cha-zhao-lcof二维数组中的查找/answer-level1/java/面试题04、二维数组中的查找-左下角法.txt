### 解题思路

以前看过类似的题目，这个题目应该是可以考虑从左下角或者右上角开始的

每次能过滤一行或者一列

逻辑并不复杂，看代码就是

### 代码

```java
class Solution {
    public boolean findNumberIn2DArray(int[][] matrix, int target) {
        if(matrix == null || matrix.length < 1){
            return false;
        }

        int rowNum = matrix.length;
        int columnNum = matrix[0].length;


        //左下角开始
        int i = rowNum - 1;
        int j = 0;

        while(i >= 0 && j < columnNum){
            if(matrix[i][j] == target){
                return true;
            }else if(matrix[i][j] < target){
                j ++;
            }else {
                i --;
            }
        }

        return false;

    }
}
```