### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    public int SurfaceArea(int[][] grid) {
        int ans = 0;
        for(int i = 0; i < grid.Length; i++)
        {
            for(int j = 0; j < grid[i].Length; j++)
            {
                if(grid[i][j] == 0)
                {
                    continue;
                }
                ans += grid[i][j] * 4 + 2; //每格上立方柱面积

                //四周如果有相邻的立方柱减去相交部分的面积
                if(i > 0 && grid[i - 1].Length > j && grid[i - 1][j] > 0)
                {
                    ans -= Math.Min(grid[i - 1][j], grid[i][j]);
                }
                if(i + 1 < grid.Length && grid[i + 1].Length > j && grid[i + 1][j] > 0)
                {
                    ans -= Math.Min(grid[i + 1][j], grid[i][j]);
                }
                if(j > 0 && grid[i][j - 1] > 0)
                {
                    ans -= Math.Min(grid[i][j - 1], grid[i][j]);
                }
                if(j + 1 < grid[i].Length && grid[i][j + 1] > 0)
                {
                    ans -= Math.Min(grid[i][j + 1], grid[i][j]);
                }
            }
        }
        return ans;
    }
}
```