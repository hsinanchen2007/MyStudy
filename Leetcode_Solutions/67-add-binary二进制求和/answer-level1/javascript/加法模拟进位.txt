```javascript
/**
 * @param {string} a
 * @param {string} b
 * @return {string}
 */
var addBinary = function(a, b) {
  let arr = []
  let carry = 0
  let len = a.length > b.length ? a.length : b.length
  while (a.length < len) { a = '0' + a } // 把 a b 弄一样长，方便做加法
  while (b.length < len) { b = '0' + b }
  for (let i = len - 1; i >= 0; i--) {
    let sum = Number(a[i]) + Number(b[i]) + carry
    if (sum >= 2) {
      arr.push(sum % 2)
      carry = 1
    } else {
      carry = 0
      arr.push(sum)
    }
  }
  return carry === 0 ? arr.reverse().join('') : carry + arr.reverse().join('')
};
```