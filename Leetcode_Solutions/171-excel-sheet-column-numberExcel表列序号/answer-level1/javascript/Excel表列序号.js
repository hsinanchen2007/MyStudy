二十六进制转十进制

```js
var titleToNumber = function(s) {
    const map = ['', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'];
    var res = 0;
    var len = s.length;
    for (let i = 0; i < len; i++) {
        res += map.indexOf(s[i]) * Math.pow(26,len-i-1)
    }
    return res;
};
```