在原有的动态规划的思路上发现数组没有必要开二维，只需要逆序遍历工作即可。

```java

class Solution {
    public int minDifficulty(int[] jobDifficulty, int d) {
        if(jobDifficulty.length<d) {
            return -1;
        }
        int[] dp = new int[jobDifficulty.length];
        dp[0] = jobDifficulty[0];
        for(int i=1;i<jobDifficulty.length;i++) {
            dp[i] = Math.max(jobDifficulty[i],dp[i-1]);
        }
        for(int i=1;i<d;i++) {
            for(int j=jobDifficulty.length-1;j>=i;j--) {
                int most = jobDifficulty[j];
                dp[j] = Integer.MAX_VALUE;
                for(int k=j;k>=i;k--) {
                    most = Math.max(most,jobDifficulty[k]);
                    dp[j] = Math.min(dp[j],dp[k-1]+most);
                }
            }
        }
        return dp[jobDifficulty.length-1];
    }
}

```