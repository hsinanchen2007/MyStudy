### 解题思路
抄的
先遍历grid找到大陆  然后逐步判断大陆周围四个方格是否是没标记过的海洋 若是 则标记
最后找到的就是最远的海洋

### 代码

```csharp
public class Solution {
    public int MaxDistance(int[][] grid) {
 int[] dx = { 0, 0, 1, -1 };                        //这两个数组可拼成(0,1)(0,-1)(1,0)(-1,0) 用来读取四周
 int[] dy = { 1, -1, 0, 0 };

            Queue<int[]> queue = new Queue<int[]>();                        //队列
            int m = grid.Length, n = grid[0].Length;                        
            for(int i=0;i<m;i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (grid[i][j] == 1) queue.Enqueue(new int[] { i, j });                 //找出所有大陆存进queue
                }
            }
            if (queue.Count() == 0) return -1;                  //没有大陆返回-1

            bool hasocean = false;
            int[] point = null;
            while (queue.Count!=0)                      
            {
                point = queue.Dequeue();                //去除队列第一个赋值给point 并删除  先进先出
                for(int i =0;i<4;i++)
                {
                    int newx = point[0] + dx[i];
                    int newy = point[1] + dy[i];
                    if( newx<0|| newx>=m||newy<0||newy>=n||grid[newx][newy]!=0 )
                    { continue; }                                                           //如果超过边界或已经标记过 则跳过继续
                    grid[newx][newy] = grid[point[0]][point[1]] + 1;                        //新的海洋就标记成出发点的数字+1
                    hasocean = true;
                    queue.Enqueue(new int[] { newx, newy });                        //将新的点插入到queue的末尾
                }
            }
            if (hasocean == false) return -1;                           //如果没有海洋 返回-1




            return grid[point[0]][point[1]]-1;                          //结果就是运行完后queue中最后一个点的标记-1
    }
}
```