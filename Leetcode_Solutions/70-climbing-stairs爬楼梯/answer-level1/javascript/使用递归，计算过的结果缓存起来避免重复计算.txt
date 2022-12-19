```
let arr = [];
arr[1] = 1;
arr[2] = 2;
var climbStairs = function(n) {
    if(n === 1) return 1;
    if(n === 2) return 2;
    
    let temp = arr[n] ? arr[n] : climbStairs(n- 1) + climbStairs(n - 2);
    
    arr[n] = temp;
    return temp;
};
```
