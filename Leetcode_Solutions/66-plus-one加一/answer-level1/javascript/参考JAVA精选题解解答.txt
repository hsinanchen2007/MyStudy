### 解题思路
1. 逆向循环
2. 判断最后一位数+1
    - 等于10，则进一位
    - 不超过10则为普通情况，直接返回
3. 循环中整体都发生进一位的情况，则需要在头尾追加1和0

### 代码

```javascript
/**
 * @param {number[]} digits
 * @return {number[]}
 */
var plusOne = function(digits) {
    for (let i = digits.length - 1; i >= 0; i--) {
        digits[i]++;
        digits[i] = digits[i] % 10;
        if (digits[i] !== 0) {
            return digits
        }
    }
    digits[0] = 1;
    digits.push(0);
    return digits
};
```