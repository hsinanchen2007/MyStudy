### 解题思路
字符串转成对象

### 代码

```javascript
/**
 * @param {string} astr
 * @return {boolean}
 */
var isUnique = function(astr) {
    var obj = {};
    for (var i = 0; i < astr.length; i++) {
        if (obj[astr[i]]) {
            return false;
        }
        obj[astr[i]] = 1;
    }
    return true;
};
```