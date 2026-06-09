先看带有注释的代码：
```java
class Solution {
    // 动态回归
    // 状态定义：dp[i][j] 表示不戳破 i 与 j ，仅戳破 i 与 j 之间的气球我们能得到的最大金币数
    // 状态转移方程：
    //  dp[i][j] = max {dp[i][k] + dp[k][j] + nums[i]*nums[k]*nums[j]} | i < k < j
    //  上面方程中的 nums[i]*nums[k]*nums[j] 表示戳破气球 k 时能得到的金币数
    // 我们可以对上面的方程进行推演下，比如我们要求 dp[i][i + 2]：
    //  dp[i][i + 2] = dp[i][i + 1] + dp[i + 1][i + 2] + nums[i]*nums[i + 1]*nums[i + 2]
    //  其中 dp[i][i + 1] 和 dp[i + 1][i + 2] 都是返回 0，
    //  因为 i 到 i + 1 和 i + 1 到 i + 2 之间都没有气球，
    //  而我们对 dp[i][j] 的定义是不戳破 i 与 j ，仅戳破 i 与 j 之间的气球我们能得到的最大金币数
    // 所以说  dp[i][i + 2] = nums[i]*nums[i + 1]*nums[i + 2]，其实就是等于戳破 i + 1 获得的金币
    public int maxCoins(int[] nums) {
        if (nums == null || nums.length == 0) return 0;
        // 加虚拟边界 nums[-1] = nums[nums.length] = 1;
        int[] numsTemp = new int[nums.length + 2];
        for (int i = 1; i <= nums.length; i++) numsTemp[i] = nums[i - 1];
        numsTemp[0] = 1;
        numsTemp[nums.length + 1] = 1;

        // 创建 dp 数组，并且 dp 数组中的每个元素都初始化成 0
        int length = numsTemp.length;
        int[][] dp = new int[length][length];

        // 状态转移方程(计算不戳破 i 与 j ，仅戳破 i 与 j 之间的气球我们能得到的最大金币数)：
        //  dp[i][j] = max {dp[i][k] + dp[k][j] + nums[i]*nums[k]*nums[j]} | i < k < j
        // 这里 i 为什么是递减，而 j 为什么是递增，请看代码下的解释说明
        for (int i = length - 2; i >= 0; i--) {
            // 这里 +2 的原因：保证 (i, j) 之间肯定 1 个元素，因为没有元素的话，dp[i][j] 就等于 0
            for (int j = i + 2; j < length; j++) {
                int max = 0;
                // 计算戳破 k 气球得到的最大金币数
                for (int k = i + 1; k < j; k++) {
                    // 注意：使用增加了虚拟边界的数组 numsTemp
                    int temp = dp[i][k] + dp[k][j] + numsTemp[i] * numsTemp[k] * numsTemp[j];
                    if (temp > max) max = temp;
                }
                // 记录状态值
                dp[i][j] = max;
            }
        }

        // 返回最终获得的最大硬币数
        // 当然是：计算不戳破 0 与 length - 1 ，仅戳破 0 与 length - 1 之间的气球我们能得到的最大金币数
        // 因为前面我们对原数组 nums 增加了虚拟边界，所以返回 dp[0][length - 1] 就是返回最终获得的最大硬币数
        return dp[0][length - 1];
    }
}
```

解释说明如下：

