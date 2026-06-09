# javascript 解析思路

* 设置一个左游标，记录不重复子字符串的在整个字符串中的左起始位置，依次循环整个str，当找到重复字符时候，左游标右移，移动的距离是，当前左游标加子字符串中找到重复字符的位置

```
/**
 * @param {string} str
 * @return {number}
 */
var lengthOfLongestSubstring = function(str) {
 if (!str.length) return 0
    let tmpStr = ''   // 每次循环找到的不含重复字符的子字符串
    let maxStrLen = 0   // 最大不含重复字符的子字符串的长度
    let len = str.length   
    let left = 0  // 不含重复字符的子字符串的左游标
    for (let i = 0; i < len; i++) {
        if (tmpStr.indexOf(str[i]) !== -1) {
            left += (str.slice(left, i).indexOf(str[i]) + 1)
            continue
        }
        tmpStr = str.slice(left, i + 1)
        maxStrLen = Math.max(maxStrLen, tmpStr.length)
    }
    return maxStrLen
};
```
