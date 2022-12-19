var lengthOfLastWord = function (s) {
  let str = /(?=\w+\s*$)\w+/.exec(s)
  return str === null ? 0 : str[0].length
};