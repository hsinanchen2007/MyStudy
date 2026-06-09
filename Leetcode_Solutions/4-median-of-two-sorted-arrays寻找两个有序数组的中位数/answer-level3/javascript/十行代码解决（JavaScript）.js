var findMedianSortedArrays = function(nums1, nums2) {
    nums1 = nums1.concat(nums2).sort(function (a, b) {
    	return a - b;
    });
    var n = nums1.length;
    if (n % 2 == 1) {
    	return nums1[parseInt(n / 2)];
    }
    return (nums1[n / 2] + nums1[n / 2 - 1]) / 2;
};