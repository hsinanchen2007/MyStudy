### 解题思路
1. 回文数有倒序和正序相等的特点
2. 借助数组的reverse方法

### 代码

```javascript
/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
    return [...x.toString()].reverse().join('')*1 === x
};
```