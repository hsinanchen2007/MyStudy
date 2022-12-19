### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var balancedStringSplit = function(s) {
    let num = 0;
    let res = 0;
    for(let i = 0; i < s.length; i++){
        if(s[i] == 'R') num++;
        else num--;
        if(num == 0) res++;
    }
    return res;
};
```