```
public class Solution {

    public int MaxAreaOfIsland(int[][] grid) {
        if(grid.Length == 0)
        {
            return 0;
        }
        int maxCount = 0;//最大的岛屿数
        int curCnount = 0;//当前遍历到的岛屿数
        for(int i = 0;i<grid.Length;i++)
        {
            for(int j=0;j<grid[i].Length;j++)
            {
                curCnount = Island(grid,i,j);//调用递归
                if(maxCount<curCnount)
                {
                    maxCount = curCnount;
                }
            }
        }

        return maxCount;

    }
    private int Island(int[][] grid,int i,int j)//递归求相邻是否为岛屿 i行数 j列数 返回岛屿面积
    {
        int count = 0;
        if(i>=0 && j>=0 && i<grid.Length && j<grid[i].Length && grid[i][j] == 1)//是否超出边界 和 是否为陆地
        {
            grid[i][j] = 2;//表示检查过该岛屿
            count  = 1;
            //这个点的四周是否为岛屿 进行递归
            count += Island(grid,i+1,j);
            count += Island(grid,i-1,j);
            count += Island(grid,i,j-1);
            count += Island(grid,i,j+1);
            return count;
        }
        else
        {
            return 0;
        }
    }
}
```
