### 执行结果
![image.png](https://pic.leetcode-cn.com/49c794538e78363a0fc9c4bd40aed867dfabce1f8eea441705e74917328ca63d-image.png)

### 解题思路
代码一目了然

### 代码

```javascript
/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
    if (x < 0) return false

    let reverse = 0
    let tmp = x
    while (tmp) {
        reverse = reverse * 10
        reverse = reverse + tmp % 10
        tmp = Math.floor(tmp / 10)
    }

    return reverse === x

};
```