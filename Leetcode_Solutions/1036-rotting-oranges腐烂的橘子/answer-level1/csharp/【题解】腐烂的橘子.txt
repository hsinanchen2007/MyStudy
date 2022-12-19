### 解题思路
这题对我来讲还是有些难，虽然明白了思路之后做起来其实还好...
整体对思路就是用一个队列存放腐烂的橘子，用一个哈希表存放橘子腐烂的时间，一开始就腐烂的时间就是0。
然后依次从队列里取出腐烂的橘子，把它四个角上的橘子（若存在）全部感染，每感染一个橘子，就在哈希表中标记该橘子感染的时间为宿主橘子被感染的时间+1，并将新被感染的橘子加入队列，一直反复到队列中再没有橘子。
做完这一套操作后，看一下是否还有新鲜橘子，如果还有，就返回-1，否则返回哈希表中最大值即可。
看题解的话这种思路叫多源广度优先搜索，还得多了解一下这个名词。

### 代码

```csharp
public class Solution {
    int[] moveRow = {-1, 0, 1, 0};
    int[] moveCol = {0, -1, 0, 1};

    public int OrangesRotting(int[][] grid) {
        int m = grid.Length;
        int n = grid[0].Length;

        Queue q = new Queue(); //Rotten orange indices
        Hashtable t = new Hashtable(); //Rotten time

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 2) {
                    q.Enqueue(i*n + j);
                    t.Add(i*n + j, 0);
                }
            }
        }

        int res = 0;
        while(q.Count != 0) {
            int index = Convert.ToInt32(q.Dequeue());
            int row = index / n;
            int col = index % n;
            for(int k=0; k<4; k++) {
                int tmpRow = row + moveRow[k];
                int tmpCol = col + moveCol[k];
                
                if(0 <= tmpRow && tmpRow < m && 0 <= tmpCol && tmpCol < n && grid[tmpRow][tmpCol] == 1) {
                    grid[tmpRow][tmpCol] = 2;
                    q.Enqueue(tmpRow * n + tmpCol);
                    if(!t.Contains(tmpRow * n + tmpCol)) t.Add(tmpRow * n + tmpCol, Convert.ToInt32(t[index]) + 1);
                    res = Convert.ToInt32(t[tmpRow * n + tmpCol]);
                }
            }
        }

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) {
                    Console.WriteLine("i\t" + i + "\tj\t" + j);
                    return -1;
                }
            }
        }

        return res;
    }
}
```