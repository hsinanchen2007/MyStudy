### 解题思路
1. 使用动态规划进行状态转移；
2. 在i位置有两种状态，接（0）或不接（1）；
3. 根据i的状态可推测i-1的状态。

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var massage = function(nums) {
    if (!nums || nums.length <= 0) return 0;

    let dp0 = 0,
        dp1 = nums[0];
    
    for (let i = 1; i < nums.length; i++) {
        let tp0 = Math.max(dp0, dp1),
            tp1 = dp0 + nums[i];
        
        dp0 = tp0;
        dp1 = tp1;
    }

    return Math.max(dp0, dp1);
};
```