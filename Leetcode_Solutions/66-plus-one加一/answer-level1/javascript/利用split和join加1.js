### 解题思路
先转换成大整数+1后转换成string后再拆成数组即可

### 代码

```javascript
/**
 * @param {number[]} digits
 * @return {number[]}
 */
var plusOne = function(digits) {
    const digit = BigInt((BigInt(digits.join('')) + 1n)).toString()
    return digit.split('')
};
```