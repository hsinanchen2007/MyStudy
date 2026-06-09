### 解题思路
滑动窗口，left、right 分别表示当前窗口的左右边界（左闭右开）

- 如果当前窗口的和小于 target：右移 right
- 如果当前窗口的和大于 target：右移 left
- 如果当前窗口的和等于 target：push 当前窗口的数组，右移 left
- 当 left >= taget/2 时，结束

### 代码

```javascript
/**
 * @param {number} target
 * @return {number[][]}
 */
var findContinuousSequence = function(target) {
    const result = [];
    let left = 1, right = 1, currentSum = 0;
    while (left < target / 2) {
        if (currentSum < target) {
            currentSum += right;
            ++right;
        } else if (currentSum > target) {
            currentSum -= left;
            ++left;
        } else {
            const temp = [];
            for (let i = left; i < right; ++i) {
                temp.push(i);
            }
            result.push(temp);
            currentSum -= left;
            ++left;
        }
    }
    return result;
};
```

### 复杂度
- 时间复杂度 O(N)
- 空间复杂度 O(1)