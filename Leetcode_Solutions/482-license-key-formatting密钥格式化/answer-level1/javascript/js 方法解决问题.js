### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} S
 * @param {number} K
 * @return {string}
 */
var licenseKeyFormatting = function(S, K) {
    const res  = []
    const str = S.toUpperCase().split('-').join("").split("").reverse().join("")
    let index = 0
    for(let i = 0, len = str.length; i < len; i ++) {
        if(len - index <= K ){
            const temp = str.slice(i).split("").reverse().join("")
            res.unshift(temp)
            break
        }
        if((i + 1) % K === 0){
            const temp = str.slice(i + 1 - K, i + 1).split("").reverse().join("")
            res.unshift(temp)
            index = i
        }
    }
    return res.join('-')
};
```