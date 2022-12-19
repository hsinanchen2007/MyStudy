/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function(s) {
    // 创建一个映射表，并且将特殊六种组合分别转换给其他字符 
    let relativeObj = {
        I: 1,
        V: 5,
        X: 10,
        L: 50,
        C: 100,
        D: 500,
        M: 1000,
        A: 4, // IV
        B: 9, // IX
        Z: 40, // XL
        Y: 90, // XC
        N: 400, // CD
        W: 900 // CM
    }
    // 将s字符串中出现的六中组合做替换，替换称映射表中存在的字符
    s = s.replace(/(IV)/g, 'A').replace(/(IX)/g, 'B').replace(/(XL)/g, 'Z').replace(/(XC)/g, 'Y').replace(/(CD)/g, 'N').replace(/(CM)/g, 'W')
    // 做叠加
    return s.split('').reduce((rpe, next) => {
        return rpe + relativeObj[next]
    }, 0)
};