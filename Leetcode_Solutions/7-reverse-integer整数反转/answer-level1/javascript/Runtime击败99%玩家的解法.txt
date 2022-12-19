```js
var reverse = function(x) {
  const MAX_VAL = Math.pow(2, 31)
  const hasSigal = x < 0
  if (hasSigal) x = -1 * x
  let res = 0
  while(x !== 0) {
    res = res * 10 + x % 10;
    x = Math.floor(x / 10)
  }
  if (hasSigal) res = -1 * res
  if(res < -1 * MAX_VAL || res > MAX_VAL) return 0
  return res
};
```
先判断给定数字的正负，然后从左到右循环，将取到的数模10加上结果扩大十倍即可进位，然后将原数除以10并向下取整。
最后检测得到的数是否在安全范围
