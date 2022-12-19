```
/*
 * @lc app=leetcode.cn id=9 lang=javascript
 *
 * [9] 回文数
 */
/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
    let x1 = String(x)
    let arr = x1.split('')
    if (arr.reverse().join('') == x1) return true
    return false
};
```