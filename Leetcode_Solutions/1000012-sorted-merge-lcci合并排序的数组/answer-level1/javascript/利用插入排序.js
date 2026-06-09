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
 /*
    利用插入排序
    1、首先将两个数组合并为一个数组
    2、从B数组第一项在合并后的数组下标开始，依次插入到A数组中
*/
var merge = function(A, m, B, n) {
    if (B.length <= 0) {
        return
    }
    for (var i = m; i < m + n; i++) {
        A[i] = B.shift();
    }
    for (let i = m; i < A.length; i++) {
        let tmp = A[i]
        let j = i
        for (; j >= 0; j--) {
            if (tmp <= A[j - 1]) {
                A[j] = A[j - 1]
            } else {
                break
            }
        }
        A[j] = tmp
    }
};
```