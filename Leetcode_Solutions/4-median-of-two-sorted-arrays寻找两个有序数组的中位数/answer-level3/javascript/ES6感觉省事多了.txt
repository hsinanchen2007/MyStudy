```
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var findMedianSortedArrays = function(nums1, nums2) {
    let res = 0;
    let nums = [...nums1,...nums2];
    nums = nums.sort((a,b)=>a-b);
    if(nums.length%2 === 0){
        res = (nums[nums.length/2-1]+nums[nums.length/2])/2
    }else{
        res = nums[Math.floor(nums.length/2)];
    }
    return res;
};
```
