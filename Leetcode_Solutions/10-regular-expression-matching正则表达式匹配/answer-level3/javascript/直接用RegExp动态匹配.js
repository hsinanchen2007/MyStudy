### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} s
 * @param {string} p
 * @return {boolean}
 */
var isMatch = function(s, p) {
    var reg = new RegExp(p);
    return !!reg.exec(s) && reg.exec(s)[0] === s;
};
```