### 解题思路
动态规划

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var massage = function(nums) {
    var l = nums.length;
    if (l <= 1) {
        return l == 1 ? nums[0] : 0;
    }
    var dp = new Array(l)
    dp[0] = nums[0]
    dp[1] = Math.max(nums[0], nums[1])
    for (let i = 2; i < l; i++){
        if (dp[i-2] + nums[i] > dp[i-1]) {
        dp[i] = dp[i-2] + nums[i]
        } else {
        dp[i] = dp[i-1]
        }
    }
    return dp[l-1]

};
```