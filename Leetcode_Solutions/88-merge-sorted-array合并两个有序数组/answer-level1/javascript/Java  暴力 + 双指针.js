```
/**
 * @param {number[]} nums1
 * @param {number} m
 * @param {number[]} nums2
 * @param {number} n
 * @return {void} Do not return anything, modify nums1 in-place instead.
 * 1. 数组合并之后在排序，需要注意的是题目说的 直接修改 nums1 数组
 * 2. 双指针 从后往前走，依次给 nums1 赋值，当nums2 的游标走到底说明排序结束 因为 nums2 的长度是小于 nums1 的
 */
var merge = function(nums1, m, nums2, n) {
    // 方法 1
    /* nums1.splice(m, n, ...nums2);
    nums1.sort((a ,b) => a - b); */
    // 方法 2
    let currentIndex = nums1.length - 1;
    for (let i = m - 1, j = n - 1;;) {
        if (i < 0 && j < 0)
            break;
        if (nums1[i] < nums2[j] || i < 0) {
            nums1[currentIndex] = nums2[j];
            j--;
            currentIndex--;
        } else {
            nums1[currentIndex] = nums1[i];
            i--;
            currentIndex--;
        }
    }
};
```