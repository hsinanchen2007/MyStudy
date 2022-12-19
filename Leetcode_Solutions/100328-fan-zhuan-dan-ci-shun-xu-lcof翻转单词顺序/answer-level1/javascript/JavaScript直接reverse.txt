### 解题思路

直接reverse

### 代码

```javascript
/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
    const arr = s.split(' ').filter(item => item !== ' ' && item !== '')
    return arr.reverse().join(' ')
};
```