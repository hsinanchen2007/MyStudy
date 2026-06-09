[-2,1,-3,4,-1,2,1,-5,4]

首先分析 dp [i] 的最大子序列和，我们可以看出dp[i]的值受nums[i - 1]的值影响

当nums[i-1]的值为正数时: dp[i] = dp[i - 1] + nums[i]

当nums[i-1]的值为负数时: 
1.假设当前值为正 dp[i] = dp[i - 1] + nums[i] 
2.假设当前值为负 dp[i] = nums[i] 

以上我们可以得到dp公式
dp[i] = nums [i - 1] > 0 ?  dp [i - 1] + nums[i] : Math.max(dp[i - 1] + nums[i] , nums[i]);

dp值为取该值时的最大子序列和
由此可得代码：
```
        if (nums == null || nums.length == 0) {
            return 0;
        }

        if (nums.length == 1) {
            return nums[0];
        }

        int[] dp = new int[nums.length];
        dp [0] = nums[0];

        int max = dp [0];
        for (int i = 1; i < nums.length; i++) {
            dp[i] = nums [i - 1] > 0 ?  dp [i - 1] + nums[i] : Math.max(dp[i - 1] + nums[i] , nums[i]);
            if (dp[i] > max) {
                max = dp[i];
            }
        }

        return max;
```


再次观察dp公式 可以看出当前dp[i]的值受dp[i - 1]和nums[i - 1]影响 所以dp数组可以改为前缀指针，空间复杂度降低为1 
