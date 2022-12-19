采用遍历的方式，判断当前位置的值如果比后面一个小，就相减，否则相加

```
/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function(s) {
    var obj = {
        'I': 1,
        'V': 5,
        'X': 10,
        'L': 50,
        'C': 100,
        'D': 500,
        'M': 1000
    };
    
    if (s.length == 0) return 0;
    if (s.length == 1) return obj[s];
    
    var result = 0;
    for (var i=0; i<s.length; i++) {
        if(obj[s[i]] < obj[s[i+1]]) {
            result += obj[s[i+1]] - obj[s[i]]
            i++
        } else {
            result += obj[s[i]]
        }
    }
    return result;
};
```
