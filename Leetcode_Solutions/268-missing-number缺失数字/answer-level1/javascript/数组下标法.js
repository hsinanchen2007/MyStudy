### 解法一：

```javascript
var missingNumber = function(nums) {
    for (let i = 0; ; i++) {
        if (nums.indexOf(i) === -1) {
            return i
        }
    }
};
```
时间复杂度：O(n^2)
空间复杂度：O(1)

### 解法二：


```javascript
var missingNumber = function(nums) {
    nums.sort((a, b) => a - b).filter(item => item >= 0)
    if (nums[0] === 0) {
        for (let i = 0; i < nums.length; i++) {
            if (nums[i] - nums[i - 1] > 1) {
                return nums[i - 1] + 1
            }
        }
        return nums.pop() + 1
    } else {
        return 0
    }
};
```
时间复杂度：O(n log n)
空间复杂度：O(1)