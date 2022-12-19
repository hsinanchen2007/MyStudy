```
class Solution {
    public int jump(int[] nums) {
        // 定义一个数组，用于记录每个位置对应的可到达最后一个位置（目标位置）的最少步数，
        // 比如dp[3] = 4，表示nums[3]这个位置的值到达最后一个位置（目标位置），最少需要4步。
        int[] dp = new int[nums.length];
        // 最后一个位置（目标位置）不需要再移动了，记为0步
        dp[nums.length - 1] = 0;
        // 从最后一个位置（目标位置）的上一步开始循环，只有这个起点开始才有意义
        for (int i = nums.length - 2; i >= 0; i --) {
            // 判断如果当前位置的可跳跃的长度足以到达目标位置，那么它的最少步数就是1步
            if (nums[i] >= nums.length - 1 - i) {
                dp[i] = 1;
            } else {
                // 如果1步到不了目标位置，我们来看这个位置可以跳跃到哪几个位置（1 ~ nums[i]），从可跳跃到的位置中，找出到目标位置最少步数的那个
                int nextMin = i + 1;
                for (int j = 1; j <= nums[i]; j ++) {
                    // 从可跳跃到的位置中，找出到目标位置最少步数的那个
                    if (i + j < nums.length - 1 && dp[i + j] < dp[nextMin]) {
                        nextMin = i + j;
                    }
                }
                // 那么当前的最少步数就是那个后面最少步数的位置 + 1步
                dp[i] = dp[nextMin] + 1;
            }
        }
        // 题目是问我们从0位置开始跳的最少步数，所以返回dp[0]
        return dp[0];
    }
}
```
