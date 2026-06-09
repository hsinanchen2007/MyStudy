### 解题思路
最重要是要想到用第一行和第一列做记录

1.先用两个bool记录第一列和第一行需不需要置0，留到其他数先处理再处理第一列和第一行
2.从i = 1,j = 1开始遍历matrix，凡出现0时，把matrix[i][j]对应的第一行和第一列的数置0作为记录
3.从i = 1开始遍历第一行，值是0时把对应的列置0
4.从i = 1开始遍历第一列，值是0时把对应的行置0
5.根据第一步的bool把第一行和第一列置0,完成


### 代码

```csharp
public class Solution {
    public void SetZeroes(int[][] matrix) {
        if(matrix.Length == 0 || matrix[0].Length == 0)
        {
            return;
        }

        bool firstColZero = false;
        for(int i = 0; i < matrix.Length; i++)
        {
            if(matrix[i][0] == 0)
            {
                firstColZero = true;
                break;
            }
        }

        bool firstRowZero = false;
        for(int i = 0; i < matrix[0].Length; i++)
        {
            if(matrix[0][i] == 0)
            {
                firstRowZero = true;
                break;
            }
        }

        for(int i = 1; i < matrix.Length; i++)
        {
            for(int j = 1; j < matrix[0].Length; j++)
            {
                if(matrix[i][j] == 0)
                {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        for(int i = 1; i < matrix.Length; i++)
        {
            if(matrix[i][0] == 0)
            {
                for(int j = 0; j < matrix[0].Length; j++)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        for(int i = 1; i < matrix[0].Length; i++)
        {
            if(matrix[0][i] == 0)
            {
                for(int j = 0; j < matrix.Length; j++)
                {
                    matrix[j][i] = 0;
                }
            }
        }

        if(firstColZero)
        {
            for(int i = 0; i < matrix.Length; i++)
            {
                matrix[i][0] = 0;
            }
        }

        if(firstRowZero)
        {
            for(int i = 0; i < matrix[0].Length; i++)
            {
                matrix[0][i] = 0;
            }
        }
    }
}
```