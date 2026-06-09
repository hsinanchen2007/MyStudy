### 解题思路
1.题目描述太苦涩以至于没读懂题目，题目另类解读：以[[1,2],[3,4]]为例：坐标（0,0）高度为1；坐标（0,1）高度为2；坐标（1,0）高度为3；坐标（1,1）高度为4
2.求出重叠部分
    2.1 垂直重叠部分，即高度-1
    2.2 行重叠的部分为当前行与前一行的高度的最小值
    2.2 列同理
3.最后总个数*6-所有重叠的个数*2
### 代码

```csharp
public class Solution {
    public int SurfaceArea(int[][] grid)
    {
        int row = grid.Length;
        if (row == 0) return 0;
        int col = grid[0].Length;
        if (col == 0) return 0;
        int sum = 0;
        //垂直重叠部分
        int verticalOverLap = 0;
        //行重叠部分
        int rowOverLap = 0;
        //列重叠部分
        int colOverLap = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                sum += grid[i][j];
                if (grid[i][j] > 0)
                    verticalOverLap += grid[i][j] - 1;
                if (j > 0)
                    colOverLap += Math.Min(grid[i][j], grid[i][j - 1]);
                if (i > 0)
                    rowOverLap += Math.Min(grid[i][j], grid[i-1][j]);
            } 
        }

        return sum * 6 - (verticalOverLap + rowOverLap + colOverLap) * 2;
    }
}
```