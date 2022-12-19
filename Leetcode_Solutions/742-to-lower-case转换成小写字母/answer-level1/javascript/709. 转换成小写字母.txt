### 解题思路
A-Z编码为65-90, a编码为97

### 代码

```javascript
/**
 * @param {string} str
 * @return {string}
 */
var toLowerCase = function(str) {
    let result = ''
    for(let i = 0; i < str.length; i++){
        let code = str.charCodeAt(i)
        if(code >= 65 && code <= 90){
            code += 32
        }
        result += String.fromCharCode(code)
    }
    return result
};
```