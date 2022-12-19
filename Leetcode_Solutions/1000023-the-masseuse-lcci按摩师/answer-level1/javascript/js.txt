```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var massage = function(nums) {
    if (nums.length <= 2) {
        return Math.max(...nums, 0);
    }

    if (nums.length === 3) {
        return Math.max(nums[0] + nums[2], nums[1]);
    }

    let dp = [nums[0], nums[1], nums[0] + nums[2]];

    for (let i = 3; i < nums.length; i++) {
        let cur = Math.max(dp[0] + nums[i], dp[1] + nums[i], dp[2]);
        dp = [dp[1], dp[2], cur];
    }
    return Math.max(...dp);
};
```