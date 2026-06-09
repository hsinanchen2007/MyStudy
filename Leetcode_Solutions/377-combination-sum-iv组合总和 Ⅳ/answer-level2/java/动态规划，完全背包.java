因为题目不需要列出所有组合，只需要计算出组合数。因此不需要使用递归来进行搜索。
本题其实可以看做是一个完全背包问题。
关于01背包与完全背包可以参考此处。
[背包问题详解](https://blog.csdn.net/reed1991/article/details/53352426)

此题的状态转移方程为dp[i] = dp[i-nums[0]]+dp[i-nums[1]]+...dp[i-nums[len-1]],条件为i>=nums[j];
dp[0] = 1,dp[0]表示组成0，一个数都不选就可以了，所以dp[0]=1
举个例子。假设nums={1,2,3};  target = 4

dp[4] = dp[4-1]+dp[4-2]+dp[4-3] = dp[3]+dp[2]+dp[1]


dp[1] = dp[0] = 1;
dp[2] = dp[1]+dp[0] = 2;
dp[3] = dp[2]+dp[1]+dp[0] = 4;
dp[4] = dp[4-1]+dp[4-2]+dp[4-3] = dp[3]+dp[2]+dp[1] = 7
代码如下
```
public int combinationSum4(int[] nums, int target) {
        if (nums == null) {
            return 0;
        }
        int[] dp = new int[target + 1];
        //dp[0]表示组成0，一个数都不选就可以了，所以dp[0]=1
        dp[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (int num : nums) {
                if (i >= num) {
                    dp[i] += dp[i - num];
                }
            }

        }
        return dp[target];
    }
```

