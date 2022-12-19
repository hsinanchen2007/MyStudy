### 解题思路
1. 求出第n个字符所在的数字是几位
2. 求出第n个字符所在的数字
3. 求出第n个字符

### 代码

```javascript
/**
 * @param {number} n
 * @return {number}
 */
var findNthDigit = function(n) {
  // 0-9
  if (n>=0 && n <=9) return n

  // 10-99       90    Math.pow(10, 1) * 9个
  // 100-999     900   Math.pow(10, 2) * 9个
  // 1000-9999   90000 Math.pow(10, 3) * 9个
  // 1...-9...   9...  Math.pow(10, i - 1) * 9个
  var start = 9
  var i = 1
  
  // 求出第n个字符所在的数字是几位
  while(start < n) {
      i += 1
      start += Math.pow(10, i - 1) * 9 * i
  }

  // 最后一个字符与第n个字符之间相差多少个数
  var diff_n = Math.floor((start - n) / i)
  // 余数
  var diff_y = (start - n) % i
  
  // 由规律可知最后一个数为Math.pow(10, i) - 1
  // 相差diff_n个数切余数为diff_y
  return `${Math.pow(10, i) - 1 - diff_n}`.charAt(i - 1 - diff_y)
};
```