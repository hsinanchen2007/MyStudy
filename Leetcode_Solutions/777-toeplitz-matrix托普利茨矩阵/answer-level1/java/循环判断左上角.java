### 解题思路
循环判断和左上角是否相等，如果判断右下角则需要担心越界问题

### 代码

```java
class Solution {
    public boolean isToeplitzMatrix(int[][] matrix) {
             //0,0  1,1,  2,2   
             //0,1  1,2   2,3
            
             int col=matrix[0].length;
             int row=matrix.length;
             if (row == 1 || col == 1)
              return true;
             for(int i=1;i<row;i++)
                 for(int k=1;k<col;k++){
                    if(matrix[i][k]!=matrix[i-1][k-1]){
                        return  false;
                    }          
                }
                 return true;
   }
}

```