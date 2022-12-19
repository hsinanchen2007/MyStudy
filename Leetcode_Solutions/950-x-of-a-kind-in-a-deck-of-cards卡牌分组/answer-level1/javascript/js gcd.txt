![image.png](https://pic.leetcode-cn.com/c1313ce043dd144106316d9df3ef8171477ece219b1bb0e282679b8eba3c42ea-image.png)

### 解题思路
```js
  对不同数字的出现次数，求它们的最大公约数，是否大于等于2
```

### 代码

```javascript
/**
 * @param {number[]} deck
 * @return {boolean}
 */

var hasGroupsSizeX = function(deck) {
  let map = {}, n = deck.length, ans = null;
  
  const gcd = (a, b) => b === 0 ? a : gcd(b, a % b); // 求最大公约数
  
  for (let i = 0; i < n; i++) {
    let c = deck[i];
    if (map[ c ] === undefined) {
      map[ c ] = 1;
    } else {
      map[ c ] ++;
    }
  }
  
  let keys = Object.keys( map );
  
  for (let k = 0; k < keys.length; k++) {
    let c = map[ keys[k] ];
    if (ans === null) {
      ans = c;
    } else {
      ans = gcd(ans, c);
    }
  }
  
  return ans >= 2;
};
```