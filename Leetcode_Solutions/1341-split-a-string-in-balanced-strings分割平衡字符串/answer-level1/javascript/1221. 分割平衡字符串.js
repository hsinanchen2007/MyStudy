### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var balancedStringSplit = function (s) {
    let L = 0, R = 0, result = 0
    for (let i = 0; i < s.length; i++) {
        if (s[i] === 'L') {
            L++
        } else {
            R++
        }
        if (L === R) {
            result++
            L = 0
            R = 0
        }
    }
    return result
};
```