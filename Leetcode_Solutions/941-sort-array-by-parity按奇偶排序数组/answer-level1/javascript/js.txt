### 解题思路
定义一个指针（i）从第一项开始判断，如果是奇数就放到后面，否则指针向后移一位
定义一个变量（a）判断移动次数结束循环

### 代码

```javascript
/**
 * @param {number[]} A
 * @return {number[]}
 */
var sortArrayByParity = function (A) {
  let a = 0
  for (let i = 0; a < A.length - 1; a++) {
    if (A[i] % 2 !== 0) {
      A.push(A[i])
      A.splice(i, 1)
    } else {
      i++
    }
  }
  return A
}
```