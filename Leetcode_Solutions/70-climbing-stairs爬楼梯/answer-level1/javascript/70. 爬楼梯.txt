68 ms	33.7 MB
```
var climbStairs = function(n) {
    let arr = [1,1];
    for(let i = 2;i<=n;i++){
        arr[i] = arr[i-1]+arr[i-2];
    }
    return arr[n];
};
```
