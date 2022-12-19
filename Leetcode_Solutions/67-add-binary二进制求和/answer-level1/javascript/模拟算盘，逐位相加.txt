[原题解写于github](https://github.com/feikerwu/algorithm-camp/issues/1)

**解法**

模拟算盘加法，逐位相加即可

**代码**

```
/**
 * @param {string} a
 * @param {string} b
 * @return {string}
 */
var addBinary = function(a, b) {
  // 字符串翻转
  a = a.split('').reverse().join('')
  b = b.split('').reverse().join('')

  // 保证a的长度大于b的长度
  if (a.length < b.length) {
    [a, b] = [b, a]
  }

  let res = ''
  let carry = 0 // 进位

  // 模拟逐位加法
  for(let i = 0; i < a.length; i++) {
    let term = parseInt(a[i]) + parseInt(b[i] || 0) + carry
    carry = parseInt(term / 2)
    term = term % 2
    res = `${term}${res}`
  }

  // 如果最后计算完还有进位的边界处理
  if (carry > 0) {
    res = `${carry}${res}`
  }

  return res;
};
```

