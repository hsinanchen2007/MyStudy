### 解题思路

主要注意一点，在js中所有的按位操作符都会会转换为不骂进行，最后一位为1左移时会溢出，所有需要使用>>>变成无符号整数。

### 代码

```javascript
/**
 * @param {number} n - a positive integer
 * @return {number} - a positive integer
 */
const reverseBits = function(n) {
    let num = 0b0;
    for (let i = 0; i <= 31; i++) {
        num |=  (((n >> (31 - i)) & 1) << i) >>> 0
    }
    return num >>> 0;
};
```