### 解题思路
外层遍历 找出所有二元和三元的基础数据 
  内层遍历 P(i-1,j+1) = P(i,j) && s[i-1] === s[j+1]      状态转移方程用 [最大长度, i, j] 这种数据结构存储
截取 i到j 的字符串即最长子字符串

### 代码

```javascript
/**
 * @param {string} s
 * @return {string}
 */
var longestPalindrome = function(s) {
  let left = 0
  let right = 0
  let len = s.length
  // 第一个存最大长度， 第二个存left, 第三个存right
  let res = [1, 0, 0]
  for (let i=1; i < len; i++) {
    // 记录所有二元
    if (s[i-1] === s[i]) {
      if (res[0] < 2) {
        res =  [2, i-1, i]
      }
      left = i-2
      right = i+1
      while(left>=0 && right<len) {
        if (s[left] !== s[right]) {
          break
        }
        if (right-left+1 > res[0]) {
          res = [right-left+1, left, right]
        }
        left--
        right++
      }
    }
    // 记录所有三元
    if (s[i-1] === s[i+1]) {
      if (res[0] < 3) {
        res = [3, i-1, i+1]
      } 
      left = i - 2
      right = i + 2
      while (left>=0 && right<len) {
        if (s[left] !== s[right]) {
          break
        }
        if (right-left+1 > res[0]) {
          res = [right-left+1, left, right]
        }
        left--
        right++
      }
    }
  }
  return s.slice(res[1], res[2]+1)
};
```