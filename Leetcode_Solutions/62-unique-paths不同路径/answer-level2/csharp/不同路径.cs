### 解题思路
动态规划

### 代码

```csharp
public class Solution {
    public int UniquePaths(int m, int n)
        {
            int[][] result = new int[m][];
            for (int i = 0; i < m; i++)
            {
                result[i] = new int[n];
                for (int j = 0; j < n; j++)
                {
                    if (i == 0 || j == 0)
                    {
                        result[i][j] = 1;
                    }
                    else
                    {
                        result[i][j] = result[i - 1][j] + result[i][j - 1];
                    }
                }
            }

            return result[m-1][n-1];
        }
}
```