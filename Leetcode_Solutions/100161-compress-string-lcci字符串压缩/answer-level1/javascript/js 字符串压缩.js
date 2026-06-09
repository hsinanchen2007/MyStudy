首先若字符串的长度小于2，则返回字符串本身；定义一个比较字符char为字符串的第一个字符，count为1，从第二个字符开始依次比较，若字符和char相同，则count++；若不同，则str加上char和count，char变为当前字符，count变为1；注意这样最后一个字符和它的个数没有加上，所以要在循环结束后再加上最后的char和count
```
/**
 * @param {string} S
 * @return {string}
 */
var compressString = function(S) {
    let len = S.length
    if (len < 2) return S
    let str = '', char = S[0], count = 1
    for(let i = 1; i < len; i++) {
        if (char === S[i]) {
            count++
        } else {
            str += char + count
            char = S[i]
            count = 1
        }
    }
    str += char + count
    return str.length < S.length ? str : S
};
```
