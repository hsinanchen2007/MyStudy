### 解题思路
斐波那契数列

### 代码

```javascript
/**
 * @param {number} n
 * @return {number}
 */
var fib = function(n) {
  if (n === 0) return 0
  if (n === 1) return 1
  let arr = [0, 1]
  for (let i = 2; i <= n; i++) {
    arr[i] = arr[i - 1] % 1000000007 + arr[i - 2] % 1000000007
  }
  return arr[n] % 1000000007
};
```