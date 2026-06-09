### 解题思路
- 通过 reverse(), 对每一行的数组进行翻转
- 然后对二维数组进行遍历 判断为0，则重新赋值为1； 

### 代码

```javascript
/**
 * @param {number[][]} A
 * @return {number[][]}
 */
var flipAndInvertImage = function(A) {
    let R = A.length
    let C = A[0].length
    for (let i = 0; i < R; i++) {
        A[i].reverse()
    }
    for (let i = 0; i < R; i++) {
        for (let j = 0; j < C; j++) {
            if (A[i][j] === 0) {
                A[i][j] = 1
            } else {
                A[i][j] = 0
            }
        }
    }
    return A
};
```