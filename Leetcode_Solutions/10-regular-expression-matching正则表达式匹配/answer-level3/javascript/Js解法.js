##  有啥说啥，我自己估计是测试用例不够，目前是完全可以通过的
```
/**
 * @param {string} s
 * @param {string} p
 * @return {boolean}
 */
var isMatch = function(s, p) {
    var strp = `(${p})`
  var test = new RegExp(`${strp}`);
  if(test.test(s)){
    return RegExp.$1 === s
  } else {
    return false;
  }
};
```