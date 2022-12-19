### 解题思路
![image.png](https://pic.leetcode-cn.com/584a62fca42e4d39ba06c9dc47475d689fd4ec91c8da7d584b2afe7f653a67b0-image.png)


### 代码

```javascript
/**
 * @param {number} a
 * @param {number} b
 * @return {number}
 */
var getSum = function(a, b) {
    let tmp = a ^ b
    let res =(a & b) << 1
    return res + tmp
};
```