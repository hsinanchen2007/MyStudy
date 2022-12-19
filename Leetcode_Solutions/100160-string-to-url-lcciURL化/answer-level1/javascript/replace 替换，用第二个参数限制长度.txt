### 解题思路
replace方法的第二个参数可传入函数，返回替换的值，函数接收的参数分别为：
`当前匹配的字符串`、`当前序号`、`用于匹配的原字符串`

全局匹配空格，若匹配到的空格的序号大于等于真实长度，则返回空，否则返回替换的字符。

### 代码
```javascript []
/**
 * @param {string} S
 * @param {number} length
 * @return {string}
 */
var replaceSpaces = function(S, length) {
  return S.replace(/\s/g, (s, i) => (i >= length ? "" : "%20"));
};
```
