### 解题思路
此处撰写解题思路

注意细节，一定要先判断数组是否存在。不然获取列或报错。

### 代码

```java
class Solution {
    public boolean findNumberIn2DArray(int[][] matrix, int target) {
        // 要先判断二维数组的有效性
         if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
            return false;
        }
        int row = matrix.length;    // 获取二维数组的行数
        int col = matrix[0].length; // 获取二维数组的列数
        // 从二维数组的右上角开始位置搜索。 matrix[0][col-1]
        int i = 0;
        int j = col-1;

        //不能使用for循环，使用while更好。
        while (i<row && j>=0){
            if(target<matrix[i][j]){
                j--;
            }else if(target>matrix[i][j]) {
                i++;
            }else {
                return true;
            }
        }
        return false;
    }
}


```