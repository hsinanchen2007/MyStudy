```
/**
 * @param {string} s
 * @return {number}
 */
var longestPalindrome = function (s) {
    let map = new Map(), res = 0, c = 0
    for (let i of s) {
        map.set(i, map.has(i) ? map.get(i) + 1 : 1)
    }
    map.forEach((v, k) => {
        if (v % 2 === 0) {
            res += v
        } else {
            res+=v-1
            c = 1
        }
    })
    return res+c
};
```
