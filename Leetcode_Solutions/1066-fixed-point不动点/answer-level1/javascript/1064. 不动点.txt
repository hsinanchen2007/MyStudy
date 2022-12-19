### 解题思路

- 如果 $A[mid] >= mid$，说明最小的索引 ``i`` 在左侧
- 如果 $A[mid] < mid$，说明最小的索引 ``i`` 在右侧

以上推论基于题目中给出的条件：``数组 A`` 按升序排列（注意代码中的边界条件判断）

### 代码

```javascript
/**
 * @param {number[]} A
 * @return {number}
 */
var fixedPoint = function(A) {
    let lo = 0
    let hi = A.length - 1
    while (lo <= hi) {
        let mid = Math.floor((lo + hi) >> 1)
        if (A[mid] >= mid) {
            hi = mid - 1
        } else if (A[mid] < mid) {
            lo = mid + 1
        }
    }
    return A[lo] === lo ? lo : -1
};
```