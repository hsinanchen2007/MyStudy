### 解题思路
定义两个数组存偶数和奇数，循环总长度分别赋值

### 代码

```javascript
/**
 * @param {number[]} A
 * @return {number[]}
 */
var sortArrayByParityII = function (A) {
  let arr_1 = [] // 存偶数
  let arr_2 = [] // 存奇数
  for (let i = 0; i < A.length; i++) {
    if (A[i] % 2 === 0) {
      arr_1.push(A[i])
    } else {
      arr_2.push(A[i])
    }
  }
  let result = []
  for (let i = 0; i < A.length; i++) {
    if (i % 2 === 0) {
      result[i] = arr_1[i / 2]
    } else {
      result[i] = arr_2[(i - 1) / 2]
    }
  }
  return result
}
```