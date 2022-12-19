```
/**
 * @param {number} n
 * @return {number[]}
 */
var sumZero = function (n) {
  const result = [];
  for (let i = Math.floor(n / 2); i > 0; i--) {
    result.push(-i);
    result.push(i);
  }
  if (n % 2 === 1) {
    result.push(0);
  }
  return result;
};
```
