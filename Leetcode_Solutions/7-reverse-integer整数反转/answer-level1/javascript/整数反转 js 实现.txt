### 解题思路
官方题解的 js 实现，具体算法请参考官方题解

### 代码

```javascript
/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
  const edge = 2 ** 31;
  const INT_MAX = edge - 1;
  const INT_MIN = -edge;

  let rev = 0;
  while (x !== 0) {
    const pop = ~~(x % 10);

    x = ~~(x / 10);
    if (rev > INT_MAX / 10 || (rev === INT_MAX / 10 && pop > 7)) return 0;
    if (rev < INT_MIN / 10 || (rev === INT_MIN / 10 && pop < -8)) return 0;
    rev = rev * 10 + pop;
  }
  return rev;
};
```