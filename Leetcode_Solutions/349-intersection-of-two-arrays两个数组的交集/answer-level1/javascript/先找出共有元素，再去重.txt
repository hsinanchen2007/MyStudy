```
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersection = function(nums1, nums2) {
    let num1Len = nums1.length;
    let num2Len = nums2.length;
    let ret = [];
//最小长度放外面，减少循坏次数
    if (num1Len > num2Len) {
        nums2.forEach(item => {
            if (nums1.includes(item)) {
                ret.push(item)
            }
        })
    } else {
        nums1.forEach(item => {
            if (nums2.includes(item)) {
                ret.push(item)
            }
        })
    }
//通过Set去重
    return [...new Set(ret)]
}
```
