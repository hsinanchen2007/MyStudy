### 解题思路

双指针速度快
执行用时64 ms, 在所有 JavaScript 提交中击败了84.83%的用户
内存消耗 :33.9 MB, 在所有 JavaScript 提交中击败了100.00%的用户

### 代码

```javascript
/**
 * @param {number[]} numbers
 * @return {number}
 */
var minArray = function(numbers) {
    let left = 0, right = numbers.length
    while (left < right) {
        if (numbers[left] > numbers[left + 1]) {
            return numbers[left + 1]
        }
        if (numbers[right] < numbers[right - 1]) {
            return numbers[right]
        }
        left++
        right--
    }
    return numbers[0]
};
```