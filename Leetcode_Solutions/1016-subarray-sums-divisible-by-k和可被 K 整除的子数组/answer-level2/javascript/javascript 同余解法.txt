### 解题思路

大家好，我是 17

解这题的关键是要看基础知识是不是够。


1. **给你几个不同的数，算出有几种组合。**

   比如 给你 1，2，3 三个数，不同的组合数为 `3*2/2` ,是 (1,2),(1,3),(2,3)
   所以 算 n 个 数的不同组合的公式 为 `n*(n-1)/2`
   
2. **前缀和**

   对于一个数组，从第一个开始，每迭代到一个数，都把前面的和加到自身。

2. **同余的数**
 
   对于 模 5，3 和 8 都余 3 。 -2 模 5 余 -2 ，也可以看作是 余 3 ,因为 -2+5 =5 

   为什么把负数的余数转成正数呢？是为了方便算同余。
   
   先求出前缀和，同余的前缀和之间的子数组一定可以被 5 整除。

   最后 模 0 的前缀和除了可以互相组合外，本身也能被 5 整除。单独加一下。

### 代码

```javascript
/**
 * @param {number[]} A
 * @param {number} K
 * @return {number}
 */
var subarraysDivByK = function (A, K) {
  let map = new Map()
  let sum = 0
  for (let n of A) {
    sum += n
    const key = (sum % K + K) % K
    map.set(key, map.has(key) ? map.get(key) + 1 : 1)
  }
  let result = map.has(0) ? map.get(0) : 0
  for (let [, val] of map) {
    if (val > 1) result += val * (val - 1) / 2
  }

  return result
}
```