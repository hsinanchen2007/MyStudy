### 解题思路
srot方法在底层用了InsertionSort 和 QuickSort，数量小于10的数组使用 InsertionSort，比10大的数组则使用 QuickSort。
把两个数组合并成一个，排序

### 代码

```javascript
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var findMedianSortedArrays = function(nums1, nums2) {
    let arr =  nums1.concat(nums2)
    arr.sort((a,b)=>a-b)
    const ARR_LENGTH = arr.length
    const  MIDDLE = parseInt(ARR_LENGTH/2)
    return ARR_LENGTH%2===1 ? arr[MIDDLE] : (arr[MIDDLE]+arr[MIDDLE-1])/2
};
```