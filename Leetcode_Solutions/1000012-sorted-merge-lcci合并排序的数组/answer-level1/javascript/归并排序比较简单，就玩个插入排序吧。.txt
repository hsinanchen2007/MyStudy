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

// 归并排序做过很多练习了... 
// 今天就来个不一样的... 来个插入排序算法思想吧 (Insertion Sort) 
var merge = function(A, m, B, n) {
    for (let i = 0, n = B.length; i < n; i++) {
        let j = m - 1 + i // j为A数组的尾指针...
        while (j >= 0 && B[i] < A[j]) {
            A[j + 1] = A[j] // 元素依次向后移动一个空间
            j--
        }
        A[j + 1] = B[i]
    }
};
```