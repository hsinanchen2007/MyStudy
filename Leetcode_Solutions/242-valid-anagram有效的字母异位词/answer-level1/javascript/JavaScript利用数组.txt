### 解题思路

利用数组判断，就是慢了点

### 代码

```javascript
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function(s, t) {
    if (s.length !== t.length) return false
    if (s === t) return true
    const tArr = t.split('')
    let index
    for (let i = 0; i < s.length; i++) {
        index = tArr.indexOf(s[i])
        if (index !== -1) tArr[index] = undefined
    }
    for (let j = 0; j < tArr.length; j++) {
        if (tArr[j] !== undefined) return false
    }
    return true
};
```