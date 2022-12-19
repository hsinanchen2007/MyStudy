js中乘法自动对字符串进行处理（不用特别处理负号）
*[复数运算规则](https://baike.baidu.com/item/复数运算法则/2568041?fr=aladdin)*
```javascript []
var complexNumberMultiply = function(a, b) {
  let numA = a.match(/-?\d+(?=\+|$)/)
  let numB = b.match(/-?\d+(?=\+|$)/)
  let iA = a.match(/-?\d+(?=i)/)
  let iB = b.match(/-?\d+(?=i)/)
  let num = numA * numB - iA * iB
  let i = iA * numB + numA * iB
  return num + '+' + i + 'i'
}
```
