### 解题思路
从前往后比较就可以了。

### 代码

```javascript
var longestCommonPrefix = function (strs) {
    if (!strs.length) return '';
    for (var x = 0; x < strs[0].length; x++) {
        for (var i = strs.length-1; i >= 0; i--) {
            if (strs[0][x] != strs[i][x]) {
                return strs[0].substr(0,x)
            }
        }
    }
    return strs[0]
};

```