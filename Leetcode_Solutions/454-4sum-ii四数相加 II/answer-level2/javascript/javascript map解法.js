### 解题思路
将任意两个数组(比如C，D)各取出一个数的和作为key,求得这个和的所有可能数量作为value存入一个map，然后判断A,B各取一个数，如果0 - A[i] - B[j]在map中可以找到，则最终计数加上对应的value

### 代码

```javascript
/**
 * @param {number[]} A
 * @param {number[]} B
 * @param {number[]} C
 * @param {number[]} D
 * @return {number}
 */
 var fourSumCount = function(A, B, C, D) {
    const N = A.length
    if (!N) {
        return 0 
    }
    let count = 0
    const map = new Map()
    for (let i = 0; i < N; i++) {
        for (let j = 0; j < N; j++) {
            const sum = C[i] + D[j]
            if (!map.has(sum)) {
                map.set(sum, 1)
            } else {
                map.set(sum, map.get(sum) + 1)
            }
        }
    }
    for (let i = 0; i < N; i++) {
        for (let j = 0; j < N; j++) {
            const sumCD = 0 - A[i] - B[j]
            if (map.has(sumCD)) {
                count += map.get(sumCD)
            }
        }
    }
    return count
};
```