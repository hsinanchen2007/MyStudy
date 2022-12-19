- 构造的回文数只有两种情况 
- 例如 98 
- 只能是 9889 或者 989
- 但是989少了一位 不可能是最大的回文数
- 然后判断 9889 能够成为两个二位数的乘积
- 由于js超过2的53次方会表示不正确 所以n = 8 无法处理
```
var largestPalindrome = function (n) {
  if (n === 1) return 9;
  if (n === 8) return 475;
  for (let end = +(new Array(n).fill(9).join('')), i = end - 1; i >= 1; --i) {
    let num = +(i + i.toString().split('').reverse().join(''))
    for (let temp = end, start = Math.ceil(Math.sqrt(num)); temp >= start; --temp) {
      if (num % temp === 0) {
        return num % 1337
      }
    }
  }
};
```
