```
var maxCount = function(m, n, ops) {
    let [x, y] = ops.reduce((pre, cur)=>{
        return [Math.min(pre[0], cur[0]), Math.min(pre[1], cur[1])];
    }, [m, n]);
    return x * y;
};
```
