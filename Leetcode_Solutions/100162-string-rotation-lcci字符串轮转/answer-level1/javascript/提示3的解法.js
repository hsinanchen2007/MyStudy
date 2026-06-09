### 解题思路
这道题提示给得比较明白，只要字符串自加两次，另一字符串是否存在于其中即可

### 代码

```javascript
/**
 * @param {string} s1
 * @param {string} s2
 * @return {boolean}
 */
var isFlipedString = function(s1, s2) {
    if (s1.length !== s2.length) {
        return false
    }
    let s = s1 + s1;
    return s.indexOf(s2) !== -1
};
```