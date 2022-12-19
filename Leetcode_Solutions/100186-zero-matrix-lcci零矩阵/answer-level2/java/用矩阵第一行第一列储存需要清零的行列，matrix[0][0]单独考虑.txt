### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public void setZeroes(int[][] matrix) {
        int size1 = matrix.length;
        int size2 = matrix[0].length;
        boolean mark1 = false, mark2 = false;
        if(matrix[0][0] == 0) mark1 = mark2 = true;
        else{
            for(int i = 1; i < size1; i++)
            {
                if(matrix[i][0] == 0) mark1 = true;
            }
            for(int i = 1; i < size2; i++)
            {
                if(matrix[0][i] == 0) mark2 = true;
            }
        }
        for (int i = 0; i < size1; i++)
        {
            for (int j = 0; j < size2; j++)
            {
                if(matrix[i][j] == 0)
                {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for(int i = 1; i < size1; i++)
        {
            if(matrix[i][0] == 0)
            {
                for (int j = 0; j < size2; j++)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        for(int i = 1; i < size2; i++)
        {
            if(matrix[0][i] == 0)
            {
                for (int j = 0; j < size1; j++)
                {
                    matrix[j][i] = 0;
                }
            }
        }
        if(mark1)
        {
            for (int i = 0; i < size1; i++)
                {
                    matrix[i][0] = 0;
                }
        }
        if(mark2)
        {
            for (int i = 0; i < size2; i++)
                {
                    matrix[0][i] = 0;
                }
        }
    }
}
```