一开始用的如下递归解法，超时了
其中dp[n][k] 表示在n层楼 用k个鸡蛋，所需要的最小操作次数

用的是minMax思路 
```java
class Solution {
    int[][] dp;
    int K;
    int N;
    public int superEggDrop(int K, int N) {
        this.K = K;
        this.N = N;
        this.dp = new int[N + 1][K + 1];
        return helper(N, K);
    }

    int helper(int N, int K) {
        if (N == 0) return 0;
        if (K == 1) return N;
        if (dp[N][K] > 0) return dp[N][K];
        int res = Integer.MAX_VALUE;
        for (int i = 1; i <= N; i ++) {
            res = Math.min(res, 1 + Math.max(helper(i - 1, K - 1), helper(N - i, K)));
        }
        dp[N][K] = res;
        return res;
    }
}
```

下面是不超时的解法
这里的dp[n][k] 表示，用n次操作和k个鸡蛋所能达到的最大层数，当层数超过题目要求，就返回n

```java
class Solution {
    int[][] dp;
    int K;
    int N;
    public int superEggDrop(int K, int N) {
        dp = new int[N + 1][K + 1];
        int m = 0;
        while(dp[m][K] < N) {
            m++;
            for (int k = 1; k <= K; k++) {
                dp[m][k] = dp[m - 1][k - 1] + dp[m - 1][k] + 1;
            }
        }
        return m;
    }
}
```
