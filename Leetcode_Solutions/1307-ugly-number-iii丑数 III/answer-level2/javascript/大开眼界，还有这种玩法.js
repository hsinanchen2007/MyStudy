```
/**
 * @param {number} n
 * @param {number} a
 * @param {number} b
 * @param {number} c
 * @return {number}
 */
var nthUglyNumber = function(n, a, b, c) {
    let low = BigInt(Math.min(a, b, c))
    let high = 2n * (10n ** 9n)
    let A = BigInt(a)
    let B = BigInt(b)
    let C = BigInt(c)
    const N = BigInt(n)
    while(low < high) {
        const mid = (low + high) / 2n
        let count = (mid / A) + (mid / B) + (mid / C)
        count  = count - (mid / mcm(A, B)) - (mid / mcm(C, B)) - (mid / mcm(A, C)) + (mid / mcm(A, mcm(B, C)))
        if(count < N) {
            low = mid + 1n
        } else high = mid
    }
    return low
};

function mcm (a, b) {
    let temp = a * b
    while(b !== 0n) {
        let t = a % b
        a = b 
        b = t
    }
    return temp / a
}
```
