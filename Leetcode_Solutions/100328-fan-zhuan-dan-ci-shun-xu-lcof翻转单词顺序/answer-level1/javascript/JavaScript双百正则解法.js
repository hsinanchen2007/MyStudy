注意首尾空格和内部空格

```javascript
/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
    let tmp = s.trim().replace(/ +/g,' ');
    return tmp.split(' ').reverse().join(' ');
};
```