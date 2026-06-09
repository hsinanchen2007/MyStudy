## 就是求二维数组里面的最小值喽
```javascript
var maxCount = function(m, n, ops) {
    if(!ops.length) return m*n;
    let minM = Math.min.apply({},ops.map(item=>{return item[0]}))
    let minN = Math.min.apply({},ops.map(item=>{return item[1]}))
    return minM*minN;
};
```