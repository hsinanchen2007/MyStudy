
var reverseWords = function(s) {
   return s.replace(/(^\s+)|(\s+$)/g, '').replace(/\s{2,}/g, ' ').split(" ").reverse().join(' ')
};

