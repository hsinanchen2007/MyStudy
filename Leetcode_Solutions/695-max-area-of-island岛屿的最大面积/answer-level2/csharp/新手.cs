### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    public int MaxAreaOfIsland(int[][] grid)
{
    int maxArea = 0;
    int area = 0;
    for (int i = 0; i < grid.Length; i++)
    {
        for (int j = 0; j < grid[0].Length; j++)
        {
            if (grid[i][j] == 1)
            {
                //以此为中心，向四周扩散
                area = GetArea(grid, i, j);
                maxArea = maxArea > area ? maxArea : area;
            }
        }
    }
    return maxArea;
}

public int GetArea(int[][] grid, int i, int j)
{
    //由于坐标每次变化 1 个单位，所以判断是否等于数组长度即可
    if (i == grid.Length || i < 0)
        return 0;
    else if (j == grid[0].Length || j < 0)
        return 0; ;
    if (grid[i][j] == 1)
    {
        grid[i][j] = 0;
        return 1 + GetArea(grid, i + 1, j) + GetArea(grid, i - 1, j ) + GetArea(grid, i, j + 1) + GetArea(grid, i, j - 1);
    }
    return 0;
}

}
```