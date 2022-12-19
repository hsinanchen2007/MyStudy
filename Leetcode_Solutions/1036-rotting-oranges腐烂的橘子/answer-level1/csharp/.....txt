### 解题思路
此处撰写解题思路

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