### 解题思路

先排序，再计算需要自增的值

### 代码

```javascript
/**
 * @param {number[]} A
 * @return {number}
 */
var minIncrementForUnique = function(A) {
    let res = 0, move
    A = A.sort((a,b) => a - b)
    for (let i = 0; i < A.length - 1; i++) {
        if (A[i] >= A[i + 1]) {
            move = A[i] + 1 - A[i + 1]
            A[i + 1] += move
            res += move
        }
    }
    return res
};
```