## 第一版，双指针从后置位开始向前遍历（先把nums1多余部分给裁了）
> 72ms,34M。
```javascript []
/**
 * @param {number[]} nums1
 * @param {number} m
 * @param {number[]} nums2
 * @param {number} n
 * @return {void} Do not return anything, modify nums1 in-place instead.
 */
var merge = function(nums1, m, nums2, n) {
  nums1.splice(m);
  m--;
  n--;
  while (m >= 0 && n >= 0) {
    if (nums1[m] > nums2[n]) m--;
    else if (nums1[m] >= nums2[n - 1]) nums1.splice(m + 1, 0, ...nums2.splice(n--));
    else n--;
  }
  nums1.splice(m + 1, 0, ...nums2);
};
```
## 思路
![未命名文件 (1).jpg](https://pic.leetcode-cn.com/e6e16e77900b63b8943acbb700cb9d209be3602fd7103576d1733fcf8c7375ee-%E6%9C%AA%E5%91%BD%E5%90%8D%E6%96%87%E4%BB%B6%20\(1\).jpg)
