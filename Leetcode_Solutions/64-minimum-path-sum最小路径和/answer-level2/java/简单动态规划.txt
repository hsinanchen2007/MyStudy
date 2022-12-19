### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    //最小路径和
    public int minPathSum(int[][] grid) {
        int m = grid.length ;    //行
        int n = grid[0].length ; //列
        int  [][]  dp = new int[m][n];

        for(int i = 0 ;i< m; i++ ){
            for(int j = 0; j<n;j++){
                dp[i][j] = Integer.MAX_VALUE ;
            }
        }
        //边界 初始值
        dp[0][0] = grid[0][0] ;
        //状态转移方程
        for(int i = 0 ;i< m; i++ ){
            for(int j = 0; j<n;j++){
                //  不是最上面一行  上->下
                if(i>0 )  dp[i][j] = Math.min(dp[i][j],  dp[i-1][j]+grid[i][j] );
                //不是最左边一列  左->右
                if(j>0 )  dp[i][j] = Math.min(dp[i][j],  dp[i][j-1]+grid[i][j] );
            }
        }
        return dp[m-1][n-1];
    }
}
```