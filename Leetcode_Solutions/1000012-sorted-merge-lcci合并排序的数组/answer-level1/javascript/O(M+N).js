### 解题思路
由于数组 A、B 都是递增的，我们从 A、B 数组的最后一位向前遍历，较大的放到 A 数组较后位置。

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
    if (m === 0) {
        for (let i = 0; i < n; ++i) {
            A[i] = B[i];
        }
        return;
    }
    let indexA = m - 1, indexB = n - 1, lastIndex = m + n - 1;
    while (indexA >= 0 && indexB >= 0) {
        if (A[indexA] > B[indexB]) {
            A[lastIndex] = A[indexA];
            --indexA;
        } else {
            A[lastIndex] = B[indexB];
            --indexB;
        }
        --lastIndex;
    }
    for (let i = indexB; i >= 0; --i) {
        A[i] = B[indexB];
        --indexB;
    }
};
```

### 复杂度
- 时间复杂度 O(M+N)
- 空间复杂度 O(1)