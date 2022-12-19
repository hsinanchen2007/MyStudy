图的 BFS。

```
/*
 * @lc app=leetcode.cn id=1162 lang=csharp
 *
 * [1162] 地图分析
 */

// @lc code=start
public class Solution {
    public int MaxDistance(int[][] grid) {
        int length = grid.Length;
        if(length == 0)
        {
            return -1;
        }

        int[] dx = {0, 0, 1, -1};
        int[] dy = {1, -1, 0, 0};

        Queue<Coordinate> queue = new Queue<Coordinate>();
        for(int i = 0; i < length; i++)
        {
            for(int j = 0; j < length; j++)
            {
                if(grid[i][j] == 1)
                {
                    queue.Enqueue(new Coordinate(i,j));
                }
            }
        }

        bool hasOcean = false;
        Coordinate coordinate = null;
        while (queue.Any())
        {
            coordinate = queue.Dequeue();
            for(int i = 0; i < 4; i++)
            {
                var x = coordinate.X + dx[i];
                var y = coordinate.Y + dy[i];

                if(x < 0 || y < 0 || x >= length  || y >= length || grid[x][y] != 0)
                    continue;

                hasOcean = true;
                grid[x][y] = grid[coordinate.X][coordinate.Y] + 1; 
                queue.Enqueue(new Coordinate(x,y));
            }
        }

        if(coordinate == null || !hasOcean)
        {
            return -1;
        }

         return grid[coordinate.X][coordinate.Y] - 1;
    }
}

class Coordinate
{
    public Coordinate(int x,int y)
    {
        X = x;
        Y = y;
    }
    public int X { set; get; }
    public int Y { set; get; }
}
```
