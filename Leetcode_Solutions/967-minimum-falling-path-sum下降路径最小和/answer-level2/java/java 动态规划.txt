```java
class Solution {
    public int minFallingPathSum(int[][] A) {
        int n = A.length;
        int m = A[0].length;
        int i = n-2;
        int[][] dp = new int[2][m];
        int cur = 0, pre = 1;
        for(int j = 0; j < m; j ++) {
            dp[pre][j] = A[n-1][j];
        }
        while(i >=0) {
            for(int j = 0; j < m; j ++) {
                if(j == 0) {
                    dp[cur][j] = A[i][j] + Math.min(dp[pre][j], dp[pre][j+1]);
                } else if(j == m-1) {
                    dp[cur][j] = A[i][j] + Math.min(dp[pre][j], dp[pre][j-1]);
                } else {
                    dp[cur][j] = A[i][j] + Math.min(dp[pre][j], Math.min(dp[pre][j+1],dp[pre][j-1]));
                }
            }
            int temp = cur;
            cur = pre;
            pre = temp;
            i --;
        }
        int min = Integer.MAX_VALUE;
        for(int j = 0; j < m; j ++) {
            if(dp[pre][j] < min)
                min = dp[pre][j];
        }
        return min;
    }
}
```