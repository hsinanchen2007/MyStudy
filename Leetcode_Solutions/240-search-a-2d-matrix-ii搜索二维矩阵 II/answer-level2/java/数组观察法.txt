### 解题思路
数组观察 
从右上角开始，
每次去除列或者行，
直到最后找到值为止

### 代码

```java
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
         //bad-case
         if (matrix.length == 0 || matrix[0].length == 0) {
             return false;
         }  

         //观察规律 
         //行
         int rows  =  matrix.length;
         //列
         int cols  =  matrix[0].length;

         int i = 0;

         int j = cols - 1;

         while (i < rows && j >= 0) {
             if (target > matrix[i][j]) {//去除这一列
                 i++;
             } else if (target < matrix[i][j]) {
                 j--;
             } else {
                 return true;
             }
         }

         return false;
    }
}
```