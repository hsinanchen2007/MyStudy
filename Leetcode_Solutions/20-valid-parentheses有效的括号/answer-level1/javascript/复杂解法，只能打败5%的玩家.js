/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    let str = s.trim()
    if(!str) return true
    const listMap = {
        '(': ')',
        '[': ']',
        '{': '}'
    }
    var getLeastStr = (currStr) => {
        leastStr = ''
        for (let i=0;i<currStr.length;i++){
            if (listMap.hasOwnProperty(currStr[i]) && currStr[i+1] === listMap[currStr[i]]) continue;
            if (listMap.hasOwnProperty(currStr[i-1]) && currStr[i] === listMap[currStr[i-1]]) continue;
            leastStr += currStr[i]
        }
        if (leastStr === currStr) return false
        else if (leastStr === '') return true
        return getLeastStr(leastStr)
    }
    return getLeastStr(str)
};

看看，使用了递归。
思路是一层层剥离相邻的匹配括号