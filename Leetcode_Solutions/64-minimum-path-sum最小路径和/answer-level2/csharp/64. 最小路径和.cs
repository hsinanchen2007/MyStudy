### 解题思路
C# 动态规划

### 代码

```csharp
public class Solution {
    public int MinPathSum(int[][] grid) {
        int height = grid.Length;
        if (height == 0)
        {
            return 0;
        }
        int width = grid[0].Length;
        var dp = new int[height, width];
        dp[height - 1, width - 1] = grid[height - 1][width - 1];
        for (int index = width - 2; index >= 0; index--)
        {
            dp[height - 1, index] = dp[height - 1, index + 1] + grid[height - 1][index];
        }
        for (int index = height - 2; index >= 0; index--)
        {
            dp[index, width - 1] = dp[index + 1, width - 1] + grid[index][width - 1];
        }

        for (int y = height - 2; y >= 0; y--)
        {
            for (int x = width - 2; x >= 0; x--)
            {
                dp[y, x] = Math.Min(dp[y + 1, x], dp[y, x + 1]) + grid[y][x];
            }
        }

        return dp[0, 0];
    }
}
```