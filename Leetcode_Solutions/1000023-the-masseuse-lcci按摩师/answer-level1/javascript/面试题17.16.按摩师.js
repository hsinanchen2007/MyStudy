### 解题思路
典型的动态规划题目
dp[i]表示到第i(假设数组下标从1开始)个请求时的最长分钟数
如果按摩师接了第i-1个请求，则第i个请求不能接，此时dp[i] = dp[i-1]
如果按摩师没接第i-1个请求，则第i个请求可以接，此时dp[i] = dp[i-2] + nums[i]
综上，dp[i]的最终取值应该是Math.max(dp[i-1], dp[i-2]+nums[i]);

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var massage = function(nums) {
    if(nums.length === 0) return 0;
    if(nums.length === 1) return nums[0];
    if(nums.length === 2) return nums[0]>nums[1]?nums[0]:nums[1];
    let dp = new Array(nums.length);
    dp[0] = nums[0];
    dp[1] = Math.max(nums[0], nums[1]);
    for(let i=2;i<nums.length;i++){
        dp[i] = Math.max(dp[i-2]+nums[i], dp[i-1]);
    }
    return dp[nums.length-1];
};
```