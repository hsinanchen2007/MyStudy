### 解题思路


### 代码

```javascript
/**
 * @param {string} s1
 * @param {string} s2
 * @return {boolean}
 */
var CheckPermutation = function(s1, s2) {
    if (s1.length !== s2.length) return false;
    var s1Str = s1.split('').sort().join('');
    var s2Str = s2.split('').sort().join('');
    if (s1Str !== s2Str) {
        return false;
    } else {
        return true;
    }
};
```