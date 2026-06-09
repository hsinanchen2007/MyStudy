### 解题思路
动态规划

### 代码

```csharp
public class Solution {
    public int MinPathSum(int[][] grid)
        {
            int heigth = grid.Length;
            int width = grid[0].Length;
            int[][] result = new int[heigth][];

            for (int i = 0; i < heigth; i++)
            {
                result[i] = new int[width];
                for (int j = 0; j < width; j++)
                {
                    if (i == 0 && j == 0)
                    {
                        result[i][j] = grid[i][j];
                    }
                    else if (i == 0)
                    {
                        result[i][j] = result[i][j - 1] + grid[i][j];
                    }
                    else if (j == 0)
                    {
                        result[i][j] = result[i - 1][j] + grid[i][j];
                    }
                    else
                    {

                        result[i][j] = Math.Min(result[i - 1][j], result[i][j - 1]) + grid[i][j];
                    }
                }
            }

            return result[heigth - 1][width - 1];
        }
}
```