### 解题思路

大家好，我是17

依题意，有三种状态是允许的

1. 全是 0 
2. 全是 1
3. 前面全是 0，后面全是 1

对于第一种和第二种，容易求出，第三种需要对每个位置计算，左面全变成 0 右面全变成1，哪个操作次数更小。

### 代码

```javascript

var minFlipsMonoIncr = function (S) {
   let left1 = [], right0 = []
  let c = 0
  for (let i = 0; i < S.length; i++) {
    if (S[i] == 1) c++
    left1[i] = c
  }
  c = 0
  for (let i = S.length - 1; i >= 0; i--) {
    if (S[i] == 0) c++
    right0[i] = c
  }
  c = Infinity
  for (let i = 0; i < S.length - 1; i++) {

    c = Math.min(left1[i] + right0[i + 1], c)
  }
  c = Math.min(c, left1[S.length - 1], right0[0])
  return c
};
```

### 动态规划解题思路

对于当前位置，

如果是 1，是允许的，最小操作次数不变
如果是 0，是不允许的，有两种操作。把当前位置的这一个 0  变成 1 ，最小操作次数 加 1 或 把所有 1 变成 0，取两者最小值。

```javascript
var minFlipsMonoIncr = function (S) {
  let dp = [0]
  let c1 = 0
  if (S[0] == 1) c1 = 1

  for (let i = 1; i < S.length; i++) {
    let c = Number(S[i])
    c1 += c
    if (c == 1) {
      dp[i] = dp[i - 1]
    }
    else {
      dp[i] = Math.min(dp[i - 1] + 1, c1)
    }
  }
  return dp[S.length - 1]
};
```
