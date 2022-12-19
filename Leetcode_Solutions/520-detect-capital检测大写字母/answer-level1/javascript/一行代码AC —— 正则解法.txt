### 解题思路
正则适用于字符串的匹配，根据题目的要求：

- 全部字母都是大写，比如"USA"。
- 单词中所有字母都不是大写，比如"leetcode"。
- 如果单词不只含有一个字母，只有首字母大写， 比如 "Google"。

转化成正则的表达：

- 匹配全部由大写字母组成的字符串
- 匹配全部由小写字母组成的字符串
- 匹配由首字母大写组成的字符串

### 代码

```javascript
/**
 * @param {string} word
 * @return {boolean}
 */
var detectCapitalUse = function(word) {
    return /^[A-Z]+$|^[a-z]+$|^[A-Z][a-z]+$/.test(word)
};
```