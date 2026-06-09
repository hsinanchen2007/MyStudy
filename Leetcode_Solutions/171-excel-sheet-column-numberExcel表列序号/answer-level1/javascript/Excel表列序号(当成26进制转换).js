### 解题思路
可以当成26进制转换
![image.png](https://pic.leetcode-cn.com/dfc4fb7a7566515441a020694c9bf72d8b9800da3f47d8d27817262ff178af3a-image.png)

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var titleToNumber = function (s) {
    if (s.length == 1) return s.charCodeAt() - 64
    var strs = s.split('')
    var sum = 0
    var bit = 1
    for (let i = strs.length - 1; i >= 0; i--) {
        sum += bit*(strs[i].charCodeAt() - 64)
        bit *= 26
    }
    return sum
};
```