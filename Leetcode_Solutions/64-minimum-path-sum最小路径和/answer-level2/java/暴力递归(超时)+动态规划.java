### 解题思路
 此处撰写解题思路

### 代码

```java
class Solution {
    public int minPathSum(int[][] grid) {
        int row=grid.length,col=grid[0].length;
        int[][] dp=new int[row][col];
    //从左上角动态规划 dp[i][j]表示从(0,0)位置到(i,j)位置的最小路径和
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(i==0 && j==0){
                    dp[i][j]=grid[i][j];
                }else if(i==0 && j!=0){
                    dp[i][j]=grid[i][j]+dp[i][j-1];
                }else if(i!=0 && j==0){
                    dp[i][j]=grid[i][j]+dp[i-1][j];
                }else{
                    dp[i][j]=grid[i][j]+Math.min(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[row-1][col-1];

        //从右下角动态规划 dp[i][j]表示从(i,j)位置到(row-1,col-1)的最小路径和
        // dp[row-1][col-1]=grid[row-1][col-1];
        // for(int i=row-2;i>=0;i--){
        //     dp[i][col-1]=grid[i][col-1]+dp[i+1][col-1];
        // }
        // for(int j=col-2;j>=0;j--){
        //     dp[row-1][j]=grid[row-1][j]+dp[row-1][j+1];
        // }
        // for(int i=row-2;i>=0;i--){
        //     for(int j=col-2;j>=0;j--){
        //         dp[i][j]=grid[i][j]+Math.min(dp[i+1][j],dp[i][j+1]);
        //     }
        // }
        // return dp[0][0];

    }
//暴力递归过程 调用：process(grid,0,0),会显示超时
    public int process(int[][] grid,int i,int j){
        if(i==grid.length-1 && j==grid[0].length-1){
            return grid[i][j];
        }
        if(i==grid.length-1){
            return grid[i][j]+process(grid,i,j+1);
        }
        if(j==grid[0].length-1){
            return grid[i][j]+process(grid,i+1,j);
        }
        return grid[i][j]+Math.min(process(grid,i+1,j),process(grid,i,j+1));
    }
}
```