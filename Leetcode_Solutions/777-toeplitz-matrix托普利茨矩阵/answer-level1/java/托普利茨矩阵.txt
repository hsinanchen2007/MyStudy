### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isToeplitzMatrix(int[][] matrix) {
        if(matrix==null||matrix.length==0)
            return false;
        int m=matrix.length;
        int n=matrix[0].length;
        //上一步得到矩阵的行为m，列为n
        
        for(int i=0;i<m-1;i++)
        {
            for(int j=0;j<n-1;j++)
            {
                if(matrix[i][j]!=matrix[i+1][j+1])
                    return false;
            }
        }
        return true;
    }
}
```