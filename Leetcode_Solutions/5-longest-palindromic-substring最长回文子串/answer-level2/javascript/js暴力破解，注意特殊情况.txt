### 解题思路
此处撰写解题思路
暴力遍历，以每个字符为中心向两边展开，注意特殊情况，连续两个字符相同（看成一个字符），然后展开

### 代码

```javascript
/**
 * @param {string} s
 * @return {string}
 */
var longestPalindrome = function(s) {
    let maxStr = "";
    const len = s.length;
    for (let i = 0; i < len; i++) {
  if (s[i - 1] == s[i] && i > 0) {
    for (let j = 1; j <= len; j++) {
      if (i - j - 1 < 0 || i + j >= len || s[i - j - 1] != s[i + j]) {
        j--;
        let tmp = s.substring(i - j - 1, i + j+1);
        // j--;
        maxStr = maxStr.length < (2 + 2 * j) ? tmp : maxStr;
        break;
      }
    }
  }

  for (let j = 1; j <= len; j++) {
    if (i - j < 0 || i + j >= len || s[i - j] != s[i + j]) {
      j--;
      let tmp = s.substring(i - j, i + j + 1);
      maxStr = maxStr.length < (1 + 2 * j) ? tmp : maxStr;
      break;
    }

  }

}
    return maxStr;
};
```