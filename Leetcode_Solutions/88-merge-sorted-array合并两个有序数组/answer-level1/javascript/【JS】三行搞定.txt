```
var merge = function(nums1, m, nums2, n) {
    nums1.splice(m,nums1.length - m)
    nums2.splice(n,nums2.length - n)    
    Object.assign(nums1,[...nums1,...nums2].sort((a,b) => a - b))
};
```
