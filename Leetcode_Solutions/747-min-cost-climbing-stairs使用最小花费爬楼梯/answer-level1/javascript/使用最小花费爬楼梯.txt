动态规划

f(n) = min(f(n-1), f(n-2)) + cost[n]

```js
var minCostClimbingStairs = function(cost) {
    
    let len = cost.length;
    let arr = [];
    arr[0] = cost[0];
    arr[1] = cost[1];

    for(let i = 2; i < len; i++) {
        arr[i] = Math.min(arr[i-1] , arr[i-2]) + cost[i]
    }

    return Math.min(arr[len-1], arr[len-2]);
};
```

