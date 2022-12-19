### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} s1
 * @param {string} s2
 * @return {boolean}
 */
var CheckPermutation = function(s1, s2) {
    const s2a = [...s2];
    for(let s of s1){
        const index = s2a.indexOf(s);
        if(index>=0){
            s2a.splice(index,1);
        }
    }
    return s2a.length==0;
};
```