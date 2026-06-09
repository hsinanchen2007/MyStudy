```
/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
    if (!strs.length) return ''
    const minLength = Math.min(...strs.map(item => item.length))
    let commonPre = ''
    for (let i=0; i<minLength; i++) {
        const isSame = strs.every(item => item[i] === strs[0][i])
        if (isSame) commonPre += strs[0][i]
        else break
    }
    return commonPre
};
```
首先找到数组中字符串的最短长度，即最大循环次数
循环判断每个字符是否相等，以数组中第一个字符串为参照