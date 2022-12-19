### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} n
 * @return {number[]}
 */
var printNumbers = function(n) {
    return Array(Math.pow(10, n) - 1).fill().map((_, index) => index + 1);
};
```