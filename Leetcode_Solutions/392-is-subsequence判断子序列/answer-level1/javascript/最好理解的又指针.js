### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isSubsequence = function(s, t) {
    
    let i=0
    let j=0
    let tLen=t.length
    let sLen=s.length
    
    if(s.length===0) return true

    for(let i=0;j<tLen;j++){
        if(s[i]===t[j]){
            if(++i>=sLen) return true
        }
    }
    return false
};
```