![Snipaste_2020-03-19_18-39-36.png](https://pic.leetcode-cn.com/37aa30260a3fb79d16c35d387a3856e040a4cf9b440131653280dc7b856fb805-Snipaste_2020-03-19_18-39-36.png)

### 解题思路
状态定义：DP[i]，包含 nums[i] 和的最大值，转移方程为 DP[i] = Max{DP[i-1]+nums[i],nums[i]}

### 代码

```javascript
var maxSubArray = function (nums) {
    if (!nums.length) return null
    let max = nums[0], record = nums[0];
    for (let i = 1; i < nums.length; i++) {
        record = Math.max(record + nums[i], nums[i]);
        if (record > max) max = record;
    }
    return max
};
```