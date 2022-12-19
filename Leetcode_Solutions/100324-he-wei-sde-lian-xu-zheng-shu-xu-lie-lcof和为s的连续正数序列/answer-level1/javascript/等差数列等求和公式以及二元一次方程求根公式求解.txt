### 解题思路

运用等差数列等求和公式以及二元一次方程求根公式求解。

### 代码

```javascript
/**
 * @param {number} target
 * @return {number[][]}
 */
var findContinuousSequence = function(target) {
  let res = [];
  
  for (let i = 1; i<= Math.floor(target / 2); i++) {
    let delta = 1-4*(-1*i*i + i - 2*target);
    // √delta 为整数，并且分母为偶数
    let sqrt = Math.sqrt(delta);
    if (Math.floor(sqrt) === sqrt && (-1 + sqrt) % 2 == 0) {
      // 判断根是否为整数
      let arr = [];
      // 求出整数根
      let extra = (-1 + sqrt) / 2;
      for (let j = i; j <= extra; j++) {
        arr.push(j);
      }
      res.push(arr);
    }
  }
  return res;
};
```