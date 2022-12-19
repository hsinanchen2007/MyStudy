### 解题思路
注意注释 ：@return {void} Do not return anything, modify nums1 in-place instead.就是说不要改变原数组，不要return

### 代码

```javascript
/**
 * @param {number[]} nums1
 * @param {number} m
 * @param {number[]} nums2
 * @param {number} n
 * @return {void} Do not return anything, modify nums1 in-place instead.
 */

var merge = function(nums1, m, nums2, n) {
    // nums1.splice(m,nums1.length - m)
    // nums2.splice(n,nums2.length - n)    
    // Object.assign(nums1,[...nums1,...nums2].sort((a,b) => a - b))
    
    for (var i = 0;i<nums2.length;i++) nums1[m+i] = nums2[i];
    nums1.sort(function (a,b) {
        return a-b
    })
    
};
```