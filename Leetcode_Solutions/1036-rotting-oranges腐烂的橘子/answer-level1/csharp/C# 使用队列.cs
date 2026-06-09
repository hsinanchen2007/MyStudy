### 解题思路
总体思路：
1) 遍历表格，将所有腐烂橘子入队
2) 逐个访问队列中的每个橘子，对于访问到的橘子，检查它周围（上下左右）是否有新鲜橘子，如果有，则将它设置为腐烂橘子，并入队，如此反复，直到队列为空

### 代码

```csharp
// Orange 类有三个属性：
// 1) X与Y分别表示横纵坐标，
// 2) Layer表示多少分钟后这个橘子腐烂，例如，对于腐烂的橘子，它的值为0，对于它相邻的橘子，则为1，每往外扩展，它的值都会加1
public class Orange
{
    public int X;
    public int Y;
    public int Layer;
    public Orange(int x, int y, int layer)
    {
        X = x; Y = y; Layer = layer;
    }
}

public class Solution {

    // x与y数组里的四个值分别相当于上下左右的偏移值
    private int[] x = {0,0,-1,1};  // 上下左右
    private int[] y = {-1,1,0,0};

    // 判断指定的坐标点是否
    private bool IsInside(int[][] grid, int i, int j)
    {
        if(i < 0 || i >= grid.Length || j < 0 || j >= grid[0].Length) return false;
        return true;
    }

    public int OrangesRotting(int[][] grid) {
        int row = grid.Length, column = grid[0].Length;

        // 将所有腐烂的添加到队列中
        Queue<Orange> q = new Queue<Orange>();
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < column; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.Enqueue(new Orange(i,j,0));
                }
            }
        }

        // 再将队列中的橘子与其周围橘子进行判断
        int result = 0;
        while(q.Count > 0)
        {
            var rot = q.Dequeue();
            result = Math.Max(result,rot.Layer); // 更新最大值

            for(int k = 0; k < 4; k++)   
            {
                // 上面条件中的4表示当前判断格上下左右相邻的格一共有4个，因此这个循环是访问当前腐烂格的4个相邻格
                int newCellRow = rot.X + x[k];
                int newCellCol = rot.Y + y[k];

                if(IsInside(grid,newCellRow,newCellCol) && grid[newCellRow][newCellCol] == 1)
                {
                    // 如果目标格在grid内，且它的值为1（新鲜橘子），则将其入队，并更新它的值为2
                    // 另外，记住将 layer 加 1
                    q.Enqueue(new Orange(newCellRow,newCellCol,rot.Layer +1));
                    grid[newCellRow][newCellCol] = 2;
                }
            }
        }

        // 当队列为空后，则烂橘子所有相邻（包含连续相邻）的都腐烂了，而result的值也记录了结果
        // 此时，还要判断一下是否还存在没受影响的，如果有，返回 -1，否则返回result
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < column; j++)
            {
                if(grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }

        return result;
    }
}
```