### 解题思路
替换原数组多余项

### 代码

```javascript
/**
 * @param {number[]} A
 * @param {number} m
 * @param {number[]} B
 * @param {number} n
 * @return {void} Do not return anything, modify A in-place instead.
 */
var merge = function(A, m, B, n) {
    if(A.length < m || B.length < n){
        return null
    }
    for(let i = 0; i<B.length; i++){
        A[m+i] = B[i]
    }
    return A.sort((a,b) => a-b)
};
```