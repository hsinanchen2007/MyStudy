### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    public int SurfaceArea(int[][] grid) {
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