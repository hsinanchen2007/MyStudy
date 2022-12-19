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
    if (!n) return;
    A.splice(-1*n);
    B.forEach(v => A.push(v));
    A.sort((a, b)=> a-b)
    return A
};
```