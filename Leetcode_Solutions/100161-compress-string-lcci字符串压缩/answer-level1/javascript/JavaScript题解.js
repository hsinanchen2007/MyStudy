### 解题思路
比较简单，cur记录当前值，count记录当前值出现的次数。遍历字符串，当S[i] !== cur时，更新count为0， cur为S[i];

### 代码

```javascript
/**
 * @param {string} S
 * @return {string}
 */
var compressString = function(S) {
    var len = S.length;
    var cur = S[0];
    var count = 0;
    var str = ''
    for (var i = 0; i <= len; i++) {
        if (S[i] !== cur) {
            str += `${cur}${count}`;
            count = 0;
            cur = S[i];
        }
        count++;
    }

    return str.length >= len ? S : str;
};
```