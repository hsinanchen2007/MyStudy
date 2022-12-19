dp[i][j]表示以arr[i]结尾的，已经删除j次的子数组最大值
- 递推关系：
dp[i][j] = Math.max(dp[i - 1][j] + arr[i],dp[i - 1][j - 1]);
- 面临两种情况：
1. 不删除arr[i]， dp[i - 1][j]
2. 删除arr[i]，dp[i - 1][j - 1]

```
class Solution {
    public int maximumSum(int[] arr) {
        int n = arr.length;
        int k = 1;
        int max = arr[0];
        int[][] dp = new int[n][k + 1];
        //init
        dp[0][0] = arr[0];
        for(int i = 1; i < n; i++){
            dp[i][0] = Math.max(dp[i - 1][0] + arr[i],arr[i]);
            max = Math.max(max,dp[i][0]);
        }
        //dp
        for(int i = 1; i < n; i++){
            for(int j = 1; j <= k; j++){
                dp[i][j] = Math.max(dp[i - 1][j] + arr[i],dp[i - 1][j - 1]);
                max = Math.max(max,dp[i][j]);
            }
        }
        
        return max;
    }
}
```
