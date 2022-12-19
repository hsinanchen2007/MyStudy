function getEachDigit(n) {
    let arr = [];
    while(n>0) {
        arr.push(n%10);
        n = Math.floor(n/10);
    }
    return arr
}
/**
 * @param {number} n
 * @return {number}
 */
var subtractProductAndSum = function(n) {
    let arr = getEachDigit(n);
    return arr.reduce((pre, cur) => {return pre * cur}, 1) - arr.reduce((pre, cur) => {return pre+cur}, 0)
};