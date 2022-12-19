### 解题思路
n长度的字符可以看做是n-1长度字符和当前剩余字符拼接出来。所以n长度字符的可能性为n-1长度的可能性+剩余字符有多少种

所以从长度1开始一直到字符长度，递归即可。这样的方式占用内存小，击败100%
### 代码

```javascript
/**
 * @param {string} tiles
 * @return {number}
 */
var numTilePossibilities = function(tiles) {
    let sum = 0;
    function cal(list, n) {
        let ns = Array.from(new Set(Array.from(list)));
        sum += ns.length;
        for (let i = 0, l = ns.length; i < l; i++) {
            if (n > 1) {
                cal(list.replace(ns[i], ''), n - 1);
            }
        }
    }
    cal(tiles, tiles.length);
    return sum;
};
```