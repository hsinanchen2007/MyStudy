```js
/**
 * @param {string} pattern
 * @param {string} str
 * @return {boolean}
 */
var wordPattern = function(pattern, str) {
    var strTmp = str.split(' ')
    if (pattern.length !== strTmp.length) {
        return false
    }
    var map = {}
    for (var i = 0; i < pattern.length; i++) {
        if (map[pattern[i]]) {
            if (map[pattern[i]] !== strTmp[i]) {
                return false
            }
        } else {
            if (Object.keys(map).length > 0 && Object.values(map).indexOf(strTmp[i]) > -1) {
                return false
            } else {
                map[pattern[i]] = strTmp[i]
            }
        }
    }
    return true
};
```
