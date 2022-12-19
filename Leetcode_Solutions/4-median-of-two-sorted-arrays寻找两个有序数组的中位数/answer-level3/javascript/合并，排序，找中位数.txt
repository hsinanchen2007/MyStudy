### 解题思路
合并数组，并找中位数即可。注意sort函数的使用

### 代码

```javascript
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */

var findMedianSortedArrays = function(nums1, nums2) {
    let onelist = nums1.concat(nums2)
    const comparaNumber = (a, b)=>a-b
    listTwo = onelist.sort(comparaNumber)
    index = onelist.length
    if (onelist.length % 2 != 0) return onelist[Math.floor(onelist.length / 2)]
    else return (onelist[onelist.length / 2] + onelist[onelist.length / 2 - 1]) / 2
};
```