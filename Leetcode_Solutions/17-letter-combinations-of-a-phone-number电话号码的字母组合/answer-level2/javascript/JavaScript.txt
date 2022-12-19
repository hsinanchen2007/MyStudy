```
/**
 * @param {string} digits
 * @return {string[]}
 */
const mapping = {
    '2':['a','b','c'],
    '3':['d','e','f'],
    '4':['g','h','i'],
    '5':['j','k','l'],
    '6':['m','n','o'],
    '7':['p','q','r','s'],
    '8':['t','u','v'],
    '9':['w','x','y','z']
}
var letterCombinations = function(digits) {
    // Init
    let res = mapping[digits[0]] || []
    const end = digits.length
    // Processing
    for (let di=1; di<end; di++) {
        const nextRes = []
        const patterns = mapping[digits[di]]
        for (let p of patterns) {
            for (let r of res) {
                nextRes.push(r+p)
            }
        }
        res = nextRes
    }
    return res
    
};
```
