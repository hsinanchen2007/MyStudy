[TOC]
# 前端与算法 leetcode 189. 旋转数组
---
# 题目描述
[189. 旋转数组](https://leetcode-cn.com/problems/rotate-array/)
# 概要
把他当做一到简单的题来做,不要想太多了就好也可以不整那些花里胡哨的,直接旋转数组n次,我一开始也想到了这个办法,但是觉得太简单而且效率低下,想了很久也没想到合适的办法
# 提示
使用额外的数组
# 解析
用一个额外的数组将每个元素放到对应的位置就好 下标为i的位置对应(i+k)%数组长度 ,然后把新的数组拷贝(深拷贝)到原数组即可

### 算法
```js
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var rotate = function (nums, k) {
  const re = []
  for (let i = 0; i < nums.length; i++) {
    re[(i + k) % nums.length] = nums[i]
  }
  for (let j = 0; j < nums.length; j++) {
    nums[j] = re[j]
  }
}
```
传入`[1,2,3,4,5,6,7] 3`的运行结果
```sh
[5,6,7,1,2,3,4]
```
执行结果
```sh
执行用时 :68 ms, 在所有 javascript 提交中击败了97.94% 的用户
内存消耗 :36.1 MB, 在所有 javascript 提交中击败了9.91%的用户
```
## GitHub仓库

[48. 旋转图像](https://github.com/moshuying/AlgorithmAndBlog/)

