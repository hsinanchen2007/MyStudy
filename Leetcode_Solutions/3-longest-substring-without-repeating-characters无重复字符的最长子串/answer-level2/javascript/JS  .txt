![image.png](https://pic.leetcode-cn.com/419d9f23d58cbdebe35a5711bb99535b6ba57f4076fc7fcb1d8daf9c67e07987-image.png)

### 解题思路
1. 遍历字符串
2. 把不重复的连续字符串暂存到数组中
3. 若当前遍历的字符在数组中，切割数组
4. 把当前遍历的字符push到数组中
5. Math.max获取最大值

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
  const len = s.length
  let maxLength = 0
  const maxStrArr = []
  for (let i = 0; i < len; i++) {
    const index = maxStrArr.indexOf(s.charAt(i))
    if (index >= 0) {
      maxStrArr.splice(0, index + 1)
    }
    maxStrArr.push(s.charAt(i))
    maxLength = Math.max(maxLength, maxStrArr.length)
  }
  return maxLength
};
```