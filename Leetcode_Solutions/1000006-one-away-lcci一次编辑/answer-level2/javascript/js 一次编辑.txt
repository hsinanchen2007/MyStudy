1. 两个字符串长度相差大于1时不能一次编辑
2. 若两个字符串长度相同，则依次对比每个字符，累计不同字符的个数，若不同处超过一个，则不能一次编辑
3. 若字符串长度不同，解构获取较长的字符，取较大长度依次遍历，当两个字符不同时，判断较长字符串的该字符后的子串是否与较短字符串从该字符开始的子串相同，二者相同时才能只删除一个字符构成
```
/**
 * @param {string} first
 * @param {string} second
 * @return {boolean}
 */
var oneEditAway = function(first, second) {
    let count = 0, len1 = first.length, len2 = second.length
    if (Math.abs(len1 - len2) > 1) return false
    if (len1 === len2) {
        for(let i = 0; i < len1; i++) {
            if (first[i] !== second[i]) count++
            if (count > 1) return false
        }
    } else {
        let [long, short] = len1 > len2 ? [first, second] : [second, first]
        for(let i = 0; i < long.length; i++) {
            if (long[i] !== short[i]) {
                return long.slice(i+1) === short.slice(i)
            }
        }
    }
    return true
};
```
