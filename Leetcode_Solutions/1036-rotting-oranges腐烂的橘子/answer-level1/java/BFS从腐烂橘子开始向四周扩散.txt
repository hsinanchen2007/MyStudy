### 解题思路
我们可以从所有腐烂的橘子坐标处同时开始出发，将四周的新鲜橘子变腐烂，这就是一分钟的过程。
1.遍历将腐烂橘子的坐标入队
2.**同时**入队的腐烂橘子为一层，遍历这一层，将四周值为1(新鲜橘子)变为2，再将它们的坐标入队
3.遍历一层后，分钟数加一，就这样一直到队列为空

这道题的这种解法和1162.地图分析的填海造陆解法几乎一样。可以看看：[https://leetcode-cn.com/problems/as-far-from-land-as-possible/]()

### 代码

```java
class Solution {
    public int orangesRotting(int[][] grid) {
        Queue<int []>queue=new LinkedList<>();
        boolean hasOne=false;
        int [][] direction={{1,0},{-1,0},{0,1},{0,-1}};
        for(int i=0;i<grid.length;i++)
            for(int j=0;j<grid[0].length;j++){
                if(grid[i][j]==2)
                    queue.offer(new int[]{i,j});
                else if(grid[i][j]==1)
                    hasOne=true;
            }
        if(queue.isEmpty())return hasOne?-1:0;
        int ans=0;
        while(!queue.isEmpty()){
            int n=queue.size();
            for(int i=0;i<n;i++){
                int [] t=queue.poll();
                for(int j=0;j<4;j++){
                    int x=t[0]+direction[j][0];
                    int y=t[1]+direction[j][1];
                    if(x>=0&&x<grid.length&&y>=0&&y<grid[0].length&&grid[x][y]==1){
                        grid[x][y]=2;
                        queue.offer(new int[]{x,y});
                    }
                }//for 每个腐烂的橘子，将四周好的橘子变腐烂
            }//for 一层
            ans++;
        }//while

        for(int i=0;i<grid.length;i++)
            for(int j=0;j<grid[0].length;j++)
                if(grid[i][j]==1)
                    return -1;
        return ans-1;
    }
}
```