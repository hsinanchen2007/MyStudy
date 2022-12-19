/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
    return s.replace(/\s+/g, ' ').replace(/\s$/, '').replace(/^\s/, '').split(' ').reverse().join(' ')
};