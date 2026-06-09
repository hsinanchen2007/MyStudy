### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} astr
 * @return {boolean}
 */
var isUnique = function(astr) {
    if(astr.length==1)return true;
    const map = [...astr].reduce((a, b)=>{
        if(!a[b])a[b]=1;
        else a[b]+=1;
        return a;
    }, {});
    const keys = Object.keys(map);
    for(let o of keys)if(map[o]!=1)return false;
    return true;
};
```