/**
 * @param {string} J
 * @param {string} S
 * @return {number}
 */
var numJewelsInStones = function(J, S) {
    /** 
     * split方法通过分隔符（空字符），将字符串转成数组
     * filter方法依次循环数组元素，若元素满足某条件（true），则添加到新数组，否则(false)不添加
     * includes判断s元素是否被包含在字符串J中
    */
    //两种方法等价
    //return S.split("").filter(s => J.includes(s)).length;
     return S.split("").filter(function(s){
        return J.includes(s);
     }).length;
};