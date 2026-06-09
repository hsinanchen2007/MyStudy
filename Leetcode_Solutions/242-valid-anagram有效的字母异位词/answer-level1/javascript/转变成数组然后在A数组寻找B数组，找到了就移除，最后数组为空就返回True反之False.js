### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function(s, t) {
    if(s.length!=t.length)return false;
    const sarr=[...s], tarr=[...t];
    while(sarr.length){
        const ele = sarr.shift();
        const index = tarr.indexOf(ele);
        if(index<0)return false;
        tarr.splice(index,1);
    }
    return !tarr.length;
};
```