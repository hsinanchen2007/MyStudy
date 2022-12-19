### 解题思路

![image.png](https://pic.leetcode-cn.com/41b71243d14a06e25f8a79b22c3bff9f50fc2aeb96965d6eec791a714afe13f3-image.png)

### 代码

```javascript
/**
 * @param {number[]} T
 * @return {number[]}
 */
var dailyTemperatures = function(T) {
    let ret = [];
    T.forEach((val, idx, arr) => {
        let n = T.findIndex((t, i) => {
            return t > val && i > idx;
        }) - idx;
        ret.push(n > 0 ? n : 0);
    })
    return ret;
};
```