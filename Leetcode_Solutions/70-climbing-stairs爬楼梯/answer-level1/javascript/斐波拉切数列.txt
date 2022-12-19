```
var climbStairs1 = function(n) {
  if(n===1) return 1
  let f = 1, s = 2
  for(let i = 3; i <= n; i++) {
    let t = f + s
    f = s
    s = t
  }
  return s
};

```
