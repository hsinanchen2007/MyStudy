### 解题思路
![image.png](https://pic.leetcode-cn.com/1eebac9fd16e3844fa7627e3f4673ae8937172a058a9e3cd0caa733cc95c51f0-image.png)

parseInt本身可以覆盖正则表达式的那部分处理，但是似乎会稍稍慢一些。

### 代码

```javascript
/**
 * @param {string} str
 * @return {number}
 */
var myAtoi = function (str) {
    if (false) {
        const re = /^\s*[+-]?\d+/;
        const MAX = 2147483647;
        const MIN = -2147483648;
        let ret = str.match(re) ? parseInt(str.match(re)[0], 10) : 0;
        if (ret > MAX) ret = MAX;
        if (ret < MIN) ret = MIN;
        return ret;
    }
    // actually parseInt() method could cover the usage of Regex
    let ret = !isNaN(parseInt(str, 10)) ? parseInt(str, 10) : 0;
    const MAX = 2147483647;
    const MIN = -2147483648;
    if (ret > MAX) ret = MAX;
    if (ret < MIN) ret = MIN;
    return ret;
}
```