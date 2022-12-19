### 解题思路
此处撰写解题思路
用滑动窗口的方法，新建一个字符串arr保存s.slice(i,j),只要s[j]不存在于arr中，就将s[j]添加到arr中，并记录下此时无重复字符的字串长度，当s[j]存在arr中时，则移动i，进行下一次的窗口检测。
### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
  if(!s) return 0
  let i = 0
  let j = 1
  let len = 0
  let arr = s.slice(i, j)
  len = arr.length
  let length = s.length
  while( i < length && j < length) {
    if(arr.indexOf(s[j]) === -1) {
      j++
      len = (arr.length + 1) > len ? arr.length + 1 : len
    } else {
      i++
    }
    arr = s.slice(i, j)
  }
  return len  
};
```