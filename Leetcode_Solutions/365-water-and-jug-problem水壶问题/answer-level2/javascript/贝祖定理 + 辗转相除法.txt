### 解题思路
贝祖定理 + 辗转相除法
![image.png](https://pic.leetcode-cn.com/7f0dffa27d80695d2dce64470a803422f201ec2db32060c0a5bd5cb8d8f1d162-image.png)


### 代码

```javascript
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