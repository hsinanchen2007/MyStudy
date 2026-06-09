### 解题思路

以第一个值作为锚点。进行升序遍历，接下来的每一项的值都和锚点的值进行比较，如果一致则往samePrefix加，如果不一致直接退出函数。

### 代码

```javascript
/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
    if (strs.length < 1) return strs[0] || '';
    var anchor = strs.shift()
    var samePrefix = ''
    for (var i = 0; i < anchor.length; i++) {
        var temp = anchor[i]
        for (var j = 0; j < strs.length; j++) {
            var value = strs[j][i]
            if (value !== temp) return samePrefix
        }
        samePrefix += temp
    }
    return samePrefix
};
```