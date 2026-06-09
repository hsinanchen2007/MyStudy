```
var merge = function(nums1, m, nums2, n) {
    for(let i=m;i<m+n;++i){
         let j=i;
         for(;j>=1 && nums1[j-1]>nums2[i-m];--j) nums1[j] = nums1[j-1];
         nums1[j] = nums2[i-m];
    }
};
```
