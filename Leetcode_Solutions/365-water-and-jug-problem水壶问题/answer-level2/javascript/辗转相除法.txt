```
var canMeasureWater = function(x, y, z) {
  if (x + y < z) {
    return false
  }
  if (x * y === 0) {
    return z === x + y || z === 0
  }
  function gcd (x, y) {
    if (x % y === 0) {
      return y
    } else {
      return gcd(y, x % y)
    }
  }
  let min
  let max
  if (x > y) {
    max = x
    min = y
  } else {
    max = y
    min = x
  }
  return z % gcd(max, min) === 0
};
```
