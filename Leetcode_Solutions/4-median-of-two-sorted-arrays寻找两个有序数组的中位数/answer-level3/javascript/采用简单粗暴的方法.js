### 解题思路
先实现这种算法，时间复杂度是O(n+m)，没有达到要求；
先合并数组，采用的归并排序合并有序数组，这题目有个不严谨的，这两个数组必须是同时从小到大有序

### 代码

```javascript
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var findMedianSortedArrays = function (nums1, nums2) {
    let len1 = nums1.length;
    let len2 = nums2.length;
    // 这里这种方式还要说明，排序是从小到大，如果大到小,倒过来
    let isMin = nums1[0] <= nums1[len1 - 1];
    let mArr = merge(nums1, nums2);
    // console.log('marr:', mArr);
    let mid = Math.floor(mArr.length / 2);
    // console.log(mid);
    if (mArr.length % 2 === 0) {
        //偶数
        return (mArr[mid - 1] + mArr[mid]) / 2;
    } else {
        //奇数
        return mArr[mid];
    }

};
function merge(arr1, arr2) {
    let arr = [];
    while (arr1.length > 0 && arr2.length > 0) {
        if (arr1[0] > arr2[0]) {
            arr.push(arr2.shift())
        } else {
            arr.push(arr1.shift())
        }
    }
    while (arr1.length) {
        arr.push(arr1.shift());
    }
    while (arr2.length) {
        arr.push(arr2.shift());
    }
    return arr;
}
```