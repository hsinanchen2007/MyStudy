### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} n
 * @return {number[]}
 */
var printNumbers = function(n) {
    if(n == 0) return []
    let str = ''
    let res = []
    for(let i=0; i<n; i++){
        str += '9'
    }
    str = str * 1
    for(let j=0; j<str; j++){
        res.push(j+1)
    }
    return res
};
```