### 解题思路
特殊需要注意的是999这类会增加数组长度的

### 代码

```javascript
/**
 * @param {number[]} digits
 * @return {number[]}
 */
var plusOne = function (digits) {
    for (let i = digits.length - 1; i >= 0; i--) {
        if (digits[i] === 9) {
            digits[i] = 0
            if (i === 0) {
                digits.unshift(1)
                break
            }
        }
        else {
            digits[i]++
            break
        }
    }
    return digits
};
```