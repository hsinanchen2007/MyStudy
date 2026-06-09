### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function(nums) {
    // 定义子序列的和 sum
    // 定义最大子序列的和 Max
    // Max 默认为num[0]，遍历nums, sum = sum + nums[i]
    // 每次获取新的 sum 就更新 Max
    // 只要遇到 sum < 0，sum 就置 0
    // 最后返回最大子序列和 Max 即可
    let sum = 0
    let Max = nums[0]
    for(let i=0; i<nums.length; i++) {
        sum += nums[i]
        Max = Math.max(Max, sum)
        if(sum < 0) {
            sum = 0
        }
    }
    return Max
};
```