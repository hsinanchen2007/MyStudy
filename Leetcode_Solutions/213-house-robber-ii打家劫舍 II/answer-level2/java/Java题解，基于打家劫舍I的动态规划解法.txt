先贴一下打家劫舍I的解法：
```
public int rob(int[] nums) {
    int n = nums.length;
    if (nums.length == 0) {
        return 0;
    }
    if (nums.length == 1) {
        return nums[0];
    }

    int[][] dp = new int[n][2];
    dp[0][0] = 0;
    dp[0][1] = nums[0];
    int maxRob = nums[0];
    for (int i = 1; i < n; i++) {
        dp[i][0] = Math.max(dp[i-1][1], dp[i-1][0]);
        dp[i][1] = dp[i-1][0] + nums[i];
        if (dp[i][1] > maxRob) {
            maxRob = dp[i][1];
        }
    }

    return maxRob;
}
```

本题的解法分为2种情况求解：
- 第一种情况：第一间打劫，最后一天不打劫(也就是不用考虑最后一间房屋)
- 第二种情况：第一间不打劫，最后一天打劫或者不打劫

相比较打家劫舍I只是多考虑一些情况，核心的推算逻辑都是一致的，代码如下：

**dp[i][0]: 表示第i天不打劫; dp[i][1]: 表示第i天打劫**
```
public int rob(int[] nums) {
    int n = nums.length;
    // 没有房屋, 直接返回0
    if (nums.length == 0) {
    return 0;
    }
    // 只有一间房屋, 返回该房屋现金
    if (nums.length == 1) {
    return nums[0];
    }

    // 情况1：第一间打劫
    int[][] dp = new int[n][2];
    dp[0][1] = nums[0]; // base case, 第一间打劫
    dp[1][0] = dp[0][1]; // base case, 第二间只能不打劫
    int maxRob = nums[0];
    // 第三间开始循环推算
    for (int i = 2; i < n - 1; i++) {
    // 第i间不打劫 = Max(第i-1间打劫, 第i-1间不打劫)
    dp[i][0] = Math.max(dp[i - 1][1], dp[i - 1][0]);
    // 第i间打劫 = 第i-1间不打劫 + 第i间打劫
    dp[i][1] = dp[i - 1][0] + nums[i];
    if (dp[i][1] > maxRob) {
        // 记录过程中最大值
        maxRob = dp[i][1];
    }
    }

    // 情况2：第一间不打劫(这种情况不用设置base case)
    dp = new int[n][2];
    for (int i = 1; i < n; i++) {
    // 第i间不打劫 = Max(第i-1间打劫, 第i-1间不打劫)
    dp[i][0] = Math.max(dp[i - 1][1], dp[i - 1][0]);
    // 第i间打劫 = 第i-1间不打劫 + 第i间打劫
    dp[i][1] = dp[i - 1][0] + nums[i];
    if (dp[i][1] > maxRob) {
        // 记录过程中最大值
        maxRob = dp[i][1];
    }
    }

    return maxRob;
}
```

**代码运行通过，如有理解错误的地方，还望大神指出，谢谢！**

