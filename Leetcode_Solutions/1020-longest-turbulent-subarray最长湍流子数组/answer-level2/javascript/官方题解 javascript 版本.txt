### 解题思路

大家好，我是 17

这道题的关键是如何把语言描述转化为程序方便处理的形式。

把 大于，小于等于转换为 -1 ，1，0 。这样就方便判断了。

### 代码

```javascript
/**
 * @param {number[]} A
 * @return {number}
 */
var maxTurbulenceSize = function(A) {
 let N = A.length;
  let ans = 1;
  let anchor = 0;

  for (let i = 1; i < N; ++i) {
    let c =compare(A[i-1],A[i])
    if (i == N - 1 || c * compare(A[i], A[i + 1]) != -1) {
      if (c != 0) ans = Math.max(ans, i - anchor + 1);
      anchor = i;
    }
  }

  return ans;

};

function compare(a, b) {
  if (a > b) return 1
  if (a < b) return -1
  return 0
}
```