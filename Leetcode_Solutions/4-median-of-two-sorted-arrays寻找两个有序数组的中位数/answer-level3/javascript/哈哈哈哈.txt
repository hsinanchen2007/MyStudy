### 解题思路
哈哈哈哈

### 代码

```javascript
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var findMedianSortedArrays = function(nums1, nums2) {
    let nums = nums1.concat(nums2).sort((a, b) => { return a - b; });
    if(nums.length%2 == 0){
        // 偶数
        return (nums[nums.length/2-1] + nums[nums.length/2]) / 2;
    }else{
        // 奇数
        return nums[nums.length/2 - 0.5];
    }
};
```