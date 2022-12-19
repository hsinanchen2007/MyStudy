### 解题思路
类斐波那契数列

f(0) = 1, f(1) = 1, f(2) = 2
f(n) = f(n-1) + f(n-2)

### 代码

```javascript
/**
 * @param {number} n
 * @return {number}
 */
var numWays = function (n) {
  if (n === 0) return 1
  if (n <= 2) return n
  let a = 1, b = 2, c, i
  for (i = 3; i <=n; i++) {
    c = a + b
    a = b % 1000000007
    b = c % 1000000007
  }
  return b
}

```


记忆函数 迭代
```js
var numWays = function (n) {
  let memo = []
  return step(0, n, memo)
}

function step(i, n, memo) {
  if (i > n) return 0
  if (i === n) return 1
  if (memo[i] > 0) return memo[i]
  memo[i] = step(i + 1, n, memo) + step(i + 2, n, memo)
  return memo[i] % 1000000007
}
```