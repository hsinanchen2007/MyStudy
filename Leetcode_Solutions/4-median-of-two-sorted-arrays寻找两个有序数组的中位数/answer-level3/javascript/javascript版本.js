```
var findMedianSortedArrays = function(nums1, nums2) {
    let reIndex = nums2.length - 1; //记录当前nums2的索引
    for (let i = nums1.length - 1; i >= 0; i--) {
        while (nums1[i] <= nums2[reIndex] && reIndex > -1) {
            nums1.splice(i + 1, 0, ...(nums2.splice(reIndex, 1)));
            reIndex--;
        }
    }
    const arr = [...nums2, ...nums1];
    const { length } = arr;
    return length % 2 ? arr[Math.floor(length / 2)] : (arr[length / 2] + arr[length / 2 - 1]) / 2;
};
```
满足时间复杂度要求：
重点是满足时间复杂度并将有序数组进行排序。
