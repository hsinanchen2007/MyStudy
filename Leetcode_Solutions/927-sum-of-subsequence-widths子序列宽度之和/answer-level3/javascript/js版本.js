```
/**
 * @param {number[]} A
 * @return {number}
 * 这是一个纯数学问题
 * 官方题解已经给出了数学推导
 */
const mod = BigInt(10 ** 9 + 7)
var sumSubseqWidths = function(A) {
    const n = A.length
    if(n === 1) return 0
    A.sort((a, b) => a - b)
    const powArr = new Array(n)
    // 这一步避免重复计算
    for(let i = 0; i < n; i++) powArr[i] =pow(i)
    let ans = 0n
    for(let i = 0; i < n; i++) {
        ans += ((powArr[i] - powArr[n - i - 1]) * BigInt(A[i]))
    }
    return ans % mod
};


// 这一步把会溢出的计算分解成不会溢出
function pow(len) {
    if(len > 52) {
        const half = (len / 2) | 0
        return pow(half) * pow(len - half)
    } else return BigInt(Math.pow(2, len))
}
```
