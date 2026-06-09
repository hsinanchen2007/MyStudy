### 解题思路

需要注意的是
 1. nums1 是 nums2 的子集
 2. x 在 nums2 中对应位置的右边的第一个比 x 大的元素

```
如: nums1 = [4,1,2], nums2 = [1,3,4,2]

nums1 中的 4, 在nums2中的 4 在 第2位, 它的下一位为2, 不存在比它大, 所以为-1
nums1 中的 1, 在nums2中的 1 在 第0位, 它的下一位为3, 比它大 , 所以为3
nums1 中的 2, 在nums2中的 2 已经是最后一个元素了, 不存在下一个, 所以为-1
```


### 代码

```javascript
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var nextGreaterElement = function(nums1, nums2) {
    let arr = []
    nums1.forEach((item, index) => {
      let i = nums2.indexOf(item)
      while (i < nums2.length) {
        if (item < nums2[i]) {
          arr.push(nums2[i])
          return;
        }
        i++ 
      }
      arr.push(-1)
    })
    return arr
};
```