### 解题思路
正则先替换所有的非数字字母，转换小写，然后翻转判断

### 代码

```javascript
/**
 * @param {string} s
 * @return {boolean}
 */
var isPalindrome = function(s) {
    const str = s.replace(/[^A-Za-z0-9]+/g,'').toLowerCase()

    return str === str.split('').reverse().join('')
};
```