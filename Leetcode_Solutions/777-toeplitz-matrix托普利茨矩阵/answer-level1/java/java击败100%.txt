### 解题思路
先把第0行所有元素往右下遍历，之后再把第0列第一行开始往右下遍历即可查完所有对角。

### 代码

```java
class Solution {
    public boolean isToeplitzMatrix(int[][] matrix) {
      
      for(int i=0;i<matrix[0].length;i++)
      {
          int x=0,y=i;
          int index=matrix[x][y];
        while(x<matrix.length-1&&y<matrix[0].length-1)
        {
            x++;
            y++;
            if(matrix[x][y]!=index)
            {
                return false;
            }
        }
      }
      for(int j=1;j<matrix.length;j++)
      {
          int x=j,y=0;
          int index=matrix[x][y];
          while(x<matrix.length-1&&y<matrix[0].length-1)
          {
             x++;
             y++;
             if(matrix[x][y]!=index)
             {
                 return false;
             }
          }
      }
      return true;
    }
}
```