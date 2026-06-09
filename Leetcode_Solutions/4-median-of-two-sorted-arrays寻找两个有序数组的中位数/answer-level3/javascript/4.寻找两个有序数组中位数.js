var findMedianSortedArrays = function (nums1, nums2) {
  const num = [...nums1, ...nums2].sort((a, b) => a - b)
  if (num.length % 2 == 0) return (num[num.length / 2 - 1] + num[num.length / 2]) / 2
  else return num[(num.length - 1) /2]
};