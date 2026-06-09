```
/**
 * 我们要将n拆成尽可能多的3，剩下的余数若为1，则加入3变成4，若为2，则直接相乘
 * @param {number} n
 * @return {number}
 */
const cuttingRope = function(m) {
    let n = BigInt(m)
    const modNum = 1000000007n
    if (n === 1n || n === 2n) {
        return 1n
    }
    if (n === 3n) {
        return 2n
    }

    const mod = n % 3n
    const time = n / 3n
    if (mod === 0n) {
        return (3n ** time) % modNum
    } else if (mod === 1n) {
        return 4n * (3n ** (time - 1n)) % modNum
    } else {
        return 2n * (3n ** time) % modNum
    }
}
```
