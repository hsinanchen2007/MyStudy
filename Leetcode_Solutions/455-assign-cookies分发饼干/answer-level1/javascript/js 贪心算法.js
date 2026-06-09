// ### 解题思路
// 每次尝试把最大的饼干给最贪心的小盆友，如果可以满足他，饼干给他，用次大的饼干尝试给次贪心的小盆友；如果不能满足他，那么小盆友，再见👋

// ### 代码

// ```javascript
/**
 * @param {number[]} g
 * @param {number[]} s
 * @return {number}
 */
var findContentChildren = function(g, s) {
    const gLen = g.length
    const sLen = s.length
    if (!gLen || !sLen) {
        return 0
    }
    g.sort((a, b) => b - a)
    s.sort((a, b) => b - a)
    let count = 0
    let i = 0
    let j = 0
    while (i < sLen && j < gLen) {
        if (s[i] >= g[j]) {
            count ++
            i ++
        }
        j ++
    }
    return count
};
// ```