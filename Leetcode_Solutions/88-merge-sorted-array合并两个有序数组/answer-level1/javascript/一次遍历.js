```
var merge = function(nums1, m, nums2, n) {
    let p1 = m -1, p2 = n -1, p = m+n-1
    while(p >= 0) {
        if(p1 >= 0 && p2 >= 0){
            nums1[p--] = (nums2[p2] > nums1[p1]) ? nums2[p2--] : nums1[p1--]
        }else if(p1 >= 0){
            nums1[p--] = nums1[p1--]
        }else if(p2>=0) {
             nums1[p--] = nums2[p2--]
        }else {
            return nums1
        }  
    }
    return nums1
};
```
