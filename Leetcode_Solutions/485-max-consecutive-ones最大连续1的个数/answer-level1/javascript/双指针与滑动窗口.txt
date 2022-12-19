### 代码

```javascript
var findMaxConsecutiveOnes = function(nums) {
    let left = 0,
       right = 0
    let count = 0
    while (right < nums.length) {
        if (nums[right] === 1) {
            right++
        } else {
            right++
            left = right
        }
        let temp = nums.slice(left, right)
        count = Math.max(count, temp.length)
        temp = []
    }
    return count
};
```
时间复杂度：O(n)
空间复杂度：O(n)