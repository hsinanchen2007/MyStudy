```java
class Solution {
    public int longestArithSeqLength(int[] A) {
        int n = A.length;
        int[][] dp = new int[n][20001];
        int res = 0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                int diff = A[i]-A[j] + 10000;
                dp[i][diff] = Math.max(dp[j][diff]+1,dp[i][diff]);
                res = Math.max(dp[i][diff],res);
            }
        }
        return res+1;
    }
}
```