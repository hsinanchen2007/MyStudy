公式已经给了，照着套
```
/**
 * @param {number} n
 * @return {number}
 * 思路：利用array，while循环出每个T项放入数组中
 */
var tribonacci = function(n) {
  let arr = [0, 1, 1];
  if (n < 3) return arr[n];
  let i = 3;
  while (n >= i) {
    arr[i] = arr[i - 3] + arr[i - 2] + arr[i - 1];
    i++;
  }
  return arr[n];
};
```