### 解题思路
![image.png](https://pic.leetcode-cn.com/e3e5f669f4b6858959690a368990f2a96c709635434cc2d1570504c20e53eeea-image.png)


### 代码

```javascript
/**
 * @param {number} n
 * @return {number}
 */
var fib = function(n) {
    let fibonacci = [0,1];
    for(let i = 2; i <= n; i ++) {
        fibonacci[i] = (fibonacci[i - 1] + fibonacci[i - 2]) % (1e9 +7);
    }
    return fibonacci[n];
};
```