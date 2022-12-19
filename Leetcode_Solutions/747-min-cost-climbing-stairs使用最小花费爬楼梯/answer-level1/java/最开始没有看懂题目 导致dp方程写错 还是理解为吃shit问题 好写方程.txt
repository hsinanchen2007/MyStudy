吃shit的起点有2个 从index 0开始吃和从index 1开始吃，所以dp的base case是 dp[0] = cost[0], dp[1] = cost[1],
又因为得吃完shit 所以我们得走到数组的下一位，所以循环时 数组length+1 当走到数组的下一位的及阶梯走完的时候，有2种方式及i-1和i -2 跳跃而来，这个时候拿到最小值即可，原始dp 代码
```
        if (cost == null || cost.length == 0) {
            return 0;
        }

        if (cost.length == 1) {
            return cost[0];
        }

        int[] dp = new int[cost.length + 1];
        dp[0] = cost[0];
        dp[1] = cost[1];

        for (int i = 2; i < cost.length + 1; i++) {
            if (i == cost.length) {
                dp[i] = Math.min(dp [i - 1], dp [i - 2]);
                continue;
            }

            dp[i] = Math.min(dp[i - 2], dp [i - 1]) + cost[i];
        }

        return dp[cost.length];
```

当然有优化空间 就是当前状态只受 i-1和i-2吃的shit量控制 所以dp数组可以换为2个变量即可