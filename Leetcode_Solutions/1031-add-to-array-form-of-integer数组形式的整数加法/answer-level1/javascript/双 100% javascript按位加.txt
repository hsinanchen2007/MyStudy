### 解题思路
执行用时 : 112 ms, 在所有 JavaScript 提交中击败了 100.00% 的用户
内存消耗 : 38.2 MB , 在所有 JavaScript 提交中击败了 100.00% 的用户

### 代码

```javascript
/**
 * @param {number[]} A
 * @param {number} K
 * @return {number[]}
 */
var addToArrayForm = function (A, K) {
  let len = A.length
  let k = K

  while (len-- && k > 0) {
    let sum = A[len] + k
    A[len] = sum % 10

    k = Math.floor(sum / 10)
  }
  if (len < 0 && k > 0) {
    return String(k).split('').map(item => parseInt(item)).concat(A)
  }
  else {
    return A
  }

};
```