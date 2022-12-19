### 解题思路
右上角查找法：将右上角数值作为比较标准（设为a[0][n-1]），假设查找数值大于右上角的数字，便可排除a[0][]的情况，重新将标准设为a[1][n-1];如果查找数值小于右上角标准a[0][n-1]的话，便可以排除a[][n-1],重新将标准设为a[0][n-2]。由此类推，记得开始时设置flag为false，如果一直找不到就到达临界条件跳出循环。
### 代码

```java
class Solution {
    public boolean findNumberIn2DArray(int[][] matrix, int target) {
          boolean flag=false;
          if(matrix.length==0)return flag;
          int rows=matrix.length;
          int columns=matrix[0].length;
          int row=0;
          int column=columns-1;
          while(row<rows&&column>=0){
              if(matrix[row][column]==target){
                  flag=true;
                  break;
              }
              else if(matrix[row][column]>target){
                  column=column-1;
              }else{
                  row=row+1;
              }
          }
          return flag;
    }
}
```