### 解题思路
易知回文如果长度是偶数，那么必然组成回文的每种字母的个数都是偶数，如果回文长度是奇数，那有且只有一种字母，是奇数，其他的必须是偶数
### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var longestPalindrome = function (s) {
  let res = 0
  let map = new Map()
  for (let i = 0; i < s.length; i++) {
    if (map.has(s[i])) {
      map.delete(s[i])
      res += 2
    } else {
      map.set(s[i], 1)
    }
  }
  if (map.size !== 0) {
    res++
  }
  return res;
};
```