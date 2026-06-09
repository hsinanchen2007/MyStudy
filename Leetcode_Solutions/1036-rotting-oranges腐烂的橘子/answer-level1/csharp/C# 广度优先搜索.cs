### 解题思路
1、使用广度搜索的方式，首先查找列表中所有等于2的网格，并加入队列中。
2、判断队列是否为空，如果不为空，则弹出一个Point，并判断该Point的上下左右是否存在新鲜的橘子，如果存在，则加入队列，并设置该点为2，表明已经呗腐烂。每次加入一个队列，就把好的橘子数量good--
3、每一次大的循环，都判断队列是否为空，如果为空，说明当前队列中所有腐烂的橘子都没有影响其他橘子，否则，说明腐烂了一批，time++，表明过了一分钟
4、到最后队列为空时，如果good!=0说明有好的橘子没有被影响，返回-1，否则返回time，也就是最终的时间

### 代码

```csharp
public class Solution {
 private int[][] direct = {
        new int[] {1,0},
        new int[] {-1,0},
        new int[] {0,1},
        new int[] {0,-1}
    };

    public int OrangesRotting(int[][] grid) {
        int row = grid.Length;
        int col = grid[0].Length;
        //这题适合用广度搜索
        Queue<Point> queue = new Queue<Point>();
        int good = 0;
        for(int i=0;i<row;i++) {
            for(int j=0;j<col;j++) {
                if(grid[i][j]==2) {
                    queue.Enqueue(new Point(i,j)); //找到所有腐烂的橘子
                }else if(grid[i][j]==1) {
                    good++;
                }

            }
        }
        int time = 0;
        
        while(queue.Count!=0) {
            int count = queue.Count;
            for(int i=0;i<count;i++) {
                Point p = queue.Dequeue();
                for(int j=0;j<4;j++) {
                    int newRow = direct[j][0] + p.row;
                    int newCol = direct[j][1] + p.col;
                    if(newRow>=0 && newRow<row && newCol>=0 && newCol<col && grid[newRow][newCol]==1) {
                        queue.Enqueue(new Point(newRow,newCol));
                        grid[newRow][newCol] = 2;
                        good--;
                    }

                }
            }
            if(queue.Count!=0) {
                //queue不为空
                time++;
            }
        }
        if(good!=0)
            return -1;
        return time;      
    }



    class Point {
        public int row;
        public int col;
        public Point(int row,int col){this.row = row;this.col = col;}
    }
}
```