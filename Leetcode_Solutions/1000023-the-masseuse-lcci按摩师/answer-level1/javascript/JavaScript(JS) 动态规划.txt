### 解题思路
DP[i][0]表示不包含第i个元素的最大值，DP[i][1]表示包含第i个元素的最大值。

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var massage = function (nums) {
    if (nums.length <= 2) {
        return Math.max(0, ...nums)
    } else if (nums.length === 3) {
        return Math.max(nums[0] + nums[2], nums[1])
    } else {
        let dp = [[0, nums[0]], [nums[0], nums[1]], [nums[1], nums[0] + nums[2]]];
        for (let i = 3; i < nums.length; i++) {
            dp[i] = [];
            dp[i][0] = dp[i - 1][1];
            dp[i][1] = Math.max(dp[i - 1][0] + nums[i], dp[i - 3][1] + nums[i])
        }
        return Math.max(dp[nums.length - 1][0], dp[nums.length - 1][1])
    }
};
```