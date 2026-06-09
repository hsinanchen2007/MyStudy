### 解题思路
因为某个点的最短路径为左边和上边方格的最短路径中的较小值+该点的值，所以可以用动态规划来做。并用mem数组来存储每个格子已经得出的最短路径，减少递归次数。

### 代码

```java
class Solution {
    int[][]mem;
    int res;
    public int minPathSum(int[][] grid) {
        int R=grid.length,C=grid[0].length;
        mem=new int[R][C];
        return dp(grid,R-1,C-1);
    }
    public int dp(int[][]grid,int r,int c){
        if(r==0&&c==0)return grid[0][0];
        int len=Integer.MAX_VALUE;
        if(r-1>=0){
            if(mem[r-1][c]!=0){
                len=Math.min(len,mem[r-1][c]+grid[r][c]);
            }else{
                int temp=dp(grid,r-1,c);
                mem[r-1][c]=temp;
                len=Math.min(len,mem[r-1][c]+grid[r][c]);
            }
        }
        if(c-1>=0){
            if(mem[r][c-1]!=0){
                len=Math.min(len,mem[r][c-1]+grid[r][c]);
            }else{
                int temp=dp(grid,r,c-1);
                mem[r][c-1]=temp;
                len=Math.min(len,mem[r][c-1]+grid[r][c]);
            }
        }
        return len;
    }
}

```