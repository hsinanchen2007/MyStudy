/**
 * @param {string} s
 * @return {number}
 */
先遍历定义一个正则，然后replace替换，虽然没打败多少人，但觉得这个代码量少，
var romanToInt = function(s) {
  let rate = {
    IV: 4,
    IX: 9,
    XL: 40,
    XC: 90,
    CD: 400,
    CM: 900,
    I: 1,
    V: 5,
    X: 10,
    L: 50,
    C: 100,
    D: 500,
    M: 1000
  };
  var regStr = "";
  for (let item in rate) {
    regStr += "(" + item + ")|";
  }
  var num = 0;
  regStr = regStr.substring(0, regStr.length - 1);
  var reg = new RegExp(regStr, "g");
  s.replace(reg, function(a) {
    return (num += rate[a] * 1);
  });
  return num;
};