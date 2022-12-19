### 代码

```javascript
var moveZeroes = function(nums) {
    let pointer = 0
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] !== 0) {
            [nums[pointer], nums[i]] = [nums[i], nums[pointer]]
            pointer++
        }
    }
    return nums
};
```
时间复杂度：O(n)
空间复杂度：O(1)