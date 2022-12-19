### 解题思路
![image.png](https://pic.leetcode-cn.com/ff5582f467bb8fe16b3d99472fd28df26ab25eff139489167376f7e5631f6340-image.png)

正则表达式 + parseInt()

### 代码

```javascript
/**
 * @param {string} str
 * @return {number}
 */
var myAtoi = function(str) {
    const re = /^\s*[+-]?\d+/;
    const MAX = 2147483647;
    const MIN = -2147483648;
    let ret = str.match(re) ? parseInt(str.match(re)[0], 10) : 0;
    if (ret > MAX) ret = MAX;
    if (ret < MIN) ret = MIN;
    return ret;
};
```