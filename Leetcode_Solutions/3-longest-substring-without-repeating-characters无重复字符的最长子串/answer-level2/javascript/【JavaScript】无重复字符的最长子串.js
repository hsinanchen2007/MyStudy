### 解题思路
首先声明三个参数，一个是无重复最长长度，一个是当前的子串，一个是最终的最长子串
判断当前子串是否包含字母，如果不包含，将它拼接起来，并且判断长度是否大于之前判断的长度，如果大于，则说明有更长的子串形成，需要更新`len`和`longestSubstring`;如果包含了，说明当前元素和之前的元素有重复了，在这里我们找到重复元素第一次出现的索引，然后从它的后一位开始剪切这个字符串，将剪切后的字符串赋值给当前`curSub`，我这里如果你想要返回长度，就`return len`，如果你想要最长的无重复字符串，就`return longestSubstring`
如：`abca`这个子串，第一个a和最后一个a重复了，我们用indexOf拿到第一个a出现的索引，向后推一位即第二位开始剪切这个字符串，则剪切之后的为`bca`，此时可以拿着这个子串继续循环看是否后面元素有重复的。

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
 var lengthOfLongestSubstring = function(s) {
        let len = 0 //这个是长度
        let longestSubstring = '' //这个最长子串
        let curSub = ''
        for (let i = 0; i < s.length; i++) {
          if (!curSub.includes(s[i])) {
            curSub += s[i]
            if (curSub.length > len) {
              longestSubstring = curSub
              len = curSub.length
            }
          } else {
            curSub += s[i]
            let index = curSub.indexOf(s[i])
            curSub = curSub.slice(index + 1)
          }
        }
        return len
      }
    
```
```
<!-- 上面代码的es6版 -->
let lengthOfLongestSubstring = s => {
        let len = 0
        let curSub = ''
        let longestSubstring = ''
        for (let ele of s) {
          if (curSub.includes(ele)) {
            curSub += ele
            curSub = curSub.slice(curSub.indexOf(ele) + 1)
          } else {
            curSub += ele
            if (curSub.length > len) {
              len = curSub.length
              longestSubstring = curSub
            }
          }
        }
        return len
      }
```