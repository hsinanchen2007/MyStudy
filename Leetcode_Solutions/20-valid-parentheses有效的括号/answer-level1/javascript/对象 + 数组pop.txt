### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    var map = {
        "(": ")",
        "[": "]",
        "{": "}"
    }
    var arr = []
    for (var i of s) {
        if (map[i]) {
            arr.push(map[i])
        } else {
            if (i !== arr.pop()) {
                return false;
            }
        }
    }
    return !arr.length;
};
```