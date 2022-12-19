比如n = 4，那么以1开头的单词有 3 * 2 * 1 个；n = 3，以1开头的单词有 2 * 1个，依次类推，只要得出 k 是当前阶乘的多少倍，那么就获取剩下的当中的第几个单词。

执行用时 :68 ms, 在所有JavaScript提交中击败了100.00%的用户
内存消耗 :33.7 MB, 在所有JavaScript提交中击败了80.28%的用户

```javascript
/**
 * @param {number} n
 * @param {number} k
 * @return {string}
 */
var getPermutation = function(n, k) {
  let m = 1;
  k = k - 1;
  for (let i = 2; i < n; i++) m *= i;

  let a = [];
  for (let i = 1; i <= n; i++) a.push(i)

  let s = []
  for (let i = 0; i < n; i++) {
    let t = k / m | 0
    s[i] = a[t]
    a.splice(t, 1)
    k %= m
    m /= (n - i - 1)
  }
  return s.join("");
};
```