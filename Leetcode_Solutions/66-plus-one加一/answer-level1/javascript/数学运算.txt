### 解题思路
从数组的最后一位开始，一次加一，如果有进位的话取 10 的模，用 carry 表示进位 
如果 carry === 0 或者到数组最前一位加一之后停止循环。
如果此时仍有进位，则往数组最前面添加数字 1。

### 代码

```javascript
/**
 * @param {number[]} digits
 * @return {number[]}
 */
var plusOne = function(digits) {
    if (!digits.length || !digits[0]) return [1];
    let carry = 1, currentIndex = digits.length - 1;
    while (carry && currentIndex >= 0) {
        carry = digits[currentIndex] + carry > 9 ? 1 : 0;
        digits[currentIndex] = (digits[currentIndex] + 1) % 10;
        --currentIndex;
    }
    if (currentIndex === -1 && carry) {
        digits.unshift(1);
    }
    return digits;
};
```

### 复杂度
- 时间复杂度 O(N)
- 空间复杂度 O(1)