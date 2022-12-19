```
/**
 * @param {number} n
 * @return {number}
 */
var map = {
  0: 1,
  1: 1
}
var climbStairs = function(n) {
  if(map[n] !== undefined) return map[n]
  map[n] = climbStairs(n-1) + climbStairs(n-2)
  return map[n]
};
```
