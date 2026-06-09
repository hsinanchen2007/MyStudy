### 解题思路
把题目的意思转述一下，就是找一张牌有没有另一个配对的，有就数量加1。也就是已一个数，找另一个数的问题。

1. 为了方便找别一个，把牌都转成，小数在前大数在后
2. 用两数和的方法 查找另一个。

### 代码

```javascript
/**
 * @param {number[][]} dominoes
 * @return {number}
 */
var numEquivDominoPairs = function (dominoes) {
  dominoes = dominoes.map(item => {
    item.sort((a, b) => a - b)
    return item
  })
  let map = new Map()
  let count = 0
  for (let item of dominoes) {
    let key = item.join('')
    if (map.has(key)) {
      count += map.get(key)
      map.set(key, map.get(key) + 1)
    }
    else {
      map.set(key, 1)
    }
  }
  return count
};
```