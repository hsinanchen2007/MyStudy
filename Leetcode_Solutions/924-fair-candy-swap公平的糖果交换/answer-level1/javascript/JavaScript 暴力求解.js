### 解题思路
- 通过 reduce（）迭代得出求和
- 两个数组的差值 == 2 * 交换的数值

### 代码

```javascript
/**
 * @param {number[]} A
 * @param {number[]} B
 * @return {number[]}
 */
var fairCandySwap = function(A, B) {
  let sum1 = A.reduce((prev,next) => prev + next)
  let sum2 = B.reduce((prev,next) => prev + next)
  let gap = (sum1 - sum2) / 2
  for (let i = 0; i < A.length; i++) {
    if(B.includes(A[i]-gap)){
      return [A[i],A[i]-gap]
    }
  }
};
```