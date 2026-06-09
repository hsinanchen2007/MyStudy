### 解题思路
replace函数全局匹配替换

### 代码

```javascript
/**
 * @param {string} S
 * @return {string}
 */
var removeVowels = function(S) {
    return S.replace(/['a','e','i','o','u']/g, '');
};
```