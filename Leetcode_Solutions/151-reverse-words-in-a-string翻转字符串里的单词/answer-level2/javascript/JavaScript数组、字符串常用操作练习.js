### 解题思路
JavaScript数组、字符串常用操作练习

### 代码

```javascript
/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function (s) {
return s.trim().split(/  */).reverse().join(' ')
};

```