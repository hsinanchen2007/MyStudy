```js
var largestSumAfterKNegations = function(A, K) {
    // 从小到大排序
    A.sort((a, b) => a - b)
    // 将数组中的负数尽可能的变成正数
    for (let i = 0; i < A.length; i++) {
        if (A[i] < 0 && K > 0) {
            A[i] = -A[i];
            K--
        }
    }
    // 再次从小到大排序
    A.sort((a, b) => a - b)
    // 当数组没有0时，且 K 为奇数，我们不得不把最小的一个的正数变成负数
    if (K % 2 !== 0 && A.indexOf(0) == -1) {
        A[0] = -A[0]
    }
    // 数组求和
    let sum = 0;
    A.forEach((item) => {
        sum += item
    })
    return sum
};
```