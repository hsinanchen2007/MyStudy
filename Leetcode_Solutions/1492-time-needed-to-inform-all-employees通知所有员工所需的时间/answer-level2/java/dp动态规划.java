动态规划，代码没几行。耗时12ms，空间56.8m

```java
class Solution {
    
    public int numOfMinutes(int n, int headID, int[] manager, int[] informTime) {
        int[] dp = new int[manager.length];
        Arrays.fill(dp, -1);
        dp[headID] = 0;
        int max = 0;
        for (int i = 0; i < manager.length; i++) {
            resolve(i, dp, manager, informTime);
            if (dp[i] > max) {
                max = dp[i];
            }
        }
        return max;
    }
    
    private void resolve(int i, int[] dp, int[] manager, int[] informTime) {
        if (dp[i] != -1) {
            return;
        }

        int mgr = manager[i];
        
        if (dp[mgr] == -1) {
            resolve(mgr, dp, manager, informTime);
        }

        dp[i] = informTime[mgr] + dp[mgr];
    }
}

```