### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} str
 * @return {string}
 */
var toLowerCase = function(str) {
    const res = [];
    for(let c of str){
        if(!/[a-zA-Z]/.test(c)){
            res.push(c);
            continue;
        }
        const cc = c.charCodeAt();
        const after = (cc>96&&cc<123) ? c : String.fromCharCode(cc+32);
        res.push(after);
    }
    return res.join('');
};
```