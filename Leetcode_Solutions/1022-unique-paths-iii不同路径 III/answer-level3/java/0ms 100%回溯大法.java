### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    private int num=0;
    public int uniquePathsIII(int[][] grid) {
        boolean[][]used=new boolean[grid.length][grid[0].length];//用来记录这个点是否走过
        int rest=grid.length*grid[0].length;//记录剩余需要走的点数
        int []start=new int[2];//起始点坐标
        int []end=new int[2];//终点坐标
        for (int i=0;i<grid.length;i++){
            for (int j=0;j<grid[0].length;j++){
                if (grid[i][j]==-1) {
                    used[i][j] = true;
                    --rest;
                }
                else if (grid[i][j]==1){
                    start[0]=i;
                    start[1]=j;
                }
                else if (grid[i][j]==2){
                    end[0]=i;
                    end[1]=j;
                }
            }
        }
        helper(grid,used,rest,start[0],start[1],end);
        return num;
    }
    private void helper(int[][]grid,boolean[][]used,int rest,int x,int y,int[]end){
        if (x==end[0] && y==end[1]){//如果走到了终点，剩余需要走的点只剩终点了，则满足条件
            if (rest==1) {
                num++;
            }
            return;
        }
        --rest;//把当前点标记为走过
        used[x][y]=true;
        if (x-1>=0 && !used[x-1][y])//向上走
            helper(grid,used,rest,x-1,y,end);
        if (x+1<grid.length && !used[x+1][y])//向下走
            helper(grid,used,rest,x+1,y,end);
        if (y-1>=0 && !used[x][y-1])//向左走
            helper(grid,used,rest,x,y-1,end);
        if (y+1<grid[0].length && !used[x][y+1])//向右走
            helper(grid,used,rest,x,y+1,end);
        used[x][y]=false;//把当前点的标记还原
        ++rest;
    }
}
```