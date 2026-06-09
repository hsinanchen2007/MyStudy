![image.png](https://pic.leetcode-cn.com/b77bd2b258c70d9fccecfc3957a0af73c58c7da6817b8d8d24d295e16b908606-image.png)

```javascript []
/**
 * @param {string} a
 * @param {string} b
 * @return {string}
 */
var addBinary = function(a, b) {
    let tBinary = BigInt("0b"+a) + BigInt("0b"+b);
    return tBinary.toString(2);
};
```
