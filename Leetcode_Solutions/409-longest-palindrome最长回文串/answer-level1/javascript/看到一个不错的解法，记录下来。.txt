/**
 * @param {string} s
 * @return {number}
 */
var longestPalindrome = function(s) {
    let charTimeArr = Array(58).fill(0);
    for(let char of s) {
        charTimeArr[char.charCodeAt() - 65] += 1;
    }
    let maxSize = 0;
    for(let time of charTimeArr) {
        maxSize += parseInt((time/2),10) *2
    }
    return maxSize < s.length? maxSize + 1: maxSize
};