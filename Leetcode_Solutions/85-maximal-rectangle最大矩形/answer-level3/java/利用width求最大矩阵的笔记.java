### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int maximalRectangle(char[][] matrix) {
        if (matrix.length == 0) {
        return 0;
    }
        int max=0;
    int[][] width=new int [matrix.length][matrix[0].length];
    for(int row=0;row<matrix.length;row++)
    {
    for(int col=0;col<matrix[0].length;col++)
    {
        if(matrix[row][col]=='1')
        {
            if(col==0)
            {
                width[row][col]=1;
            }else
            {
                width[row][col]=width[row][col-1]+1;
            }
        }else{
            width[row][col]=0;
        }
    int minwidth=width[row][col];
    for(int up=row;up>=0;up--)
    {
        int height=row-up+1;
        minwidth=Math.min(minwidth,width[up][col]);
    max=Math.max(max,height*minwidth);
    }
    }
}
return max;
    }
}
```