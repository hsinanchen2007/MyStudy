### 解题思路

- 计算 ``数组`` 的和
- 如果 ``sum % 3 !== 0``，说明和不能三等分，直接返回 ``false``
- 如果 ``sum % 3 === 0``，那么重新遍历一次数组
    - 令一个临时变量为 ``0``
    - 叠加临时变量，直至它等于 ``avarage``，``count`` 自增 ``1``
    - 遍历结束后如果 ``count >= 3``，说明数组能被分成和相等对三个部分
### 代码

```javascript
/**
 * @param {number[]} A
 * @return {boolean}
 */
var canThreePartsEqualSum = function(A) {
    let sum = A.reduce((prev, curr) => prev + curr)
    if (sum % 3 !== 0) {
        return false
    }
    let average = sum / 3
    let prev = 0
    let count = 0
    for (let i = 0; i < A.length; i++) {
        prev += A[i]
        if (prev === average) {
            prev = 0
            count++
        }
    }
    return count >= 3
};
```