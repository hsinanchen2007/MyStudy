### 解题思路

reverse()翻转

### 代码

```javascript
/**
 * @param {number[][]} A
 * @return {number[][]}
 */
var flipAndInvertImage = function(A) {
    for (let i = 0; i < A.length; i++) {
        A[i].reverse()
        for (let j = 0; j < A[i].length; j++) {
            A[i][j] = A[i][j] === 0 ? 1 : 0
        }
    }
    return A
};
```