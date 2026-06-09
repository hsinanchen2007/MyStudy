![微信图片_20200113203526.png](https://pic.leetcode-cn.com/f6fb4f76c0f87f4cd161cce7e960d0de1528cbab9a4079b88d88b14cd3ce511c-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200113203526.png)
```
class Solution {
    public int[][] colorBorder(int[][] grid, int r0, int c0, int color) {
        boolean[][] flag=new boolean[grid.length][grid[0].length];
        int target=grid[r0][c0];
        help(grid,flag,r0,c0,target,color);
        return grid;
    }
    public void help(int[][] grid,boolean[][] flag,int i,int j,int target,int color){
        if(i<0 || i>=grid.length || j<0 || j>=grid[0].length || grid[i][j]!=target || flag[i][j]){
            return;
        }
        flag[i][j]=true;
        if(i==0 || i==grid.length-1 || j==0 || j==grid[0].length-1){
            grid[i][j]=color;
        }
        if(i<grid.length-1 && !flag[i+1][j] && grid[i+1][j]!=target || i>0 && !flag[i-1][j] && grid[i-1][j]!=target || j<grid[0].length-1 && !flag[i][j+1] && grid[i][j+1]!=target || j>0 && !flag[i][j-1] && grid[i][j-1]!=target){
            grid[i][j]=color;
        }
        help(grid,flag,i+1,j,target,color);
        help(grid,flag,i-1,j,target,color);
        help(grid,flag,i,j+1,target,color);
        help(grid,flag,i,j-1,target,color);
    }
}
```

