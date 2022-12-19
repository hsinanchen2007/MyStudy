### 解题思路
1、统计出每种数字的数目
2、所有数目的最大公约数 > 1

### 代码

```javascript
/**
 * @param {number[]} deck
 * @return {boolean}
 */
var hasGroupsSizeX = function(deck) {
  // 统计出每种数字的数目
  const hash = deck.reduce((pre, num) => {
    pre[num] ? pre[num]++ : pre[num] = 1
    return pre
  }, {})
  const counts = Object.values(hash)
  // 最大公约数
  function getGCD (arr) {
    function gcd (a, b) {
      if (b === 0) return a
      return gcd(b, a % b)
    }
    while (arr.length > 1) {
      arr.splice(0, 2, gcd(arr[0], arr[1]))
    }
    return arr[0]
  }
  // 成功条件：
  return getGCD(counts) > 1
};
```