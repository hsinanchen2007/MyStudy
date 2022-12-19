/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
   return s.replace(/\s+/g,' ').trim().split(' ').reverse().join(' ');
};