### 解题思路
javascript map

### 代码

```javascript
/**
 * @param {string} pattern
 * @param {string} str
 * @return {boolean}
 */
var wordPattern = function(pattern, str) {
      const pArr = pattern.split('')
      const sArr = str.split(' ')
      const pLen = pArr.length
      const sLen = sArr.length
      if (pLen !== sLen) {
        return false
      }
      const mapP = new Map()
      const mapS = new Map()
      for (let i = 0; i < pLen; i++) {
        const pat = pArr[i]
        const s = sArr[i]
        if (!mapP.has(pat)) {
          mapP.set(pat, s)
        } else {
          if (mapP.get(pat) !== s) {
            return false
          }
        }
        if (!mapS.has(s)) {
          mapS.set(s, pat)
        } else {
          if (mapS.get(s) !== pat) {
            return false
          }
        }
      }
      return true
    };
```