![image.png](https://pic.leetcode-cn.com/bb281442c6083f77bf02caf6903dff2335fb4e4829d359184b7f330d5cb8e4a6-image.png)

### 解题思路
```js
  动态规划：
  
  每次计算当前位置的最大上升子序列的时候，要把前面的动规点遍历一遍，找到最大的那个点 + 1
  更新为当前点的值
  
  dp[i] 记录：当前点之前的这小段数组中最长的子序列

  ! 推荐看官方的 ppt 演示，过程很清晰
```

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */

var lengthOfLIS = function(nums) {
  let dp = [], n = nums.length, ans = 0;
  
  if (n === 0) return 0;
  if (n === 1) return 1;
  
  dp[0] = 1;
  for (let i = 1; i < n; i++) {
    let max = 0;
    for (let j = 0; j < i; j++) {
      if (nums[i] > nums[j]) {
        max = Math.max(dp[j] + 1, max);
      } else {
        max = Math.max(max, 1);
      }
    }
    dp[i] = max;
    ans = Math.max(dp[i], ans);
  }
  
  return ans;
};
```