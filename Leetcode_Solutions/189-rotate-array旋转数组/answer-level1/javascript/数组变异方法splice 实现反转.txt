![image.png](https://pic.leetcode-cn.com/677a30a60eaf9e9d7d1ecfac9362b34d542ac3bdbb826db41e44776fcb716d65-image.png)

整理了一会思路 发现就是 把后k个元素 移动到前面去

在不使用新空间的情况下 想到了数组的变异方法 splice的 删除和插入功能

于是就有了下面的解法

```
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var rotate = function(nums, k) {
    nums.splice(0,0,...nums.splice(nums.length-k))
};
```
