### 解题思路
由于确保A有足够的空间，那么最终A中元素的长度为 m+n，从这个索引位置p开始，利用双指针在A、B中从后往前遍历，较大者放入p的位置，p往前移动。

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
    let i = m - 1, j = n - 1, p = m + n - 1;
    while (i >= 0 && j >= 0) {
        if (A[i] >= B[j]) {
            A[p--] = A[i--];
        } else {
            A[p--] = B[j--];
        }
    }
    while (i >= 0) {
        A[p--] = A[i--];
    }
    while (j >= 0) {
        A[p--] = B[j--];
    }
};
```