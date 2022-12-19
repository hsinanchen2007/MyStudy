### 解题思路
先用substr截取字符串，再用replace把空格替换成%20，须全局替换。

### 代码

```javascript
/**
 * @param {string} S
 * @param {number} length
 * @return {string}
 */
var replaceSpaces = function(S, length) {
    return S.substr(0,length).replace(/ /g,"%20")
};
```