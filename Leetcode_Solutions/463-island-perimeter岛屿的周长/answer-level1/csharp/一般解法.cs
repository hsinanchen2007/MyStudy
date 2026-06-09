### 解题思路
直接二层循环遍历，发现是1的单元格，先按4计算周长累加，然后判断当前单元格的上方与左方是否为相邻的1，是的话，每条边需要减去2，因为相邻的情况下，按照4累加本身就把重复的边计算了两次

### 代码

```csharp
public class Solution {
    public int IslandPerimeter(int[][] grid) {
        int round=0;
        for(int i=0;i<grid.Length;i++)
        {
            for(int j=0;j<grid[i].Length;j++)
            {
                if(grid[i][j]==1)
                {
                    round+=4;
                }
                if(j>0)
                {
                    if(grid[i][j]==1&&grid[i][j-1]==1)
                    {
                        round-=2;
                    }
                }
                if(i>0)
                {
                    if(grid[i][j]==1&&grid[i-1][j]==1)
                    {
                        round-=2;
                    }
                }
            }
        }
        return round;
    }
}
```