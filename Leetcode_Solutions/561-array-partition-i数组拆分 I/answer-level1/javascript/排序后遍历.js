### 代码

```javascript
var arrayPairSum = function(nums) {
    nums.sort((a, b) => a - b)
    let sum = 0
    for (let i = 0; i < nums.length; i+=2) {
        sum += nums[i]
    }
    return sum
};
```
时间复杂度：O(n log n)
空间复杂度：O(1)