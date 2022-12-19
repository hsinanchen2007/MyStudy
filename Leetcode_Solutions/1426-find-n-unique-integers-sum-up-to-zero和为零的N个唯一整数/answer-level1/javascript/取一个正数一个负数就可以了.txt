### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} n
 * @return {number[]}
 */
var sumZero = function(n) {
    const res = [];
    let m=Math.trunc(n/2);
    for(let i=1; i<=m; i++){
        res.push(i, -i);
    }
    if(n%2!=0)res.push(0);
    return res;
};
```