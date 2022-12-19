```
/**
 * @param {number[]} nums
 * @return {number}
 */
var lengthOfLIS = function(nums) {
    const len = nums.length;
    if(!len) return 0;
    const dp = [];
    dp[0] = 1;
    let max = 1;
    for(let i = 1; i < len; i++) {
        dp[i] = 1;
        for(let j = 0; j < i; j++) {
            if (nums[i] > nums[j]) dp[i] = Math.max(dp[i], dp[j] + 1);
            else if (nums[i] === nums[j]) dp[i] =  Math.max(dp[i], dp[j]);
        }
        max = Math.max(max, dp[i]);
    }
    return max;
};
```
