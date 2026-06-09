```js
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersect = function(nums1, nums2) {
    let result = [];
    if (nums1.length < nums2.length) [nums1, nums2] = [nums2, nums1];
    for (let i = nums1.length; i--;) {
        let index = nums2.indexOf(nums1[i]);
        if (index !== -1) result.push(nums2.splice(index, 1));
    }
    return result;
};
```