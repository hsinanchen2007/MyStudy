### 解题思路
一行代码可还香？

### 代码

```javascript
/**
 * @param {string} astr
 * @return {boolean}
 */
var isUnique = function(astr) {
    return new Set(astr).size === astr.length
};
```