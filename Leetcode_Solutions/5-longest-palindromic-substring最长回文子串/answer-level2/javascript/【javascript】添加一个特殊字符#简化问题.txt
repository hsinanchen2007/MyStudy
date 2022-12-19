### 解题思路
 看到这种方法，简直惊呆了，什么样的脑袋才能想到这种方法
 向字符串的空隙和首尾添加一个特殊字符，这样回文就肯定是奇数子串
 如："baaac", "#b#a#a#a#c", 回文串是“#a#a#a#”
     "aaaa", "#a#a#a#a#", 回文串是”#a#a#a#a#“
 这样再找中心，就十分方便了

方法用了，但是代码比较烂，时间和空间还是很费哈哈哈

### 代码

```javascript
/**
 * @param {string} s
 * @return {string}
 */
var longestPalindrome = function(s) {
  if (s.length === 1) return s
  let s2 = '#'
  // 给s的所有空隙和首尾都加上一个特殊的字符’#‘，这样它的回文字符串就一定是奇数
  for (let i = 0; i < s.length; i++) {
    s2 += (s[i] + '#')
  }
  let res = ''
  for (let i = 0; i < s2.length; i++) {
    let left = i - 1
    let right = i + 1
    // 选定一个中心，然后向左右扩展
    let str = s2[i] === '#' ? '' : s2[i]
    while(s2[left] === s2[right] && left >= 0 && right < s2.length) {
      if (s2[left] !== '#') {
        str = s2[left] + str + s2[right]
      }
      left--
      right++
    }
    // 这里可以提前跳出循环
    if (str.length === s2.length) {
      return str
    }
    if (str.length > res.length) {
      res = str
    }
  }
  return res
};
```