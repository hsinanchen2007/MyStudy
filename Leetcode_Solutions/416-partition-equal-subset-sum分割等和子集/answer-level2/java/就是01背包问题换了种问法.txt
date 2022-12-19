这题换种问法：
给定集合A，能否从A中挑选多个数，其和为 sum/2。

如此就转化为标准的01背包问题，有转化式：
dp[i][j] = dp[i-1][j] | dp[i-1][j-num]

使用一维数组进行简化
dp[j] = dp[j] | dp[j-num]
但二层遍历需要从target->j

(注意，二层遍历不能从j->taget，而应该是target->j
前者会后趋依赖前趋，不满足“只使用一次”的约束
而后者后趋不依赖前趋，满足“只使用一次”的约束
例：
1 3 3 5
前者：
对1，dp[1] = 1
根据转化式，dp[2] = dp[2 - 1] = 1,不满足约束

后者：
对6,5...2,1
dp[1] = 1，其余都为0)

代码如下：
```
    public boolean canPartition(int[] nums) {
        if (nums.length <= 1) {
            return false;
        }

        int sum = 0;
        for (int num : nums) {
            sum += num;
        }

        if (sum % 2 != 0) {
            return false;
        }
        int target = sum / 2;

        boolean[] dp = new boolean[target + 1];
        Arrays.sort(nums);

        for (int num : nums) {
            for (int i = target; i >= num; i--) {
                if (i == num || dp[i - num]) {
                    dp[i] = true;
                    if (i == target){
                        return true;
                    }
                }
            }
        }

        return dp[target];
    }
```

