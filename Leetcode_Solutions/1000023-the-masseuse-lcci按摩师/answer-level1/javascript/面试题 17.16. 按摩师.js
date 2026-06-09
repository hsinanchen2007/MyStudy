### 解题思路
动态规划

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var massage = function(nums) {
    let len = nums.length
    if(len === 0){
        return 0
    }
    if(len === 1){
        return nums[0]
    }
    if(len === 2){
        return Math.max(...nums)
    }
    let dp = [nums[0], Math.max(nums[0], nums[1])]
    for(let i = 2; i < len; i++){
        dp[i] = Math.max(dp[i - 1], dp[i - 2] + nums[i])
    }
    return dp[len - 1]
};
```