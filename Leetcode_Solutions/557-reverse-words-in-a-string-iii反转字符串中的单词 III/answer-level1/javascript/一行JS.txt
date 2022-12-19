### 解题思路
主要是一开始忘了forEach()和map()的区别（forEach()没有返回值，数组只是相当于参数传了进去，而map()可以返回值），用了forEach()，用了map()就没什么难度了。

### 代码

```javascript
/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
    return s.split(' ').map(a=>a.split('').reverse().join('')).join(' ');
};
```