暴力解析
var romanToInt = function(s) {
    let result = 0
    const formatMap = {
        I: 1,
        V: 5,
        X: 10,
        L: 50,
        C: 100,
        D: 500,
        M: 1000
    }
    sArr = s.split('')
    for (var i=0;i<s.length;i++) {
        if(sArr[i] === 'C' && sArr[i+1] === 'D') {
            i++
            result += 400
        }
        else if(sArr[i] === 'C' && sArr[i+1] === 'M') {
            i++
            result += 900
        }
        else if(sArr[i] === 'X' && sArr[i+1] === 'L') {
            i++
            result += 40
        }
        else if(sArr[i] === 'X' && sArr[i+1] === 'C') {
            i++
            result += 90
        }
        else if(sArr[i] === 'I' && sArr[i+1] === 'V') {
            i++
            result += 4
        }
        else if(sArr[i] === 'I' && sArr[i+1] === 'X') {
            i++
            result += 9
        }
        else result += formatMap[sArr[i]]
    }
    return result
};