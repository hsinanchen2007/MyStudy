### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} str1
 * @param {string} str2
 * @return {string}
 */
var gcdOfStrings = function(str1, str2) {
    for(let i=str1.length-1; i>=0; i--) {
        let str = str1.substr(0, i+1)
        let splitStr1 = str1.split(str).join('')
        let splitStr2 = str2.split(str).join('')
        if(!splitStr1 && !splitStr2) {
            return str
        }
    }
    
    return ''
    
};
```

