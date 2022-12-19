# 思路
一个烂橘子传染周围，周围的再传染周围的，相当于二叉树一层一层的向下，是一个广度优先问题。
# 代码
```
class Solution {
    private int[][] directions = new int[][]{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    public int orangesRotting(int[][] grid) {
        if(grid==null||grid.length==0||grid[0].length==0)
        return 0;
        int rows=grid.length;
        int cols=grid[0].length;
        Queue<int[]> queue = new ArrayDeque<>();
        //队列中加入值为2的节点，也就是腐烂的橘子
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(grid[i][j]==2)
                queue.add(new int[]{i,j});
            }
        }
        //层数
        int count=0;
        while(!queue.isEmpty())
        {
            //这一层的个数
            int size=queue.size();
            while(size-->0)
            {
                int[] cur=queue.poll();
                for(int[] d:directions)
                {
                    int r=cur[0]+d[0];
                    int c=cur[1]+d[1];
                    if(r>=0&&r<rows&&c>=0&&c<cols&&grid[r][c]==1)
                    {
                        queue.add(new int[]{r,c});
                        grid[r][c]=2;
                    }
                }
            }
            count++;
        }
        //搜索完了，看还有没有没被传染的
        for(int[] row:grid)
        {
            for(int num:row)
            {
                if(num==1)
                return -1;
            }
        }
        return count==0 ? 0 : count-1;
    }
}
```
- 时间复杂度：O(r*c),r行c列
- 空间复杂度：O(r*c),r行c列
