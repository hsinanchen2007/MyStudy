# 23 - 合并两个有序数组

## 题目

给定两个**有序**整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。

说明:

- 初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
- 你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。

示例:

> 输入:
> nums1 = [1,2,3,0,0,0], m = 3
> nums2 = [2,5,6],       n = 3
>
> 输出: [1,2,2,3,5,6]
>

## 解答

一开始想法，是从小到大放到nums1后面，然后逆序一下。但如果遇到了nums1的最大数，还是得重新挪动一下整个数组。显然就太麻烦了。

官方给出的解法是，从后往前，把大的数字放在数组后面。这样就能避免和nums1的最大数撞车了。

```js
/**
 * @param {number[]} nums1
 * @param {number} m
 * @param {number[]} nums2
 * @param {number} n
 * @return {void} Do not return anything, modify nums1 in-place instead.
 */
var merge = function(nums1, m, nums2, n) {
  const len1 = nums1.length;
  m--;
  n--;
  for (let i = len1 - 1; n >= 0; i--) {
    if (nums1[m] > nums2[n]) {
      nums1[i] = nums1[m];
      m--;
    } else {
      nums1[i] = nums2[n];
      n--;
    }
  }
};
```

> Runtime: 56 ms, faster than 76.94% of JavaScript online submissions forMerge Sorted Array.
>
> Memory Usage: 34.1 MB, less than 33.52% of JavaScript online submissions for Merge Sorted Array.

循环跳出的条件，只需要是n为0即可。因为当`n`跑完的时候，`nums1`剩下的都是比`num2`小的，也就无需再判断了。