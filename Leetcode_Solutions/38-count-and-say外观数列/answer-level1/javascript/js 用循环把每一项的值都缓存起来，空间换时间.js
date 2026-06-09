参考菲波那切的解法

```js
var countAndSay = function(n) {
  let cache = [, '1']

  // 通过第n-1项字符串计算出第n项字符串
  let calcStr = s => {
    let activeNum = s[0]
    let times = 1
    let res = ''
    for (let i = 1; i <= s.length; i++) {
      let v = s[i]
      if (activeNum !== v) {
        res = res + times + activeNum
        times = 1
        activeNum = v
      } else {
        activeNum = v
        times++
      }
    }

    return res
  }

  for (let i = 2; i <= n; i++) {
    cache[i] = calcStr(cache[i - 1])
  }

  return cache[n]
}
```
