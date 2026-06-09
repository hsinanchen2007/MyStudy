### 解题思路
状态定义 DP[i]：从头至 i 元素，最长子序列的长度。
状态转移方程 Dp[i] = Max{DP[j]}+1，其中 j:0 至 i-1 且 nums[j]<nums[i] 

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var lengthOfLIS = function (nums) {
    if (!nums.length) return 0
    let state = [1];
    for (let i = 1; i < nums.length; i++) {
        let max = state[0];
        for (let j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                max = Math.max(max, state[j] + 1);
            }
        }
        state[i] = max;
    }
    return Math.max(...state)
};
```