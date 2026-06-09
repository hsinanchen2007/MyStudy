### 解题思路

##### 1. 题目概述：腐烂的橘子

##### 2. 思路：
   - 特征：是一个动态扩散的过程,类似于 BFS 的处理思路
   - 方案：先遍历一边,找到 BFS 的种子,然后逐轮扩散,直到无法继续扩散为止
   - 结果：若橘子总数与感染总数一致,那么返回分钟(几轮),否则就是-1
   - 其它: 如果一个橘子都没有,也谈不上什么扩散,直接返回 0,即 0 分钟以后就没有新鲜的橘子了

##### 3. 知识点：BFS

##### 4. 复杂度分析: 
   - 时间复杂度：O(m*n)
   - 空间复杂度：O(m*n) ->使用了额外的空间记录腐烂橘子的位置


### 代码

```csharp []
public class Solution {
        public int OrangesRotting(int[][] grid)
        {
            var rows = grid.Length;
            var cols = grid[0].Length;

            var totalCount = 0;
            var badCount = 0;
            var flagPos = new bool[rows, cols];
            var initQueue = new Queue<int[]>();
            for (var r = 0; r < rows; r++)
            {
                for (var c = 0; c < cols; c++)
                {
                    var curValue = grid[r][c];
                    if (curValue == 0) continue;

                    totalCount++;

                    if (curValue == 2)
                    {
                        flagPos[r, c] = true;
                        badCount++;
                        initQueue.Enqueue(new int[] { r, c });
                    }
                }
            }

            if (totalCount == 0) return 0;

            var forReturn = -1;
            var rowArray = new int[] { -1, 1, 0, 0 };
            var colArray = new int[] { 0, 0, -1, 1 };
            while (initQueue.Any())
            {
                forReturn++;

                var nextQueue = new Queue<int[]>();
                while (initQueue.Any())
                {
                    var curPos = initQueue.Dequeue();
                    for (var i = 0; i < 4; i++)
                    {
                        var newR = curPos[0] + rowArray[i];
                        var newC = curPos[1] + colArray[i];
                        if (newR >= 0 && newR < rows && newC >= 0 && newC < cols && !flagPos[newR, newC] && grid[newR][newC] == 1)
                        {
                            flagPos[newR, newC] = true;
                            badCount++;
                            nextQueue.Enqueue(new int[] { newR, newC });
                        }
                    }
                }

                initQueue = nextQueue;
            }

            return badCount == totalCount ? forReturn : -1;
        }
}
```