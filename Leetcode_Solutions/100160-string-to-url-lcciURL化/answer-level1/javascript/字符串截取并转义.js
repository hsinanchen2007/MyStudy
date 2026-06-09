### 解题思路
末位空格忽略的话用 substring 进行字符串处理
再用 encodeURL 进行空格转义
### 代码

```javascript
/**
 * @param {string} S
 * @param {number} length
 * @return {string}
 */
var replaceSpaces = function(S, length) {
    return encodeURI(S.substring(0, length))
};
```