### 解题思路
1. 取首位值，作为标准
2. 然后和剩余的值做对比

### 代码

```javascript
/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
    if(!strs.length) return "";
    let val = strs.shift();
    let str = ''
    for(let i = 0; i < val.length; i++){
        let flag = strs.every(item => item[i] === val[i]);
        if(flag) {
            str += val[i];
        } else {
            break;
        }
    }
    return str;
};
```