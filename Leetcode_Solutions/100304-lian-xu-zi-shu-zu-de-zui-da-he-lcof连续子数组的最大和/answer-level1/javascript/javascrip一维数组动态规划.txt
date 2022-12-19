### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function(nums) {
  if (nums.length === 0) {
    return 0;
  }
  // 创建dp数组
  const dp = new Array(nums.length);
  dp[0] = nums[0];
  let max = nums[0];
  let sum = nums[0];
  for (let i = 1; i < dp.length; i++) {
    // 如果当前值加上累计值比当前值大，则把当前值加入累计值
    if (nums[i] + sum > nums[i]) {
      dp[i] = dp[i - 1] + nums[i];
      sum += nums[i];
    } else {
    // 否则，重新设置累计为当前值
      sum = nums[i]
      dp[i] = nums[i];
    }
    max = Math.max(max, dp[i]);
  }
  return max;
};
```