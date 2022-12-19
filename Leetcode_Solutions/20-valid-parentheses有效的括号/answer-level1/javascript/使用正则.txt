

解题思路：匹配到成对括号，就替换成空字符串

```
var isValid = function(s) {
    let reg = /\(\)|\[\]|\{\}/
    while( reg.test( s ) ){
        s = s.replace( reg, "" )
    }
    return s.length === 0
};
```
