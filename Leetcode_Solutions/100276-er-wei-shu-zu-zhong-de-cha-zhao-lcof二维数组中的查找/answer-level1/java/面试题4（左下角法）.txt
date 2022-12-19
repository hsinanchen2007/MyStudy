### 解题思路
同右上角法的思路

### 代码

```java
class Solution {
    public boolean findNumberIn2DArray(int[][] matrix, int target) {
          boolean flag=false;
          if(matrix.length==0)return flag;
          int rows=matrix.length;
          int columns=matrix[0].length;
          int row=rows-1;
          int column=0;
          while(row>=0&&column<columns){
              if(matrix[row][column]==target){
                  flag=true;
                  break;
              }
              else if(matrix[row][column]>target){
                  row=row-1;
              }else{
                  column=column+1;
              }
          }
          return flag;
    }
}
```