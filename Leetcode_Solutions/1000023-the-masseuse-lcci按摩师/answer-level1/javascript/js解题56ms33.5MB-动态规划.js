### 解题思路
1. 先读懂题目，题目要求返回最大的总和数，并且不能用相邻的两个元素，也就是取元素隔一个或者多个，只要最后结果最大就行。
2. 这题很容易想到动态规划，如果知道每个子数组的的最大和，那么只要比较当前这个元素加上dp[i-2]是否大于dp[i-1],如果大于那么dp[i]=dp[i-2]+nums[i],小于那么当前的最大和dp[i]=dp[i-1]，遍历完那么就得到了所有得dp,直接返回数组dp的最后一个元素即可。
3. 动态规划的核心就是将原问题分解为一个个子问题，并且能够通过子问题等到结果。

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var massage = function(nums) {
  const len = nums.length
  if (len == 0) return 0
  if (len == 1) return nums[0]
  var dp = new Array(len)
  dp[0] = nums[0]
  dp[1] = Math.max(nums[0], nums[1])
  for (let i = 2; i < len; i++){
    if (dp[i-2] + nums[i] > dp[i-1]) {
      dp[i] = dp[i-2] + nums[i]
    } else {
      dp[i] = dp[i-1]
    }
  }
  return dp[len-1]
};
```