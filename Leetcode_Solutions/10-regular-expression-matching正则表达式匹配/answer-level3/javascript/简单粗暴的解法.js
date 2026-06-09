var isMatch = function(s, p) {
  let reg = /[\.\*]/g;
  if (reg.test (p)) {
    var _reg = new RegExp (p, 'g');
    return _reg.test (s) && s.match (_reg)[0].length == s.length;
  } else {
    return s === p;
  }
};