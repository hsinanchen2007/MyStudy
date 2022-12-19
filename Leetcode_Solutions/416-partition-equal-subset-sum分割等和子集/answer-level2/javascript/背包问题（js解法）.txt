```
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var canPartition = function(nums) {
 // 本质是一个求容量为sum / 2的背包问题，如果正好可以填满背包，返回true
  const sum = nums.reduce((a, b) => a + b)
  const len = nums.length
  if (sum % 2 || len < 2) {
      return false
  }
  const half = sum / 2
  // 背包
  const res = []
  for (let i = 0; i < half + 1; i++) {
    res[i] = nums[0] <= i ? nums[0] : 0
  }
  for (let i = 1; i < len; i++) {
    for (let j = half; j >= nums[i]; j--) {
        // 更新不同容量下放入的数字最大和        
        res[j] = Math.max(res[j], nums[i] + res[j - nums[i]])
    }
  }
  // 背包容量恰好填满时候返回true
  return res[half] === half
};
```
