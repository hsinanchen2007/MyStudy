```
var climbStairs = function(n, arr=[]) {
  if(n===2) return 2
  if(n===1) return 1
  if(arr[n]) {
    return arr[n]
  }
  arr[n] = climbStairs(n-1,arr) + climbStairs(n-2,arr)
  return arr[n]
};

```
