```
var countAndSay = function (n) {
  let nums = 0 // 个数
  let s = '' // 单个字符串
  let res = '1' // 保留前一项
  let t = '' // 临时转存
  for (let i = 0; i < n - 1; i++) {
    const len = res.length
    for (let j = 0; j < len; j++) {
      const e = res[j]
      s = s == '' ? e : s
      nums++
      if (e != res[j + 1]) {
        t += nums + s
        nums = 0
        s = ''
      }
    }
    res = t
    t = ''
  }
  return res
};
```
