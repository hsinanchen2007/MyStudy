``` javascript
/*
 * @lc app=leetcode.cn id=633 lang=javascript
 *
 * [633] 平方数之和
 */
/**
 * @param {number} c
 * @return {boolean}
 */
var judgeSquareSum = function(c) {
  let a = 0
  let b = Math.floor(Math.sqrt(c))
  while (a <= b) {
    let res = a * a + b * b
    if(res < c) {
      a++
    } else if (res > c){
      b--
    } else {
      return true
    }
  }
  return false
};
// ✔ Accepted
//   ✔ 124/124 cases passed (64 ms)
//   ✔ Your runtime beats 99.29 % of javascript submissions
//   ✔ Your memory usage beats 20.69 % of javascript submissions (34.8 MB)

```