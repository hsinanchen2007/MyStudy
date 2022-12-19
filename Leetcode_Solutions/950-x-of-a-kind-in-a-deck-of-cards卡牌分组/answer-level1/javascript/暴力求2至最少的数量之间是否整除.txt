### 解题思路
求出每个数字的数量组成的数组，求数组能不能整除[2,最少数量]之间任意一个数，如果能就能分组

### 代码

```javascript
/**
 * @param {number[]} deck
 * @return {boolean}
 */
var hasGroupsSizeX = function (deck) {
  if (!deck.length || deck.length === 1) return false;
  let obj = {};
  for (let i of deck) {
    obj[i] = !obj[i] ? 1 : ++obj[i];
  }
  const sizeArr = Object.values(obj);
  const minSize = Math.min.apply(null, sizeArr);
  for (let i = 2; i <= minSize; i++) {
    if (sizeArr.every(key => !(key % i))) return true;
  }
  return false;
};


```