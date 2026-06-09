### 解题思路
参考甜咦思路写的，还得多学习啊

### 代码

```csharp
public class Solution {
    public int MaxDistance(int[][] grid) {
        int[] dx = { 0, 0, 1, -1 };
        int[] dy = { 1, -1, 0, 0 };

        Queue<int[]> queue = new Queue<int[]>();
        int m = grid.Length, n = grid[0].Length;
        //先入队所有陆地
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    queue.Enqueue(new int[] { i, j });
                }
            }
        }
        //从各个陆地开始，一圈一圈的遍历海洋，最后遍历到的海洋就是离陆地最远的海洋
        bool hasOcean = false;
        int[] point = null;
        while (queue.Count != 0)
        {
            point = queue.Dequeue();
            int x = point[0], y = point[1];
            //取出队列的元素，将其四周的海洋入队
            for (int i = 0; i < 4; i++)
            {
                int newX = x + dx[i];
                int newY = y + dy[i];
                if (newX < 0 || newX >= m || newY < 0 || newY >= n || grid[newX][newY] != 0)
                {
                    continue;
                }
                grid[newX][newY] = grid[x][y] + 1;// 这里我直接修改了原数组，因此就不需要额外的数组来标志是否访问
                hasOcean = true;
                queue.Enqueue(new int[] { newX, newY });
            }
        }

        // 没有陆地或者没有海洋，返回-1。
        if (point == null || !hasOcean)
        {
            return -1;
        }

        // 返回最后一次遍历到的海洋的距离。
        return grid[point[0]][point[1]] - 1;
    }
}
```