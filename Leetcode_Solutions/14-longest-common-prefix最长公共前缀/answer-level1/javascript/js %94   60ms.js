/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
  if (strs.length === 0) return '';

  var first = strs[0];
  if (!first) {
    return '';
  }

  if (strs.length === 1) {
    return first;
  }

  var length = 0;

  function loop(len) {
    for (var i = 0; i < strs.length; i++) {
      if (strs[i].substr(0, len) != first.substr(0, len)) {
        return false;
      }
    }
    length = len;
    return true;
  }

  for (let i = 1; i < first.length + 1; i++) {
    var r = loop(i);
    if (!r) {
      break;
    }
  }

  return length > 0 ? first.substr(0, length) : '';
};