### 解题思路
看了官方的思路，遍历数组，依次找出第i个元素的最长上升子序列，第二个for循环的目的是将第i个元素与它之前元素的的已找出的所有最长子序列比比较，并在它的基础上加1，这样就是当前的元素的最长子序列，max就是不断去找出截止到第i个元素时的最长子序列。

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var lengthOfLIS = function(nums) {
    if (nums.length === 1) return 1;
    let max = 0;
    const dp = new Array(nums.length);
    dp[0] = 1;
    for (let i = 1; i < dp.length; i++) {
        let val = 0;
        for (let j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                val = Math.max(val, dp[j]);
            }
        }
        dp[i] = val + 1;
        max = Math.max(max, dp[i]);
    }
    return max;
};
```