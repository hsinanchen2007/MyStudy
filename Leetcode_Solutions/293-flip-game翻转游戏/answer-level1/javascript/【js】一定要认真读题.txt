/**
 * @param {string} s
 * @return {string[]}
 */
var generatePossibleNextMoves = function(s) {
    let result  = []
    s= s.split('')
    if(!s.includes('+')) {
        return []
    }
    for (var i = 0; i< s.length; i++) {
        if(s[i]===s[i+1]) {
            const ss = [...s]
            if(s[i] === "+") {
                ss[i] =ss[i+1] = '-'
                result.push(ss.join(''))
            }
        }
    }
    return result
};