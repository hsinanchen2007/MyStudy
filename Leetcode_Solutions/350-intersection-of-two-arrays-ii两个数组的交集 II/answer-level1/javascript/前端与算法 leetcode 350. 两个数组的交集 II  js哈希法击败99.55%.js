[TOC]
# 前端与算法 leetcode 350. 两个数组的交集 II
---
# 题目描述
给定两个数组，编写一个函数来计算它们的交集。

示例 1:
```
输入: nums1 = [1,2,2,1], nums2 = [2,2]
输出: [2,2]
```
示例 2:
```
输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出: [4,9]
```
说明：

*    输出结果中每个元素出现的次数，应与元素在两个数组中出现的次数一致。
*    我们可以不考虑输出结果的顺序。

进阶:

*    如果给定的数组已经排好序呢？你将如何优化你的算法？
*    如果 nums1 的大小比 nums2 小很多，哪种方法更优？
*    如果 nums2 的元素存储在磁盘上，磁盘内存是有限的，并且你不能一次加载所有的元素到内存中，你该怎么办？

[350. 两个数组的交集 II](https://leetcode-cn.com/problems/intersection-of-two-arrays-ii/)
# 概要
这道题可以看成一道传统的映射题,我们需要知道每个值出现的次数,映射关系为<元素,出现次数>,首先统计数组1中所有元素出现的次数,再遍历数组2即可,如果数组2中的元素存在且大于1,则表示已经找到一个相同的了,如果值等于1,直接删除[1](https://leetcode-cn.com/problems/intersection-of-two-arrays-ii/solution/wei-shi-yao-yong-map-by-vailing-2/)
# 提示
哈希表,双指针,暴力
# 解析
## 解法一：哈希表
时间复杂度O(n)
先用Hashmap记录第一个数组中的元素【放在key】，和出现的次数【放在value】。然后再遍历第二个数组，如果找到对应元素，则添加这个元素到返回数组里。如果value值大于1，HashMap中的value值减 1，表示已经找到一个相同的了。如果value值等于1，则删除该元素。[2](https://leetcode-cn.com/problems/intersection-of-two-arrays-ii/solution/js-xie-leetcode-by-zhl1232/)
## 解法二:双指针
将两个数组排序,两个指针初始值为0,比较两个指针的元素是否相等相等则放到返回数组里,两个指针同时往前,不相等元素小的指针往前,如果相等,那肯定比较过的元素就没用了,两个指针往前,不相等的时候**因为较大的元素在较小的数组里存在**所以把元素小的数组指针往前
## 解法三:暴力法
时间复杂度O(n^2)
遍历第一个数组,然后再第二个数组查找`indexOf`是否有当前元素

### 算法
```js
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersect = function (nums1, nums2) {
// hash法
  const [hash,res] = [new Map(),[]]
  nums1.forEach(el=>{
    if (hash.has(el)) {
      hash.set(el, hash.get(el) + 1)
    } else {
      hash.set(el, 1)
    }
  })
  nums2.forEach(el=>{
    const hashKey = hash.get(el)
    if (hash.has(el)) {
      res.push(el)
      if (hashKey > 1) {
        hash.set(el, hashKey - 1)
      } else {
        hash.delete(el)
      }
    }
  })
  return res
//   // 双指针法
//   let p1 = 0
//   let p2 = 0
//   let res = []
//   nums1 = nums1.sort((a, b) => a - b)
//   nums2 = nums2.sort((a, b) => a - b)
//   while (p1 < nums1.length && p2 < nums2.length) {
//     if (nums1[p1] == nums2[p2]) {
//       res.push(nums1[p1])
//       p1++
//       p2++
//     } else if (nums1[p1] < nums2[p2]) {
//       p1++
//     } else {
//       p2++
//     }
//   }
//   return res
//   // 暴力法
// const res = []
// if (nums1.length < nums2.length) [nums1, nums2] = [nums2, nums1]
// for (let i = 0; i < nums1.length; i++) {
//   const key = nums2.indexOf(nums1[i])
//   if (key !== -1) res.push(nums2.splice(key, 1))
// }
// return res
}
```
## 传入`[1, 2], [11, 1, 2, 3, 2]`的运行结果
```sh
[ 1, 2 ]
```
## 执行结果
```sh
执行用时 :56 ms, 在所有 javascript 提交中击败了99.55% 的用户
内存消耗 :34.7 MB, 在所有 javascript 提交中击败了53.72%的用户
```

### GitHub仓库

[344. 反转字符串](https://github.com/moshuying/AlgorithmAndBlog)

### 查看更多

[查看更多题解](http://sfau.lt/bPbzVVJ)