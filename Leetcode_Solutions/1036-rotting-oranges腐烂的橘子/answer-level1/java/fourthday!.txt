### 解题思路
广度优先算法
设置队列存放着腐烂的橘子
如同找迷宫出口
找到出口（新鲜橘子数为0）没有路可走（放腐烂橘子的队列空）
其中边界条件很特殊容易使数组溢出
设计四个方向的（-1，0），（+1，0），（0，-1），（0，+1）条件
### 代码

```java
class Solution {
    public int orangesRotting(int[][] grid) {
        Queue<int[]> bado=new LinkedList<int[]>();//存放腐烂的橘子的队列
        int count=0;//格子中新鲜橘子的计数
        for(int n=0;n<grid.length;n++)
        {
            for(int m=0;m<grid[0].length;m++)
            {
                if(grid[n][m]==1)
                {
                    count++;
                }
                else if(grid[n][m]==2)
                {
                    bado.offer(new int[]{n,m});
                }
            }
        }
        int time=0;
        while(!bado.isEmpty()&&count>0)
        {
            int n=bado.size();
            time++;
            for(int i=0;i<n;i++)
            {
            int r,c;
            int[] b=bado.poll();
            r=b[0];
            c=b[1];
            if(r-1>=0&&grid[r-1][c]==1)
            {
                grid[r-1][c]=2;
                count--;
                bado.offer(new int[]{r-1,c});
            }
            if(c-1>=0&&grid[r][c-1]==1)
            {
                grid[r][c-1]=2;
                count--;
                bado.offer(new int[]{r,c-1});
            }
            if(r+1<grid.length&&grid[r+1][c]==1)
            {
                grid[r+1][c]=2;
                count--;
                bado.offer(new int[]{r+1,c});
            }
            if(c+1<grid[0].length&&grid[r][c+1]==1)
            {
                grid[r][c+1]=2;
                count--;
                bado.offer(new int[]{r,c+1});
            }
            }
        }
        if(count>0)
        {
            return -1;
        }
        else
        {
            return time;
        }
    }
}
```