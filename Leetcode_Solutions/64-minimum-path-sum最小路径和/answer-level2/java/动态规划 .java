### 解题思路
只用一维数组dp存下每一行的值，遍历完一行之后复用dp再遍历下一行，空间复杂度o(N)

### 代码

```java
class Solution {
    public int minPathSum(int[][] grid) {
        if(grid.length==0||grid[0].length==0){
            return 0;
        }
        int m=grid.length,n=grid[0].length;
        int[]dp=new int[n];
        //按行遍历，计算出一行的值存到dp数组，复用dp再遍历下一行
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(j==0){
                    dp[j]=dp[j];//只能从上面走
                }else if(i==0){
                    dp[j]=dp[j-1];//只能从左边来
                }else{
                    dp[j]=Math.min(dp[j],dp[j-1]);
                }
                dp[j]+=grid[i][j];

            }
        }
        return dp[n-1];

    }
}
```