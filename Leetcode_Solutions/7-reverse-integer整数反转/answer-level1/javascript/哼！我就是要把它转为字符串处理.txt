# 代码
## 第一版，虽然得出结果，但是不符合题意 “*假设我们的环境只能存储得下 32 位的有符号整数*”
> 116ms,35.6M
```javascript []
/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
  if (x < 0) return -reverse(-x);
  const againstX = +(x + '').split('').reverse().join('');
  if (againstX > 2147483647) return 0;
  return againstX;
};
```

## 第二版，这回不会溢出了
> 92ms,35.8M
```javascript []
/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
  if (x < 0) return -reverse(-x);
  const xStr = ('' + x).replace(/0+$/, '');
  if (xStr.length > 10) return 0;
  if (xStr.length < 10) return +xStr.split('').reverse().join('');

  const maxInt32Str = '2147483647';
  for (let i = 0; i < 10; i++) {
    if (xStr[9 - i] < maxInt32Str[i]) return +xStr.split('').reverse().join('');
    if (xStr[9 - i] > maxInt32Str[i]) return 0;
  }
  return +xStr.split('').reverse().join('');
};
```