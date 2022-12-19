### 解题思路
动态规划，dp[i]为长度为i的时候的最优解，则nums长度为0和1的时候最优解是确定的，分别为nums[0]和Math.max(nums[0],nums[1]),
对于i=2，对于最后一个预约有两种情况：
1. 选择这个预约，则不能选i-1这个预约，最优解dp[i] = dp[i - 2] + nums[i]
2. 不选这个预约，则这时候最优解dp[i] = dp[i - 1]
真正的最优解选两个之间大的一个即可

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var massage = function(nums) {
    const size = nums.length
    if(!size) return 0
    const dp = [nums[0],Math.max(nums[0],nums[1])]
    for(let i = 2;i < size;i++){
        dp[i] = Math.max(dp[i-2] + nums[i], dp[i-1])
    }
    return dp[size - 1]
};
```