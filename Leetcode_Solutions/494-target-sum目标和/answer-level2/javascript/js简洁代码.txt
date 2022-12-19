[参考这位的题解](https://leetcode-cn.com/problems/target-sum/solution/js-dong-tai-gui-hua-by-stack_pop-3/)

主要是js中对象的属性名是string，我们可以用双非转化为string为number。
**题目中：保证返回的最终结果能被32位整数存下**。是我们使用的条件，不然会超限



```javascript []
/**
 * @param {number[]} nums
 * @param {number} S
 * @return {number}
 */
var findTargetSumWays = function(nums, S) {
  let dp = Array.from({ length: nums.length }, _ => new Object())
  if (nums[0] === 0) {
    dp[0][0] = 2
  } else {
    dp[0][nums[0]] = 1
    dp[0][-nums[0]] = 1
  }
  for (let i = 1; i < nums.length; i++) {
    for (let key in dp[i - 1]) {
      dp[i][~~key + nums[i]] = (dp[i][~~key + nums[i]] || 0) + dp[i - 1][key]
      dp[i][~~key - nums[i]] = (dp[i][~~key - nums[i]] || 0) + dp[i - 1][key]
    }
  }
  return dp[nums.length - 1][S] || 0
}
```
