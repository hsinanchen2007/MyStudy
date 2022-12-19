快速幂算法：
https://blog.csdn.net/qq_19782019/article/details/85621386

```js
/**
 * @param {number} N
 * @return {number}
 */
var fib = function(N) {
    if (N <= 1) return N

    function matrixPower(A, n) {
        const result = [[1, 0], [0, 1]] 
        while (n >= 1) {
            if (n%2 !== 0) {
                n -= 1       
                mutiply(result, A)
            }
            n = n/2
            mutiply(A, A)
        }

        return result
    }
    function mutiply(A, B) {
        a = A[0][0] * B[0][0] + A[0][1] * B[1][0]
        b = A[0][0] * B[0][1] + A[0][1] * B[1][1]
        c = A[1][0] * B[0][0] + A[1][1] * B[1][0]
        d = A[1][0] * B[0][1] + A[1][1] * B[1][1]

        A[0][0] = a
        A[0][1] = b
        A[1][0] = c
        A[1][1] = d
    }

    const matrix = [[1, 1], [1, 0]]
    const result = matrixPower(matrix, N-1)

    return result[0][0]
};
```
