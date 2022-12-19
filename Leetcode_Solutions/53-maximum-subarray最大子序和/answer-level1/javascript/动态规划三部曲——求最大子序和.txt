### 解题思路
(1)dp[i]：到i处（包含i）的最大子序和
(2)关系式: 如果dp[i-1]<0，只计算nums[i]，如果dp[i-1]>=0，加上。
     dp[i]=max(dp[i-1],0)+nums[i]
(3)初始值：dp[0]=nums[0]
最后返回的最大和为dp[0]...dp[n]中的最大值。

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 * (1)dp[i]：到i处（包含i）的最大子序和
 * (2)关系式: 如果dp[i-1]<0，只计算nums[i]，如果dp[i-1]>=0，加上。
 *      dp[i]=max(dp[i-1],0)+nums[i]
 * (3)初始值：dp[0]=nums[0]
 * 最后返回的最大和为dp[0]...dp[n]中的最大值。
 */
var maxSubArray = function (nums) {
    if (!nums || nums.length === 0) {
        return 0
    }
    let n = nums.length
    let dp = new Array(n)
    // 初始化
    dp[0] = nums[0]
    max = nums[0]
    // 关系式
    for (let i = 1; i < n; i++) {
        dp[i] = Math.max(dp[i - 1], 0) + nums[i]
        max = Math.max(max, dp[i])
    }
    return max
};
```