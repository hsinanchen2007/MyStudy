### 解题思路


### 代码

```javascript
/**
 * @param {string} s
 * @return {string}
 */
var longestPrefix = function(s) {
    if (s.length === 1) return '';
    for (let i = 1; i < s.length; i++) {
        if (s.substring(i) === s.substring(0, s.length - i)) {
            return s.substring(i);
        }
    }
    return '';
};
```