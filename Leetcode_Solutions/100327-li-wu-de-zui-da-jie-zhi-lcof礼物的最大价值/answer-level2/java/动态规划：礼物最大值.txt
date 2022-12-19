思路:定义动态规划数组int[][]dp,数组值表示到达当前位置礼物最大值。
1、dp[i][j] = grid[i][j]+Math.max(dp[i-1][j],dp[i][j-1]);
到达i,j位置最大礼物值等于。grid[i][j]礼物值加上左边或右边元素最大值。
2、边界处理 [0,0]位置直接赋值。
   第一行与第一列分别处理即可。
代码如下所示
```
class Solution {
    public int maxValue(int[][] grid) {
        int r = grid.length;
        int c = grid[0].length;
        int [][] dp = new int[r][c];
        for(int i=0;i<r;i++ ){
            for(int j=0;j<c;j++){
                if(i == 0 && j== 0){
                    dp[i][j]=grid[0][0];
                }else if( i == 0 ){
                    dp[i][j] = grid[i][j]+dp[i][j-1];
                }else if(j == 0 ){
                    dp[i][j] = grid[i][j]+dp[i-1][j];
                }else{
                    dp[i][j] = grid[i][j]+Math.max(dp[i-1][j],dp[i][j-1]);
                }
            }
        } 
        return dp[r-1][c-1];
    }
}

```

