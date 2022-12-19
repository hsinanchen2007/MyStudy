var findMedianSortedArrays = function(nums1, nums2) {
  let len = nums1.length + nums2.length;
  let temp = [];
  temp = [...nums1, ...nums2].sort((a, b) => a - b);
  if (len % 2 === 0) {
    return (temp[len / 2 - 1] + temp[len / 2]) / 2;
  } else {
    return (temp[parseInt(len / 2)]);
  }
};
