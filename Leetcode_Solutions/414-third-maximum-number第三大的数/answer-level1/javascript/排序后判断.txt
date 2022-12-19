### 代码

```javascript
var thirdMax = function(nums) {
    nums = [...new Set(nums)].sort((a, b) => a - b)
    console.log(nums)
    if (nums.length - 3 >= 0) {
        return nums[nums.length - 3]
    } else {
        return Math.max(...nums)
    }
};
```
时间复杂度：O(n log n)
空间复杂度：O(1)