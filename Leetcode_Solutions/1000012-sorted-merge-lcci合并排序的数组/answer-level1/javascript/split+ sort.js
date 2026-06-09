### 解题思路


### 代码

```javascript
/**
 * @param {number[]} A
 * @param {number} m
 * @param {number[]} B
 * @param {number} n
 * @return {void} Do not return anything, modify A in-place instead.
 */
var merge = function (A, m, B, n) {
    A.splice(m)
    B.splice(n)
    A.push(...B)
    let a = A.sort((a, b) => {
        if (a - b > 0) {
            return 1
        }
        if (a - b < 0) {
            return -1
        }
        if (a - b === 0) {
            return 0
        }

    })
    A.unshift(...a)
    A.splice(A.length / 2)
};
```