### 解法一：循环找括号对 消除

```javascript
/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function (s) {
  if (s.length % 2 !== 0) return false
  while (s.includes('()') || s.includes('[]') || s.includes('{}')) {
    s = s.replace(/\(\)/g, '').replace(/\[\]/g, '').replace(/\{\}/g, '')
  }
  return s ? false : true
}
```

### 解法二
定义一个数组保存括号排序，循环字符串，遇到匹配的括号就抵消掉
![image.png](https://pic.leetcode-cn.com/a84f04b27b24cdc41619ebe734ab39a0ad894e3fcaedf34684072ef5c5c00a81-image.png)

```javascript
/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function (s) {
  let len = s.length
  if (len === 0) return true
  if (len % 2 !== 0) return false
  let map = new Map([['(', ')'], ['[', ']'], ['{', '}']])
  let arr = [s[0]]
  for (let i = 1; i < len; i++) {
    if (s[i] === map.get(arr[0])) {
      arr.shift()
    } else {
      arr.unshift(s[i])
    }
  }
  return arr.length === 0
}
```