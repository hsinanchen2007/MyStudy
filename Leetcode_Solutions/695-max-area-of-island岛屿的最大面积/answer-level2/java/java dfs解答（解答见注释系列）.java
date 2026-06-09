```java
class Solution {
    int[][]grid;
    int rows;
    int columns;
    int max=Integer.MIN_VALUE;
    int sum=0;
    public int maxAreaOfIsland(int[][] grid) {
        //dfs,把所有岛屿都找出来被
        //走过的1就改变其值，不用担心跳过情况，因为只要能走到这个1，他身边的1就全走过了，再取走这个1就是重复了。
        //思路之前有点被禁锢了，以为必须是4个方向的1包围，中间的土地算面积。。。
        if(grid.length==0||grid==null)
            return 0;
        this.grid = grid;
        this.rows = grid.length;
        this.columns = grid[0].length;
        for(int i=0;i<grid.length;i++)
        {
            for(int j=0;j<grid[0].length;j++)
            {
                if(grid[i][j]==1)
                {
                    findArea(i,j);
                    max=Math.max(sum,max);
                    sum=0;
                }
            }
        }
        return max==Integer.MIN_VALUE?0:max;
    }
    //不能在这个函数里传sum,比如[[1,1],[1,0]]，
    //无论是我走到右边的1，还是下边的1，此时sum都为1+1=2。而其实已经走过了另一个1，
    //但是没有加进来。
    public void findArea(int i,int j)
    {
        if(i<0||i>=rows||j<0||j>=columns||grid[i][j]==0||grid[i][j]==-1)
        {
            return ;
        }
        sum++;
        grid[i][j]=-1;
        //max=Math.max(sum,max);
        findArea(i-1,j);
        findArea(i+1,j);
        findArea(i,j+1);
        findArea(i,j-1);
    }
}
```
