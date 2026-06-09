```
/**
 * 可以将题意转化为，求所有牌数量的最大公约数是否大于等于2
 */

// 求最大公约数公式
const gcd = (a, b) => b === 0 ? a : gcd(b, a % b)

var hasGroupsSizeX = function(deck) {
    if (deck.length < 2) return false
    // 用一个数组计算每个数字，及其出现次数
    const counter = []
    for (let d of deck) {
        if (counter[d] === undefined) {
            counter[d] = 1
        } else {
            counter[d]++
        }
    }
    let prev = null
    // 遍历数组，求相邻两个牌的数量的最大公约数，小于2则return false
    for(let i = 0; i < counter.length; i++) {
        if (counter[i] === undefined) continue
        if (counter[i] < 2) return false
        if (prev === null) {
            prev = counter[i]
        } else {
            if (gcd(prev, counter[i]) < 2) return false
            prev = counter[i]
        }
    }
    return true
};
```