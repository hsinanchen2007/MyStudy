[TOC]
# 前端与算法 leetcode 66. 加一
---
# 题目描述
给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。

示例 1:
```
输入: [1,2,3]
输出: [1,2,4]
解释: 输入数组表示数字 123。
```
示例 2:
```
输入: [4,3,2,1]
输出: [4,3,2,2]
解释: 输入数组表示数字 4321。
```

[66. 加一](https://leetcode-cn.com/problems/plus-one/)
# 概要
考虑一下进位情况即可,新建一个空数组,长度是传入数组的长度+1,然后给第一个位+1返回此数组即可
# 提示
# 解析
## 解法一
题的意思只是加一,这意味着它的情况只有两种,末位为9或不为9

末位为9时加一位时进位为0,如果不出现进位运算时结束循环

考虑特殊情况99,99999等,手动创建数组填入0
## 解法二
从后往前依次给每个数加一,加一后大于10则对10取余,一直到数组的头部的时候`i===0`数组头部加入一位1即可

### 算法
```js
/**
 * @param {number[]} digits
 * @return {number[]}
 */
var plusOne = function(digits) {
  for (let i = digits.length - 1; i >= 0; i--) {
    digits[i]++
    digits[i] = digits[i] % 10
    if (digits[i] !== 0) return digits
  }
  digits = new Array(digits.length + 1).fill(0)
  digits[0] = 1
  return digits
  // 解法2
  // for (let i = digits.length - 1; i >= 0; i--) {
  //   digits[i]++
  //   if (digits[i] >= 10) {
  //     digits[i] = digits[i] % 10
  //     if (i === 0) {
  //       digits.unshift(1)
  //       break
  //     }
  //   } else {
  //     break
  //   }
  // }
  // return digits
};
```
传入`[1,2,3]`的运行结果
```sh
[1,2,4]
```
执行结果
```sh
执行用时 :44 ms, 在所有 javascript 提交中击败了100.00% 的用户
内存消耗 :33.7 MB, 在所有 javascript 提交中击败了33.81%的用户
```
## GitHub仓库

[48. 旋转图像](https://github.com/moshuying/AlgorithmAndBlog/)