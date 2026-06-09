### 解题思路
使用es6 map
![leetcode-451.png](https://pic.leetcode-cn.com/daa3e36cbaa9d18cecbeb630f6f2d522aefe1463cf602e24574eadd72e8f3c08-leetcode-451.png)

### 代码

```javascript
/**
 * @param {string} s
 * @return {string}
 */
var frequencySort = function(s) {
      const len = s.length
      if (!len) {
        return s
      }
      const map = new Map()
      const temp = []
      let str = ''
      for (let i = 0; i < len; i++) {
        const char = s[i]
        if (!map.has(char)) {
          map.set(char, 1)
        } else {
          map.set(char, map.get(char) + 1)
        }
      }
      map.forEach((val, key) => {
        temp.push({ val, key })
      })
      temp.sort((a, b) => b.val - a.val)
      temp.forEach(item => {
        str += item.key.repeat(item.val)
      })
      return str
    };
```