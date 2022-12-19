### 解题思路

get到的下标不一致就非同构

### 代码

```javascript
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
const isIsomorphic = (s, t) => {
  const sMap = new Map(), tMap = new Map()
  for (let i = 0; i < s.length; i++) {
      if (sMap.get(s[i]) !== tMap.get(t[i])) {
          return false
      } else {
          sMap.set(s[i], i)
          tMap.set(t[i], i)
      }   
  }
  return true
}
```