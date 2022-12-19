## 一
> 92ms,34.4M
```javascript []
/**
 * @param {number} n - a positive integer
 * @return {number}
 */
var hammingWeight = function(n) {
  return n.toString(2).replace(/0+/g, '').length;
};
```

## 二
> 88ms,34.8M
```javascript []
/**
 * @param {number} n - a positive integer
 * @return {number}
 */
var hammingWeight = function(n) {
  let count = 0;
  while(n !== 0) {
    if (n % 2 !== 0) count++;
    n >>>= 1;
  }
  return count;
};
```
#### `>>>` 为无符号左边填充0，`>>` 为有符号填充

