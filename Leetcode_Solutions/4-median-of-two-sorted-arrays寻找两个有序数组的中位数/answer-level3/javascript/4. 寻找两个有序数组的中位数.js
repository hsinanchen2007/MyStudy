/*
 * @lc app=leetcode.cn id=4 lang=javascript
 *
 * [4] 寻找两个有序数组的中位数
 */
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var findMedianSortedArrays = function (nums1, nums2) {
  let newArr = [];

  while (nums1.length && nums2.length) {
    if (nums1[0] < nums2[0]) {
      newArr.push(nums1.shift())
    } else {
      newArr.push(nums2.shift())
    }

    if (!nums1.length) {
      newArr.push(...nums2)
      break
    }

    if (!nums2.length) {
      newArr.push(...nums1)
      break
    }
  }

  if (newArr.length === 0) {
    newArr = [...nums1, ...nums2];
  }

  let len = newArr.length;

  if (len % 2) {
    return newArr[(len - 1) / 2];
  } else {
    return (newArr[len / 2 - 1] + newArr[len / 2]) / 2;
  }
};



![image.png](https://pic.leetcode-cn.com/f06d24122383b0483367bd32bb68974091424fa2289cb5880fd5c27964d76cd1-image.png)
