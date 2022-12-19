## 第一版，中心扩展法，解法名字来自官方题解，做了这么多题，现在能不暴力就不暴力了。┐(・o・)┌ 
> 108ms,35.8M
```javascript []
/**
 * @param {string} s
 * @return {string}
 */
var longestPalindrome = function(s) {
  if (!s.length) return '';
  let maxStr = '';
  for (let i = 0; i + (maxStr.length >> 1) < s.length; i ++) {
    if (s[i] === s[i + 1]) {
      const { left, right } = findPldrEdge(i, i + 1, s);
      if (right - left - 1 > maxStr.length) maxStr = s.slice(left + 1, right);
    }
    const { left, right } = findPldrEdge(i, i, s);
    if (right - left - 1 > maxStr.length) maxStr = s.slice(left + 1, right);
  }
  return maxStr;
};

/**
 * 在字符串s中寻找以left和right为中心的最长回文子串的边缘索引
 * @param {number} left 回文子串中心的初始左值
 * @param {number} right 回文子串中心的初始右值
 * @param {string} s 原始字符串
 * @return {Object}
 */
function findPldrEdge(left, right, s) {
  while (s[--left] === s[++right] && left >= 0 && right < s.length) {}
  return { left: left + 1, right };
}
```
### 思路
1. 将以每个字符为中心的最长回文子串都找出来，其中最长的就是我们需要的结果咯
2. 注意点1：回文子串的中心并不仅仅只能是一个字符，在出现连续两个相同的字符时这两个连续字符也可以作为回文子串的中心
3. 注意点2：不需要一定遍历完全部字符。例如遍历到第`i`个字符时，已经检查出来的最长回文子串的长度为`l`，如果`l / 2`大于剩下未遍历的字符数`s.length - i`时，已经可以直接结束遍历了

#### to do Manacher 算法，看了下算法详解，还是挺厉害的，我咋想不到呢。
