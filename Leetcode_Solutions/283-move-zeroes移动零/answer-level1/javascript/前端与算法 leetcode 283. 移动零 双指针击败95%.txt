[TOC]
# 前端与算法 leetcode 283. 移动零
---

## 题目描述
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

示例:
```
输入: [0,1,0,3,12]
输出: [1,3,12,0,0]
```
说明:

1.  必须在原数组上操作，不能拷贝额外的数组。
2.  尽量减少操作次数。

[283. 移动零](https://leetcode-cn.com/problems/move-zeroes/)

## 概要

这个问题属于 “数组变换” 的一个广泛范畴。这一类是技术面试的重点。主要是因为数组是如此简单和易于使用的数据结构。遍历或表示不需要任何样板代码，而且大多数代码将看起来像伪代码本身。[[1]]

问题的要求很简单,将所有0移动到数组末尾且非0元素必须保持其原始顺序

## 提示

双指针,暴力法

## 解析

有意思的是,正常设计的算法,在遇到`[0,0,0,0,1],[1,0,0,0,0,1]`这两种数组的时候都比较尴尬,没办法有效的减少操作次数,这两个需求是相互排斥的,但是我们可以尽可能的在其中找到平衡

### 解法一:暴力法
暴力法使用一个`额外的数组`,先将所有非0元素按照原顺序push到数组里同时用`count`统计0出现的次数,然后在`额外的数组`里再push`count`个0,按照题目的要求我们需要在原来的数组上改动,所以再依次将数组元素填入原数组

<!-- #### 复杂度分析
*   时间复杂度:O(n)
*   空间复杂度:O(n) -->

### 解法二:双指针法
前一种方法有一些额外的操作.例如,所有(除最后一个)前导零的数组:`[0,0,0,1]`就会对数组进行许多不必要的操作,如果只固定非0元素的话,可以只交换一次
## 算法

```js
/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var moveZeroes = function (nums) {
  // 双指针法
  for (let [i, j] = [0, 0]; i < nums.length; i++) {
    if (nums[i] !== 0) {
      [nums[j], nums[i]] = [nums[i], nums[j]]
      j++
    }
  }
  // 暴力法
  // let count = 0 // 统计0的个数
  // const res = [] // 返回的数组
  // nums.forEach(el => el === 0 ? count++ : res.push(el))
  // for (let i = 0; i < count; i++) {
  //   res.push(0)
  // }
  // for (let i = 0; i < nums.length; i++) {
  //   nums[i] = res[i]
  // }
}
```

## 传入`[0,1,0,3,12]`的运行结果

```sh
[1,3,12,0,0]
```

## 执行结果

```
执行用时 :68 ms, 在所有 javascript 提交中击败了95.54%的用户
内存消耗 :37.2 MB, 在所有 javascript 提交中击败了5.10%的用户
```

## GitHub仓库

[350. 两个数组的交集 II](https://github.com/moshuying/AlgorithmAndBlog)
<!-- ## 引用列表 -->
<!-- leetcode,leetcode-cn,[J],283. 两个数组的交集 II, -->
[1]:https://leetcode-cn.com/problems/move-zeroes/solution/yi-dong-ling-by-leetcode/