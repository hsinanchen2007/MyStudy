### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var massage = function(nums) {
    if (nums.length === 0) {
        return 0;
    }
    const dp = new Array(nums.length + 1);
    dp[0] = 0;
    dp[1] = nums[0];
    let max = Number.MIN_SAFE_INTEGER;
    for (let i = 2; i < dp.length; i++) {
        dp[i] = Math.max(dp[i - 1], nums[i - 1] + dp[i - 2]);
    }
    return dp[nums.length];
};
```