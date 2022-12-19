### 解题思路
此题只需要对角线翻转，然后再上下翻转就可以实现。

### 代码

```csharp
public class Solution {
    public void Rotate(int[][] matrix) 
    {
       int a, b;
            for (int i = 0; i <matrix.GetLength(0); i++)
            {
                a = matrix.Rank;
                for (int j = 0; j < matrix.GetLength(0) - i - 1; j++)
                {
                    a--;
                    b = matrix[i][j];
                    matrix[i][j] = matrix[matrix.GetLength(0) - (j + 1)][matrix.GetLength(0) - 1 - i];
                    matrix[matrix.GetLength(0) - (1 + j)][matrix.GetLength(0) - 1 - i] = b;
                }
            }

            for (int i = 0; i < matrix.GetLength(0)/2; i++)
            {
                for (int j = 0; j < matrix.GetLength(0); j++)
                {

                    b = matrix[i][j];
                    matrix[i][j] = matrix[matrix.GetLength(0) - i - 1][j];
                    matrix[matrix.GetLength(0) - 1 - i][j] = b;
                }
            }
          
           
           
    }
}
```