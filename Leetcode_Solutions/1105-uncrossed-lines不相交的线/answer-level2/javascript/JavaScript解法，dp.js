### 解题思路
难点在于怎么创建一个空的二维数组 ` let newArr = Array.from(new Array(lens1), () => new Array(lens2))` 

### 代码

```javascript
/**
 * @param {number[]} A
 * @param {number[]} B
 * @return {number}
 */
var maxUncrossedLines = function(A, B) {
  let lens1 = A.length;
  let lens2 = B.length;
  let newArr = Array.from(new Array(lens1), () => new Array(lens2))
  for (let i = 0; i < lens1; i++) {
    for(let j = 0; j < lens2; j++) {
      if ( j==0 && i ==0 ) {
        newArr[i][j] = A[i] == B[j] ? 1:0
      } else if ( j == 0 && i > 0) {
        let temp1 = A[i] == B[j] ? 1:0;
        newArr[i][j] = Math.max(newArr[i-1][j], temp1)
      } else if ( j > 0 && i == 0) {
        let temp2 = A[i] == B[j] ? 1:0;
        newArr[i][j] = Math.max(newArr[i][j-1], temp2)
      } else {
        let temp3 = A[i] == B[j] ? 1:0;
        newArr[i][j] = Math.max(Math.max(newArr[i-1][j-1]+temp3, newArr[i-1][j]), newArr[i][j-1])
      }
    }
  }
  return newArr[lens1-1][lens2-1];

};
```