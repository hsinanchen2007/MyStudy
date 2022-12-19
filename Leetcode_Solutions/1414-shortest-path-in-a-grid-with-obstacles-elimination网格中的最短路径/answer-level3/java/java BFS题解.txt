大概的思路基本和标准答案一致
标准答案：因为有一个约束条件必须可以打破k个障碍，找到最短路径L，那么可以建立一个vis[i][j][k]数组，其中(i,j)代表`当前位置`，k代表的是`已经消除阻碍的次数`，其实能这么建立的前提是因为bfs先访问到的点(i,j)路径一定是最短的，所以用三维数组来约束bfs就可以得到答案。

自己的思路：
- 我的思路也是bfs，但是要先建立一个brkflag[i][j]，代表的是访问点(i,j)时，最小的消除阻碍的次数。stepflag[i][j]，代表的是访问点(i,j)，最小的步数。
- 假设当前状态是now(x,y,消除次数brk，步数step），可以想象：
- 假设要通过点(i,j)，如果当前是个空地，能经过这个点(i,j)，要不就是now.step + 1 < stepflag[i][j]，就是now经过这个点时需要的步数比以前的访问stepflag[i][j]还要小，所以可以再次访问点(i,j)；当然另外一种情况就是即使 now.step + 1 > stepflag[i][j]，但是now.brk < brkflag[i][j]，就是虽然的now经过这个点(i,j)时的步数长，但是我的brk次数小一点，用于以后再次brk，所以也可以再次访问点(i,j)；
- 假设要通过点(i,j)，如果当前是个阻碍，首先要判定brk次数超过k没有，没有的时候再做下面的访问：能经过这个点(i,j)，要不就是now.step + 1 < stepflag[i][j]，就是now经过这个点时需要的步数比以前的访问stepflag[i][j]还要小，所以可以再次访问点(i,j)；当然另外一种情况就是即使 now.step + 1 > stepflag[i][j]，但是now.brk < brkflag[i][j]，就是虽然的now经过这个点(i,j)时的步数长，但是我的brk次数小一点，用于以后再次brk，所以也可以再次访问点(i,j)；
- 复杂度大概也是$O(m^2n^2)$，这次要爆搜了。
```
import java.util.LinkedList;
import java.util.Queue;

public class test15 {

    final int N = 4;
    final int[] dx = {1,-1,0,0};
    final int[] dy = {0,0,1,-1};
    int m,n;
    int myk;
    int ans = Integer.MAX_VALUE;
    int[][] mygrid;
    int[][] brkflag;
    int[][] stepflag;

    class Point
    {
        int x,y;
        int brk;
        int step;

        public Point(int x, int y, int brk, int step) {
            this.x = x;
            this.y = y;
            this.brk = brk;
            this.step = step;
        }
    }

    public void bfs()
    {
        Queue<Point> q = new LinkedList<>();
        Point root = new Point(0,0,0,0);
        brkflag[0][0] = 0;
        stepflag[0][0] = 0;
        q.offer(root);
        while (!q.isEmpty())
        {
           Point now = q.poll();

           if(now.x == m - 1 && now.y == n -1)
           {
               ans = Math.min(ans,now.step);
               continue;
           }

           for(int i = 0;i < N;i++)
           {
               int tmpx = now.x + dx[i];
               int tmpy = now.y + dy[i];

               if(tmpx < 0 || tmpx >= m || tmpy >=n || tmpy < 0) continue;

               if(mygrid[tmpx][tmpy] == 0)
               {
                  if(stepflag[tmpx][tmpy] == -1 || (now.step + 1 < stepflag[tmpx][tmpy]))
                  {
                      q.offer(new Point(tmpx,tmpy,now.brk,now.step + 1));
                      stepflag[tmpx][tmpy] = now.step + 1;
                  }
                  else if(brkflag[tmpx][tmpy] == -1 || now.brk < brkflag[tmpx][tmpy])
                  {
                      q.offer(new Point(tmpx,tmpy,now.brk,now.step + 1));
                      brkflag[tmpx][tmpy] = now.brk;
                  }
               }
               else
               {
                   if(now.brk >= myk) continue;

                   if(stepflag[tmpx][tmpy] == -1 || (now.step + 1 < stepflag[tmpx][tmpy]))
                   {
                       q.offer(new Point(tmpx,tmpy,now.brk + 1,now.step + 1));
                       stepflag[tmpx][tmpy] = now.step + 1;
                   }
                   else if(brkflag[tmpx][tmpy] == -1 || (now.brk + 1 < brkflag[tmpx][tmpy]))
                   {
                       q.offer(new Point(tmpx,tmpy,now.brk + 1,now.step + 1));
                       brkflag[tmpx][tmpy] = now.brk + 1;
                   }
               }

           }
        }
    }

    public int shortestPath(int[][] grid, int k) {

        m = grid.length;
        n = grid[0].length;
        mygrid = grid;
        myk = k;

        brkflag = new int[m][n];
        stepflag= new int[m][n];
        for(int i = 0;i < m;i++)
        {
            for(int j = 0;j < n;j++)
            {
                brkflag[i][j] = -1;
                stepflag[i][j] = -1;
            }
        }

        bfs();
        return ans== Integer.MAX_VALUE?-1:ans;
    }
    public static void main(String[] args) {

        test15 of = new test15();
        int [][] grid = {{0,0,0},{1,1,0},{0,0,0},{0,1,1},{0,0,0}};
        int k = 1;
        System.out.println(of.shortestPath(grid,k));
    }
}

```
