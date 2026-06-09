## 第一版，递归分解质因数，暴力循环吧，循环条件看起来还可以优化
> 64ms,33.9M。
```javascript []
/**
 * @param {number} n
 * @return {number}
 */
var minSteps = function(n) {
  if (n === 1) return 0;
  for (let i = 2; i <= n / 2; i++) {
    if (n % i === 0) return minSteps(i) + minSteps(n / i);
  }
  return n;
};
```
### 解题思路
1. 观察发现将`n`分解质因数后，`n = n1 * n2 * ...`，n的步骤数就等于它的所有质因数的操作次数的和，所以`step(n) = step(n1) + step(n2) + ...`。
2. 至于它为什么是最小操作次数数我还没想好怎么证明。补充：看完官方题解后明白为什么了，证明思路直接看官方题解就好。

## 第二版，稍微优化下，用一个对象来存储递归过程中已计算过的质因数所需要的步骤数，减少计算次数。看起来还是有优化空间，这个存储有些用过一次后不会再用第二次了应该。
> 64ms,34M。
```javascript []
/**
 * @param {number} n
 * @return {number}
 */
var minSteps = function(n, cache = {}) {
  if (n === 1) return 0;
  for (let i = 2; i <= n / 2; i++) {
    if (n % i === 0) {
      if (!cache[i]) cache[i] = minSteps(i, cache);
      if (!cache[n / i]) cache[n / i] = minSteps(n / i, cache);
      return cache[i] + cache[n / i];
    }
  }
  return n;
};
```