
## 代码

```javascript
/**
 * @param {string} s
 * @return {boolean}
 */
var isPalindrome = function(s) {
    s = s.replace(/[^0-9a-zA-Z]/g,'').toLowerCase()
    let low = 0
    let high = s.length - 1
    while (low <= high) {
        if (s[low] !== s[high]) {
            return false
        }
        low++
        high--
    }
    return true
};
```
时间复杂度：O(n)
空间复杂度：O(1)