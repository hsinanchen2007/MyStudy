### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
    s = s.split(/\s+/).reverse();
    if (s[0] === '') {
        s.shift();
    }
    if (s[s.length - 1] === '') {
        s.pop();
    }
    return s.join(' ');
};
```