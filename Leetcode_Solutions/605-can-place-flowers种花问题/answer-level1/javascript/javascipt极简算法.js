### 解题思路
因为是线性问题，所以可以用贪心。

因为`javascript`的数组的特性，如果对应的下标没有值，都返回`undefined`
所以 `!flowerbed[i]` 即可以代表为 `i`位置为`0`的情况，也可以代表超出边界的情况


### 代码

```javascript
/**
 * @param {number[]} flowerbed
 * @param {number} n
 * @return {boolean}
 */
var canPlaceFlowers = function (flowerbed, n) {
  let count=0
  for (let i = 0; i < flowerbed.length; i++) { 
    if (flowerbed[i] === 0) { 
      if (!flowerbed[i - 1] && !flowerbed[i + 1]) {
        count++
        flowerbed[i]=1
      }
    }
  }

  return count >= n
};

```