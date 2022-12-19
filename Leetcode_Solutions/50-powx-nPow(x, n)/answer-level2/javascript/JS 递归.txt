# 代码
> 80ms,33.5M。
```javascript []
/**
 * @param {number} x
 * @param {number} n
 * @return {number}
 */
var myPow = function(x, n) {
  if (n < 0) return 1 / myPow(x, -n);
  if (n === 0) return 1;
  if (n % 2 === 0) return myPow(x * x, Math.floor(n / 2));
  return myPow(x * x, Math.floor(n / 2)) * x;
};
```