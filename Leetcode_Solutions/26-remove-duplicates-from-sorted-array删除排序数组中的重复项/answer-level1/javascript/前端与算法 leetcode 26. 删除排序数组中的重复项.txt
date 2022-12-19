[TOC]
# 前端与算法 leetcode 26. 删除排序数组中的重复项
---
# 题目描述
[26. 删除排序数组中的重复项](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/submissions/)
# 概要
一提到原地删除数组,就能立即想到双指针法,但是也可以用Set法去解决
# 提示
双指针,Set
# 解析

### 解法一:慢慢来

这道题难度较低,慢慢来也能解出来

## 解法二:Set法
上面那个解法不够js,实际中可以使用Set法,在js中这两种方法速度相差不大,但是Set方法更吃内存,看实际情况使用

### 算法
```js
/**
 * @param {number[]} nums
 * @return {number}
 */
const removeDuplicates = (nums) => {
  // Set法
  let temp = [...new Set(nums)];
  for (let i = 0;i < temp.length;i++) {
    nums[i] = temp[i];
  }
  return temp.length;
  // 原解法
  // if (nums.length === 0) {return 0;}
  // if (nums.length === 1) {return 1;}
  // if (nums.length < 2 && nums[0] !== nums[1]) {return 2;}
  // let i = 0;
  // for (let j = 1; j < nums.length; j++) {
  //   if (nums[j] !== nums[i]) {
  //     nums[++i] = nums[j];
  //   }
  // }
  // return i + 1;
};
```
传入`112`的运行结果
```sh
2
```
执行结果
```sh
执行用时 :72 ms, 在所有 javascript 提交中击败了98.73% 的用户
内存消耗 :36.4 MB, 在所有 javascript 提交中击败了92.29%的用户
```

### GitHub仓库

[7. 整数反转](https://github.com/moshuying/AlgorithmAndBlog)