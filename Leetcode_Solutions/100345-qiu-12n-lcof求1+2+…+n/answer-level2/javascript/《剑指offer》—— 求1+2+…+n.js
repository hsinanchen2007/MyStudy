// [戳我看原题](https://leetcode-cn.com/problems/qiu-12n-lcof/)  
// [戳我看原文](https://juejin.im/post/5e4a14c8e51d4526c26fb528)

// ## 题目描述

// 求 $1 + 2 +... + n$ ，要求不能使用乘除法、``for``、``while``、``if``、``else``、``switch``、``case`` 等关键字及条件判断语句（``A ? B : C``）

// ## 解题思路

// 通常求和无非是这几种写法：

// - 等差数列的前 $n$ 项和：$Sn = (a1 + an) * n / 2$
// - ``for`` 循环累加
// - 尾递归

// 然而题目中要求不能使用乘除法、``for``、``while``、``if``、``else``、``switch``、``case`` 等关键字及条件判断语句（``A ? B : C``），那么前面两种解法自然就被我们排除掉了，只能用尾递归。

// 为了方便理解，这里帮大家画个图👇


// ![](https://pic.leetcode-cn.com/972667eb23890d3a26dc89741363a8e7e389cbbbeabe8fd6f8c450433a9e29e7-file_1581915353847)


// ## 示例代码

// ```javascript
/**
 * @param {number} n
 * @return {number}
 */
var sumNums = function(n) {
    return n > 0 && (n + sumNums(n - 1))
};
// ```