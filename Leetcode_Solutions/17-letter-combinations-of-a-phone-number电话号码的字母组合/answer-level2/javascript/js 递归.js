```
/**
 * @param {string} digits
 * @return {string[]}
 */
const letterMap = [' ','','abc','def','ghi','jkl','mno','pqrs','tuv','wxyz']
var findCombinations = function(digits, index , s, res) {
    if (index == digits.length) {
        res.push(s)
        return 
    }
    let char = digits[index]
    let letters = letterMap[char]
    for(let i = 0; i< letters.length; i++){
        findCombinations(digits, index + 1, s + letters[i],res)
    }
    return
}
var letterCombinations = function(digits) {
    if(digits == '') return []
    let res = []
    findCombinations(digits, 0, '', res)
    return res
};
```
