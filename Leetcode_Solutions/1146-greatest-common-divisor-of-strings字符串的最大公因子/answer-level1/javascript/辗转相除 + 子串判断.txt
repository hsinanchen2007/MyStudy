### 解题思路

辗转相除 + 子串判断

### 代码

```javascript
/**
 * @param {string} str1
 * @param {string} str2
 * @return {string}
 */
var gcdOfStrings = function(str1, str2) {
    let m = str1.length 
    let n = str2.length
    while(n > 0){
        let t = n
        n = m % n
        m = t
    }
    for (let i = 0; i< str1.length ; i+=m){
        if (str1.substr(i, m) != str1.substr(0, m)) return ""
    }
    for (let i = 0; i< str2.length ; i+=m){
        if (str2.substr(i, m) != str1.substr(0, m)) return ""
    }
    return str1.substr(0, m)
};
```