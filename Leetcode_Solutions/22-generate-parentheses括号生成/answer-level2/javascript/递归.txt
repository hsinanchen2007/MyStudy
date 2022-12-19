思路：要保证生成括号的合法性
- 单边括号数量不能超过n
- 每次生成，右括号数量不能超过左括号。


```javascript []
/*
 * @lc app=leetcode.cn id=22 lang=javascript
 *
 * [22] 括号生成
 */

// @lc code=start
/**
 * @param {number} n
 * @return {string[]}
 */
var generateParenthesis = function (n) {

  let list = []

  function recursive(l, r, n, result) {
    //当左右括号数量都等于n时，生成结束
    if(l === n && r === n) return list.push(result)
    //生成合法括号
      if(l < n) {
        recursive(l + 1, r, n, result + '(')
      }
      if(r < n) {
        recursive(l, r + 1, n, result + ')')
      }
  }
  recursive(0, 0, n, "");
 
  return list;
}



```
