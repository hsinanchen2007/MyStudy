```
/**
 * @param {string} s
 * @return {number}
 */
var balancedStringSplit = function(s) {
    var sign = 0
    var balanceNum = 0
    for (var i = 0; i < s.length; i++) {
        if (s[i] === 'R') {
            sign ++
        } else if (s[i] === 'L') {
            sign --
        }
        if (sign === 0) {
            balanceNum ++
        }
    }
    return balanceNum
};
```
