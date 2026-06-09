# 213. 打家劫舍 II

## 题意

与版本1的区别：变为循环数组。本质思路是相同的。

## 思路

变成环形数组，其实只增加了一个限制/条件，就是头尾相邻，即不能同时偷`nums[0]`和`nums[n-1]`。所以我们可以进行两次遍历：

1. 遍历`nums[0 ~ n-2]`，表示考虑`nums[0]`而不考虑`nums[n-1]`
1. 遍历`nums[1 ~ n-1]`，表示考虑`nums[n-1]`而不考虑`nums[0]`

最后取更大者就行了。

另外，需要注意`n === 1`的情况，可能需要单独处理。

与198在本质上相同，所以可以直接沿用198的代码。这里提供198的其中一种思路：

```js
var rob = function (nums) {
  const n = nums.length;
  if (n === 1) return nums[0];
  return Math.max(
    robbing(nums.slice(0, n - 1)),
    robbing(nums.slice(1, n))
  );
};

// LeetCode 198
function robbing(nums) {
  const n = nums.length;
  // 状态：dp[i]表示经历前i个房子能获取的最大价值
  const dp = Array.from({ length: n + 1 }, () => 0);
  // 迭代
  for (let i = 1; i <= n; ++i) {
    dp[i] = Math.max(
      dp[i - 1], // 不偷i
      nums[i - 1] + (i - 2 >= 0 ? dp[i - 2] : 0) // 偷i
    );
  }
  // 目标
  return dp[n];
};
```
