### 解题思路
max_num 记录最大种植数量
判断前一项、当前项、后一项是否为1，都不成立为当前项可种植
### 代码

```javascript
/**
 * @param {number[]} flowerbed
 * @param {number} n
 * @return {boolean}
 */
var canPlaceFlowers = function (flowerbed, n) {
  let len = flowerbed.length
  let max_num = 0
  for (let i = 0; i < len; i++) {
    if (flowerbed[i - 1] === 1) continue
    if (flowerbed[i] === 1) continue
    if (flowerbed[i + 1] === 1) continue
    flowerbed[i] = 1
    max_num++
  }
  return max_num >= n
}
```