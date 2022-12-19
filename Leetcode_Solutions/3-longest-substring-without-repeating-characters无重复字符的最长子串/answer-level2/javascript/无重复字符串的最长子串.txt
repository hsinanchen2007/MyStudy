```
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function (s) {
    let subs = ''
    let maxLength = 0
    let sLen = s.length
    for (let i = 0; i < sLen; i++) {
        let repeatIndex = subs.indexOf(s[i])
        subs += s[i]
        if (repeatIndex > -1) {
            // 当存在重复，从重复处截取
            subs = subs.slice(repeatIndex + 1)
        } else {
            // 不用Math.max，能提升一点性能
            if (subs.length > maxLength) {
                maxLength = subs.length
            }
        }
    }
    return maxLength;
};
```
