直接用`String.prototype.replace(regex, newSubStr)`替换即可。

```javascript
/**
 * @param {string} s
 * @return {string}
 */
var replaceSpace = function(s) {
    return s.replace(/ /g, "%20")
};
```
