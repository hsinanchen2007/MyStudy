var merge = function(nums1, m, nums2, n) {
    while(n > 0){
        if(nums1[m-1] > nums2[n-1] && m > 0){//当nums1数组还有数时，比较两个数组的最后数字大小；
            nums1[m+n-1] = nums1[m-1];
            m--;
        }else{
            nums1[m+n-1] = nums2[n-1];
            n--;
        }
    }
    return nums1;
};