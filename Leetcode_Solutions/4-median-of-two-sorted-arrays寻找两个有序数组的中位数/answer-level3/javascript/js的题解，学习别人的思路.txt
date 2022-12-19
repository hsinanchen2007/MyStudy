### 解题思路
思路来自大佬[思路](https://leetcode-cn.com/problems/median-of-two-sorted-arrays/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-w-2/)

- 最重要的地方在于，条件判断的顺序不能颠倒，不然会造成下标越界，判断不到临界值的问题

### 代码

```javascript
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var findMedianSortedArrays = function(nums1, nums2) {
    const len1 = nums1.length
    const len2 = nums2.length
    const left = (len1 + len2 + 1) >> 1
    const right = (len1 + len2 + 2) >> 1
    return (getKth(nums1, 0, len1 - 1, nums2, 0, len2 - 1, left) + getKth(nums1, 0, len1 - 1, nums2, 0, len2 - 1, right)) * 0.5
    function getKth (arr1, s1, e1, arr2, s2, e2, k) {
        const l1 = e1 - s1 + 1
        const l2 = e2 - s2 + 1
        const mid = k >> 1
        const i = s1 + Math.min(l1, mid) - 1
        const j = s2 + Math.min(l2, mid) - 1
        if (l1 > l2) return getKth(arr2, s2, e2, arr1, s1, e1, k)
        else if (l1 === 0) return arr2[s2 + k - 1]
        else if (k === 1) return Math.min(arr1[s1], arr2[s2])
        else if (arr1[i] > arr2[j]) return getKth(arr1, s1, e1, arr2, j + 1, e2, k - (j - s2 + 1))
        else return getKth(arr1, i + 1, e1, arr2, s2, e2, k - ( i - s1 + 1 ))
    }
};
```