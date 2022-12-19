```
/**
 * @param {string} S
 * @param {string[]} words
 * @return {number}
 */
var expressiveWords = function(S, words) {
    const {code: sCode, counts: sCounts} = getCode(S)
    let ans = 0
    for(let i = 0;i < words.length;i++) {
        const {code, counts} = getCode(words[i])
        if(code !== sCode) continue
        let add = true
        for(let i = 0;i < counts.length;i++) {
            if(counts[i] > sCounts[i]) {
                add = false
                break
            }else if((counts[i] < sCounts[i]) && (sCounts[i] < 3)) {
                add = false
                break
            }
        }
        if(add) ans++
    }
    return ans
};
function getCode(str) {
    let code = ''
    const counts = []
    let pre = -1
    for(let i = 0;i < str.length;i++) {
        if((i === (str.length - 1)) || (str[i] !== str[i + 1])) {
            code += str[i]
            counts.push(i - pre)
            pre = i
        }
    }
    return {code, counts}
}
```
