```
class Solution {
    public int maxValue(int[][] grid) {
        if(grid==null||grid.length==0||grid[0].length==0){
            return 0;
        }
        int n=grid[0].length;
        int [] dp=new int[n];
        for(int [] value:grid){
            dp[0]+=value[0];
            for(int i=1;i<n;i++){
                dp[i]=Math.max(dp[i-1],dp[i])+value[i];
            }
        }
        return dp[n-1];
    }
}
```
