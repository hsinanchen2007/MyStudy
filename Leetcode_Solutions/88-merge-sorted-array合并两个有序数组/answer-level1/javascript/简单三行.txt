```
var merge = function(nums1, m, nums2, n) {
    const tempArr = nums2.slice(0, n)
    nums1.splice(m, nums1.length - m, ...tempArr)
    nums1.sort((a, b) => a - b)
};
```
