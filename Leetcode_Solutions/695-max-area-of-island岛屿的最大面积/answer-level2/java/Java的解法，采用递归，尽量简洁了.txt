```
class Solution {
    public int maxAreaOfIsland(int[][] grid) {
        boolean [][] flag = new boolean[grid.length][grid[0].length];//设置一个数组来判断该位置是否被遍历过。
        int maxArea=0;
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[i].length;j++){
                if(!flag[i][j]&&grid[i][j]==1)
                maxArea=Math.max(maxArea,dfs(grid,i,j,flag));
            }
        }
        return maxArea;    
    }
    public int dfs(int[][]grid,int i,int j,boolean[][]flag){
        if (i<0||i>grid.length-1||j<0||j>grid[0].length-1||grid[i][j]==0||flag[i][j])
        return 0;
        flag[i][j]=true;
        return 1+dfs(grid,i-1,j,flag)+dfs(grid,i,j-1,flag)+dfs(grid,i+1,j,flag)+dfs(grid,i,j+1,flag);

    }
}
```
