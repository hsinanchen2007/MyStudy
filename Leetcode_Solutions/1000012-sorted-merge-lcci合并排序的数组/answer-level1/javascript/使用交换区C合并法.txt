### 解题思路
此处撰写解题思路

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
    const C = []    // 储存A与B比较交换来的数据, c也是有序数组, 因为时A从左到右推入的
    for (let i = 0; i < m + n; i ++) {
        if(i >= m){ // 证明为占位符
            if(B[0] !== undefined && C[0] !== undefined) {
                if(B[0] > C[0]) {
                    A[i] = C.shift()
                } else {
                    A[i] = B.shift()
                }
            } else {
                if(B[0] !== undefined) {
                    A[i] = B.shift()
                } else {
                    A[i] = C.shift()
                }
            }
        } else if (B[0] !== undefined && A[i] > B[0]) { 
            if(C[0] !== undefined) {
                if(C[0] > B[0]) {
                    C.push(A[i])
                    A[i] = B.shift()
                } else {
                    const a = A[i]
                    A[i] = C.shift()
                    C.push(a)
                }
            } else {
                C.push(A[i])
                A[i] = B.shift()
            }
        }else if(C[0] !== undefined && C[0] < A[i]) {
            const a = A[i]
            A[i] = C.shift()
            C.push(a)
        }
    }
};
```