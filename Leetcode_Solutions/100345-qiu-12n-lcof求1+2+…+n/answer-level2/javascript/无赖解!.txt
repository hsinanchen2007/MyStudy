### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * 直接套用小学学的高斯的数学公式 n(n + 1) / 2 === (n^2 + n) / 2
 * @param {number} n
 * @return {number}
 */
var sumNums = function(n) { 
    // 直接套用高斯的数学公式 n(n + 1) / 2 === (n^2 + n) / 2
    return (Math.pow(n, 2) + n) >> 1
};
```