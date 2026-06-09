### 解题思路
  很常规的动态规划题，关键是还是找到状态的变化，我采用的是自底向上的dp表，讲一下思路。
  首先，我们会很容易发现天与天之间的数据是有关联的，所以将day作为dp的第一维，dp[i]代表的是到第i天为止的最小任务难度，这里有一个细节，一般动态规划的dp表里保存的都会是题目要求的数据，这道题要求最小难度，所以很自然的会将最小难度存放在dp表中。
  但是，这时我们会发现，一维的数组不能够满足所有状态的变化，我们并不知道第i天到底完成了几个任务，所以很自然的又引入第二个状态，使用二维数组dp[i][j]代表到第i天为止完成了第j个任务能够消耗的最小难度，到这里其实就差不多了，股票系列的题目告诉我们其实动态规划就是状态的遍历，只要能把所有的状态全部遍历，结果自然就出来了。
  最后，我们发现还有一个状态没有表示出来，那就是我们不知道当第i天完成第j个任务时，前一天的进度是多少，前一天有可能完成了j - 1个，也有可能完成了j - 2个任务，要解决这个问题，我们可以选择引入这个状态，使用三维dp，dp[i][j][k]代表到第i天为止完成了j个任务，同时前一天的进度是k，或者也可以直接遍历k，k的取值范围是i - 1 <= k < j;状态转移方程就是dp[i][j] = Min(dp[i - 1][k], (遍历k)Max(jobDifficulty[k + 1],.....,jobDifficulty[j]));

### 代码

```java
class Solution {
    public int minDifficulty(int[] jobDifficulty, int d) {
        int len = jobDifficulty.length;
        if (len == 0) return 0;
        if (d == 0) return -1;
        int[][] dp = new int[d][len];
        int maxt = jobDifficulty[0];
        for (int i = 0; i < len; i++) {
            maxt = Math.max(jobDifficulty[i], maxt);
            dp[0][i] = maxt;
        }
        for (int i = 1; i < d; i++) {
            for (int j = i; j < len; j++) {
                int minD = dp[i - 1][j - 1] + jobDifficulty[j];
                int maxJ = 0;
                for (int k = j - 1; k >= i - 1; k--) {
                    maxJ = Math.max(jobDifficulty[k + 1], maxJ);
                    minD = Math.min(dp[i - 1][k] + maxJ, minD);
                }
                dp[i][j] = minD;
            }
        }
        if (dp[d - 1][len - 1] == 0) return -1;
        return dp[d - 1][len - 1];
    }
}
```