### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var lengthOfLIS = function(nums) {
    // 动态规划
    if (nums.length === 0 ) {
        return 0;
    }
    let dp = [1];
    let max = 1;
    for (let i=1; i< nums.length; i++) {
        let maxForI = 0;
        for (let j=0; j < i; j++) {
            if (nums[j] < nums[i]) {
                maxForI = Math.max(dp[j], maxForI);
            }
        }
        dp[i] = maxForI + 1;
        max = Math.max(max, dp[i]);
    }
    return max;
};
```