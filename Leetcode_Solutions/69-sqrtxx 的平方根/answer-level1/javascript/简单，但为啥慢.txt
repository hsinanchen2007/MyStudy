### 解题思路
![image.png](https://pic.leetcode-cn.com/c18923f4325e5c0abe11fbe8754d76e7ee43678cb33b1b3af57adbed11eec6cf-image.png)


### 代码

```javascript
/**
 * @param {number} x
 * @return {number}
 */
var mySqrt = function (x) {
    if (!x) return 0;
    let ret = 1;
    for (let i = 1; i <= x / i; i++) {
        ret = i;
    }
    return ret;
};
```