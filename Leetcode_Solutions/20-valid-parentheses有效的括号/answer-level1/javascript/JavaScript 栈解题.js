### 解题思路
利用栈和Map

### 代码

```javascript
/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
  if (s.length % 2 !== 0) {
    return false
  }

  const map = new Map()

  map.set('}', '{')
  map.set(')', '(')
  map.set(']', '[')
  
  const stack = []

  for (let i = 0; i < s.length; i++) {
    if (map.has(s[i])) {
      const pop = !map.size ? '#' : stack.pop()
      if (pop !== map.get(s[i])) {
        return false
      }
    } else {
      stack.push(s[i])
    }
  }

  return !stack.length
};
```