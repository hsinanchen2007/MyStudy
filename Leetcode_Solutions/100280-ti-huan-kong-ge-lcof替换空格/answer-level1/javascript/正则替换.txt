### 解题思路
正则进行全局替换

### 代码

```javascript
/**
 * @param {string} s
 * @return {string}
 */
var replaceSpace = function(s) {
    return s.replace(/ /g, "%20");
};
```