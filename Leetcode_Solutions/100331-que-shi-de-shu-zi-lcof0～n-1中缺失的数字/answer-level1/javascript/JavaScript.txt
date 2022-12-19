### 解题思路

控制好头和尾即可

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var missingNumber = function(nums) {
    if (nums[0] !== 0) return 0
    const length = nums.length
    for (let i = 0; i < length -1; i++) {
        if (nums[i + 1] - nums[i] === 2) return nums[i] + 1
    }
    return nums[length - 1] + 1
};
```