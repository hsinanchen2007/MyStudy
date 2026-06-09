### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} astr
 * @return {boolean}
 */
var isUnique = function(astr) {
    for(let i=0;i<astr.length;i++){
        if(astr.indexOf(astr[i]) != astr.lastIndexOf(astr[i])){
            return false
        }
    }
    return true
};
```