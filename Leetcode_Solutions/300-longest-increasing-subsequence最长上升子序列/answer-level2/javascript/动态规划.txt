### 解题思路
动态规划，用 dp[i] 表示以 nums[i] 为结尾的最长上升子序列的长度（必须包含 nums[i]）。

对于 j < i，如果 nums[j] < nums[i]，则更新 dp[i] 为 Math.max(dp[i], dp[j]+1);


### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var lengthOfLIS = function(nums) {
    const dp = new Array(nums.length);
    let res = 0;
    for (let i = 0; i < nums.length; ++i) {
        dp[i] = 1;
        for (let j = 0; j < i; ++j) {
            if (nums[j] < nums[i]) {
                dp[i] = Math.max(dp[i], dp[j]+1);
            }
        }
        res = Math.max(res, dp[i]);
    }
    return res;
};
```

### 复杂度
- 时间复杂度 O(N^2)
- 空间复杂度 O(N)