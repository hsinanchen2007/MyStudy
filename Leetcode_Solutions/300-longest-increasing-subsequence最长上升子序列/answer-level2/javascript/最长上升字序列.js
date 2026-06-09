### 解题思路
动态规划

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
const lengthOfLIS = (nums)=> {
  const dp = Array(nums.length).fill(1);
  for(let i = 0; i < nums.length; i += 1){
    for(let j = 0; j < i; j += 1){
      if(nums[i]>nums[j]){
        dp[i] = Math.max(dp[i], dp[j]+1);
      }
    }
  }
  dp.sort((a,b)=> b - a);
  return dp[0] || 0;
};
```