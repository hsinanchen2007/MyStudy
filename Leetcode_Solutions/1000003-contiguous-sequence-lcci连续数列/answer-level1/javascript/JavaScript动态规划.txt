### 解题思路
创建一个dp数组，里面保存着所有dp[i]的最大子序列和，dp[i]的意思是以nums[i]为结束点的最大子序列和，例如dp[3]的值为 [-2, 1, -3]的最大子序列和，为 -3 + 1 = -2

### 代码

```javascript
var maxSubArray = function(nums) {
  const dp = new Array(nums.length)
  dp[0] = nums[0]
  dp[1] = nums[0]
  for (let i = 2, len = nums.length; i <= len; i++) {
    dp[i] = Math.max(nums[i - 1], dp[i - 1] + nums[i - 1])
  }
  return Math.max(...dp)
};
```